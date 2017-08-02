
#ifndef CPP_CALLBACK_SCRIPT_MODULE_H
#define CPP_CALLBACK_SCRIPT_MODULE_H

#include "Environment.h"

class Module : public EnvironmentClient
{
    public:
        Module() : EnvironmentClient() { }

        bool respondsToKey(const String &key) override
        {
            return (key == "module");
        }
        Strings call(const String &key, const Strings &values) override
        {
            printf("Module.call\n");
            return values;
        }
};

#endif // CPP_CALLBACK_SCRIPT_MODULE_H

