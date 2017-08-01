
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_PROVIDER_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_PROVIDER_H

#include "Common.h"

#include <cstdio>

class EnvironmentProvider
{
    public:
        EnvironmentProvider()
        {
            printf("EnvironmentProvider.constructor\n");
        }
        virtual ~EnvironmentProvider()
        {
            printf("EnvironmentProvider.destructor\n");
        }

        virtual bool hasGetter(const String &key)
        {
            printf("EnvironmentProvider.hasGetter(%s)\n", key.c_str());
            return false;
        }
        virtual Strings get(const String &key)
        {
            printf("EnvironmentProvider.get(%s)\n", key.c_str());
        }

        virtual bool hasSetter(const String &key)
        {
            printf("EnvironmentProvider.hasSetter(%s)\n", key.c_str());
            return false;
        }
        virtual void set(const String &key, const Strings &values)
        {
            printf(
                "EnvironmentProvider.set(%s, %s)\n",
                key.c_str(),
                stringsToString(values).c_str());
        }
};

#endif // CPP_CALLBACK_SCRIPT_ENVIRONMENT_PROVIDER_H

