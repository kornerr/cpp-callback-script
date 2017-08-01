
#ifndef CPP_CALLBACK_SCRIPT_MODULE_H
#define CPP_CALLBACK_SCRIPT_MODULE_H

#include "Environment.h"

class Module : public EnvironmentClient
{
    public:
        Module() { }

        virtual bool respondsToKey(const String &key)
        {
            return (key == "module");
        }
        virtual Strings call(const String &key, const Strings &values)
        {
            printf("Module.call\n");
            return values;
        }
};

#endif // CPP_CALLBACK_SCRIPT_MODULE_H

