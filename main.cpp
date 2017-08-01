
#include "Environment.h"

#include "cpp/module.h"
#include "cpp/proxy.h"

Environment *env = 0;

void runCPPClients(Environment *env)
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

    // Deallocate 'model' and 'proxy'.
    delete module;
    delete proxy;
}

int main()
{
    Environment env;

    runCPPClients(&env);


    return 0;
}

