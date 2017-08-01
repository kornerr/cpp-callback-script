
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_LISTENER_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_LISTENER_H

#include "Common.h"

#include <cstdio>

class EnvironmentListener
{
    public:
        EnvironmentListener()
        {
            printf("EnvironmentListener.constructor\n");
        }
        virtual ~EnvironmentListener()
        {
            printf("EnvironmentListener.destructor\n");
        }

        virtual void report(const String &key, const Strings &values)
        {
            printf(
                "EnvironmentListener.report(%s, %s)\n",
                key.c_str(),
                stringsToString(values).c_str());
        }
};

#endif // CPP_CALLBACK_SCRIPT_ENVIRONMENT_LISTENER_H

