
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H

#include "Common.h"

#include <cstdio>
#include <functional>


class EnvironmentClient
{
    public:
        typedef std::function<bool(const String &)> CallbackRespondsToKey;

        EnvironmentClient() : callbackRespondsToKey(nullptr) { }
        virtual ~EnvironmentClient() { }

        virtual bool respondsToKey(const String &key)
        {
            if (this->callbackRespondsToKey)
            {
                return this->callbackRespondsToKey(key);
            }
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

        void setCallbackRespondsToKey(CallbackRespondsToKey callback)
        {
            this->callbackRespondsToKey = callback;
        }

    private:
        CallbackRespondsToKey callbackRespondsToKey;
};

#endif // CPP_CALLBACK_SCRIPT_ENVIRONMENT_CLIENT_H

