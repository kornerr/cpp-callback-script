
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_PROVIDER_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_PROVIDER_H

#include "Common.h"

#include <cstdio>

class EnvironmentProvider
{
    public:
        EnvironmentProvider() { }
        virtual ~EnvironmentProvider() { }

        virtual bool hasGetter(const String &key)
        {
            return false;
        }
        virtual Strings get(const String &key)
        {
            Strings stub;
            return stub;
        }

        virtual bool hasSetter(const String &key)
        {
            return false;
        }
        virtual void set(const String &key, const Strings &values)
        {
            // Do nothing.
        }
};

#endif // CPP_CALLBACK_SCRIPT_ENVIRONMENT_PROVIDER_H

