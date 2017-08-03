
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H

#include "Common.h"
#include "Vector.h"

#include <cstdio>
#include <functional>

class EnvironmentClient
{
    public:
        // Callback for 'respondsToKey' method.
        typedef std::function<bool (const String &)> CallbackRespondsToKey;
        CallbackRespondsToKey callbackRespondsToKey;

        // Callback for 'call' method.
        typedef std::function<Strings (const String &, const Strings &)> CallbackCall;
        CallbackCall callbackCall;

        // Callback for 'call' method using Vector.
        typedef std::function<Vector (const String &, const Vector &)> CallbackCallVector;
        CallbackCallVector callbackCallVector;

        EnvironmentClient() :
            callbackRespondsToKey(nullptr),
            callbackCall(nullptr),
            callbackCallVector(nullptr) { }
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
            // Strings version.
            if (this->callbackCall)
            {
                return this->callbackCall(key, values);
            }
            // Vector version.
            else if (this->callbackCallVector)
            {
                Vector in;
                in.values = values;
                Vector out = this->callbackCallVector(key, in);
                return out.values;
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

