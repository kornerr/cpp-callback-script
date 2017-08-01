
#include "Environment.h"

#include "cpp/module-one.h"
#include "cpp/module-two.h"

Environment *env = 0;

void runCPPModules(Environment *env)
{
    // Register the first custom provider.
    ModuleOne *one = new ModuleOne(env);
    env->addModule(mp);

    // Work with module-one through Environment interface.
    
    // Try to set invalid (unregistered) key.
    env->set("invalidKey", {"value1", "value2"});
    // See current values for 'one' key.
    printf("main. one values before: '%s'\n", stringsToString(env->get("one")).c_str());
    // Set new values for 'cpp' key.
    env->set("one", {"value1", "value2"});
    // See new values for 'cpp' key.
    printf("main. one values after: '%s'\n", stringsToString(env->get("one")).c_str());

    // Remove the first custom provider.
    delete one;
}

int main()
{
    Environment env;

    runCPPModule(&env);


    return 0;
}

