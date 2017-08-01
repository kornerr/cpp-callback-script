
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H

#include "Common.h"

class EnvironmentClient
{
    public:
        virtual ~EnvironmentClient() { }

        virtual bool respondsToKey(const String &key) = 0;
        virtual Strings call(const String &key, const Strings &values) = 0;
};

#endif // CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H

