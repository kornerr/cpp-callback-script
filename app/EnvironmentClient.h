
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H

#include "Common.h"

#include <cstdio>

class EnvironmentClient
{
    public:
        EnvironmentClient() { }
        virtual ~EnvironmentClient() { }

        virtual bool respondsToKey(const String &key)
        {
            printf("EnvironmentClient.respondsToKey(%s). override me!\n", key.c_str());
            return false;
        }
        virtual Strings call(const String &key, const Strings &values)
        {
            printf(
                "EnvironmentClient.call(%s, %s). override me!\n",
                key.c_str(),
                stringsToString(values).c_str());
            Strings stub;
            return stub;
        }
};

#endif // CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H

