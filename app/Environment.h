
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_H

#include "EnvironmentProvider.h"

#include <map>

class Environment
{
    public:
        Environment() { }
        ~Environment() { }

        void addProvider(EnvironmentProvider *provider)
        {
            this->providers.push_back(provider);
        }

        Strings get(const String &key)
        {
            for (auto provider : this->providers)
            {
                if (provider->hasGetter(key))
                {
                    return provider->get(key);
                }
            }
            Strings stub;
            return stub;
        }
        void set(const String &key, const Strings &values)
        {
            for (auto provider : this->providers)
            {
                if (provider->hasSetter(key))
                {
                    provider->set(key, values);
                }
            }
        }

    private:
        std::vector<EnvironmentProvider *> providers;
};

#endif // CPP_CALLBACK_SCRIPT_ENVIRONMENT_H

