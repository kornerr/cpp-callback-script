
#include "Environment.h"
#include "File.h"

// CPP.
#include "cpp/module.h"
#include "cpp/proxy.h"

// Chai.
#include <chaiscript/chaiscript.hpp>

Environment *env = 0;

void runChai(Environment *env, const char *fileName)
{
    // Create Chai engine.
    chaiscript::ChaiScript chai;
    // Register environment type.
    chai.add(chaiscript::fun(&Environment::addClient), "addClient");
    chai.add(chaiscript::fun(&Environment::call), "call");
    chai.add(chaiscript::user_type<Environment>(), "Environment");
    // Register environment instance.
    chai.add(chaiscript::var(env), "env");
    // Load script.
    String script = readFile(fileName);
    // Execute script.
    chai.eval(script);
}

void runCPP(Environment *env)
{
    Module *module = new Module;
    env->addClient(module);
    // Work with 'module' through Environment interface.
    {
        Strings values = env->call("module", {"1", "2"});
        printf("module. values: '%s'\n", stringsToString(values).c_str());
    }

    Proxy *proxy = new Proxy(env);
    env->addClient(proxy);
    // Work with 'module' through 'proxy'.
    {
        Strings values = env->call("proxy", {"10", "20"});
        printf("proxy. values: '%s'\n", stringsToString(values).c_str());
    }

    /*
    // Deallocate 'model' and 'proxy'.
    delete module;
    delete proxy;
    */
}

// Sol2.
#include <sol.hpp>

void runSol(Environment *env, const char *fileName)
{
    sol::state lua;

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
        },
        "print",
        [](Environment &env, sol::nested<Strings> values)
        {
            env.print(values);
        }
    );
    // Register environment client class.
    lua.new_usertype<EnvironmentClient>(
        "EnvironmentClient",
        "respondsToKey", &EnvironmentClient::respondsToKey,
        "call",
        [](EnvironmentClient &ec, const String &key, sol::nested<Strings> values)
        {
            return ec.call(key, values);
        }
    );
    // Load and execute script.
    lua.script_file(fileName);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("%s /path/to/script.chai /path/to/script.lua\n", argv[0]);
        return 1;
    }
    const char *fileNameChai = argv[1];
    const char *fileNameLua = argv[2];

    Environment env;

    runCPP(&env);
    //runChai(&env, fileNameChai);
    runSol(&env, fileNameLua);

    return 0;
}

