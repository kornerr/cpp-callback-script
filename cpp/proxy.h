
#ifndef CPP_CALLBACK_SCRIPT_PROXY_H
#define CPP_CALLBACK_SCRIPT_PROXY_H

#include "Environment.h"

class Proxy : public EnvironmentClient
{
    public:
        Proxy(Environment *env) : environment(env) { }

        virtual bool respondsToKey(const String &key)
        {
            return (key == "proxy");
        }
        virtual Strings call(const String &key, const Strings &values)
        {
            printf("Proxy.call\n");
            // Redirect call to 'module'.
            return environment->call("module", values);
        }

    private:
        Environment *environment;
};

#endif // CPP_CALLBACK_SCRIPT_PROXY_H

