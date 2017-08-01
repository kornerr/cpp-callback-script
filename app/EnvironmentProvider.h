
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

        virtual Strings get(const String &key)
        {
            printf("EnvironmentProvider.get(%s)\n", key.c_str());
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

