
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H

#include "Common.h"

#include <cstdio>
#include <functional>

// Do not inherit this class. Simply provide callbacks.
class EnvironmentClient
{
    public:
        // Callback for 'respondsToKey' method.
        typedef std::function<bool (const String &)> CallbackRespondsToKey;
        CallbackRespondsToKey callbackRespondsToKey;

        // Callback for 'call' method.
        typedef std::function<Strings (const String &, const Strings &)> CallbackCall;
        CallbackCall callbackCall;

        EnvironmentClient() :
            callbackRespondsToKey(nullptr),
            callbackCall(nullptr) { }
        ~EnvironmentClient() { }

        bool respondsToKey(const String &key)
        {
            if (this->callbackRespondsToKey)
            {
                return this->callbackRespondsToKey(key);
            }
            printf("EnvironmentClient.respondsToKey(%s). provide callback!\n", key.c_str());
            return false;
        }
        Strings call(const String &key, const Strings &values)
        {
            if (this->callbackCall)
            {
                return this->callbackCall(key, values);
            }
            printf(
                "EnvironmentClient.call(%s, %s). provide callback!\n",
                key.c_str(),
                stringsToString(values).c_str());
            Strings stub;
            return stub;
        }
};

#endif // CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H

