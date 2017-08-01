
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

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("%s /path/to/script.chai\n", argv[0]);
        return 1;
    }
    const char *fileName = argv[1];

    Environment env;

    runCPP(&env);
    runChai(&env, fileName);

    return 0;
}

