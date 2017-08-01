
#ifndef CPP_CALLBACK_SCRIPT_MODULE_H
#define CPP_CALLBACK_SCRIPT_MODULE_H

#include "EnvironmentProvider.h"

class ModuleProvider : public EnvironmentProvider
{
    public:
        ModuleProvider() : EnvironmentProvider()
        {
            // Setup stub values.
            this->values = {"First", "Second"};
        }
        virtual ~ModuleProvider() { }

        virtual bool hasGetter(const String &key)
        {
            return (key == "cpp");
        }
        virtual Strings get(const String &key)
        {
            return this->values;
        }

        virtual bool hasSetter(const String &key)
        {
            return (key == "cpp");
        }
        virtual void set(const String &key, const Strings &values)
        {
            this->values = values;
        }

    private:
        Strings values;
};

#endif // CPP_CALLBACK_SCRIPT_MODULE_H

