
#include "Environment.h"

#include "cpp/module.h"

Environment *env = 0;

void runCPPModule(Environment *env)
{
    // Register custom provider.
    ModuleProvider *mp = new ModuleProvider;
    env->addProvider(mp);
    // Try to set invalid (unregistered) key.
    env->set("invalidKey", {"value1", "value2"});
    // See current values for 'cpp' key.
    printf("main. 01.cpp values: '%s'\n", stringsToString(env->get("cpp")).c_str());
    // Set new values for 'cpp' key.
    env->set("cpp", {"value1", "value2"});
    // See new values for 'cpp' key.
    printf("main. 02.cpp values: '%s'\n", stringsToString(env->get("cpp")).c_str());

    // Remove custom provider.
    delete mp;
}

int main()
{
    Environment env;

    runCPPModule(&env);


    return 0;
}

