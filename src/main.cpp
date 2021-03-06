
#include "Environment.h"

Environment *env = 0;

void runCPP()
{
    // Module.
    EnvironmentClient *module = new EnvironmentClient;
    env->addClient(module);
    module->callbackRespondsToKey =
        [](const String &key)
        {
            return (key == "module");
        };
    module->callbackCall =
        [](const String &key, const Strings &values)
        {
            printf("Module.call(%s)\n", key.c_str());
            return values;
        };

    // Work with 'module' through Environment interface.
    {
        Strings values = env->call("module", {"1", "2"});
        printf("module. values: '%s'\n", stringsToString(values).c_str());
    }

    // Proxy.
    EnvironmentClient *proxy = new EnvironmentClient;
    env->addClient(proxy);
    proxy->callbackRespondsToKey =
        [](const String &key)
        {
            return (key == "proxy");
        };
    proxy->callbackCall =
        [&](const String &key, const Strings &values)
        {
            printf("Proxy.call(%s)\n", key.c_str());
            // Redirect call to 'module'.
            return env->call("module", values);
        };
    // Work with 'module' through 'proxy'.
    {
        Strings values = env->call("proxy", {"10", "20"});
        printf("proxy. values: '%s'\n", stringsToString(values).c_str());
    }

    printf("Finished CPP\n");

    /*
    // Deallocate.
    delete module;
    delete proxy;
    */
}

// Sol2.
#include <sol.hpp>

void runSol(const char *fileName)
{
    sol::state lua;
    lua.open_libraries();
    // Register environment instance.
    lua["env"] = env;
    // Register environment class.
    lua.new_usertype<Environment>(
        "Environment",
        "addClient", &Environment::addClient,
        "call",
        [](Environment &env, const String &key, sol::nested<Strings> values)
        {
            return env.call(key, values);
        }
    );

//#define REGISTER_PLAIN_CALLBACK

    // Register environment client class.
    lua.new_usertype<EnvironmentClient>(
        "EnvironmentClient",
        "callbackCall",
#ifdef REGISTER_PLAIN_CALLBACK
        &EnvironmentClient::callbackCall,
#else // REGISTER_PLAIN_CALLBACK
        sol::property(
            [](EnvironmentClient &ec, sol::function luaCallback)
            {
                ec.callbackCall =
                    [=](const String &key, const Strings &values) -> Strings
                    {
                        sol::nested<Strings> result = luaCallback(key, sol::as_table(values));
                        return std::move(result.source);
                    };
            }),
#endif // REGISTER_PLAIN_CALLBACK
        "callbackRespondsToKey", &EnvironmentClient::callbackRespondsToKey
    );

    // Load and execute script.
    lua.script_file(fileName);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("%s /path/to/script.lua\n", argv[0]);
        return 1;
    }
    const char *fileName = argv[1];

    env = new Environment;
    runCPP();
    runSol(fileName);

    return 0;
}

