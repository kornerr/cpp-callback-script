
#ifndef CPP_CALLBACK_SCRIPT_MODULE_ONE_H
#define CPP_CALLBACK_SCRIPT_MODULE_ONE_H

#include "Environment.h"

class ModuleOneProvider : public EnvironmentProvider
{
    public:
        ModuleOneProvider(Environment *env) :
            EnvironmentProvider(),
            environment(env)
        {
            // Setup stub values.
            this->values = {"module-one.First", "module-one.Second"};
        }
        virtual ~ModuleOneProvider() { }

        virtual bool hasGetter(const String &key)
        {
            return (key == "one");
        }
        virtual Strings get(const String &key)
        {
            return this->values;
        }

        virtual bool hasSetter(const String &key)
        {
            return (key == "one");
        }
        virtual void set(const String &key, const Strings &values)
        {
            this->values = values;
        }

    private:
        Strings values;
        Environment *environment;
};

#endif // CPP_CALLBACK_SCRIPT_MODULE_ONE_H

