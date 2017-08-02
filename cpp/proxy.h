
#ifndef CPP_CALLBACK_SCRIPT_PROXY_H
#define CPP_CALLBACK_SCRIPT_PROXY_H

#include "Environment.h"

class Proxy : public EnvironmentClient
{
    public:
        Proxy(Environment *env) : environment(env) { }

        bool respondsToKey(const String &key) override
        {
            return (key == "proxy");
        }
        Strings call(const String &key, const Strings &values) override
        {
            printf("Proxy.call\n");
            // Redirect call to 'module'.
            return environment->call("module", values);
        }

    private:
        Environment *environment;
};

#endif // CPP_CALLBACK_SCRIPT_PROXY_H

