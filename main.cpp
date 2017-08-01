
#include "Environment.h"

#include "cpp/module.h"
//#include "cpp/proxy.h"

Environment *env = 0;

void runCPPClients(Environment *env)
{
    Module *module = new Module;
    env->addClient(module);

    // Work with 'module' through Environment interface.
    
    Strings values = env->call("module", {"value1", "value2"});
    printf("runCPPClients. values: '%s'\n", stringsToString(values).c_str());


    // Deallocate the model.
    delete module;
}

int main()
{
    Environment env;

    runCPPClients(&env);


    return 0;
}

