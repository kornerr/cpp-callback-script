
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_H

#include "EnvironmentProvider.h"

#include <map>

class Environment
{
    public:
        Environment() { }
        ~Environment() { }

        void addProvider(const String &key, EnvironmentProvider *provider)
        {
            this->providers.insert(
                std::pair<String, EnvironmentProvider *>(key, provider));
        }

        Strings get(const String &key)
        {
            for (auto it : this->providers)
            {
                if (it.second->hasGetter(key))
                {
                    return it.second->get(key);
                }
            }
            Strings stub;
            return stub;
        }
        void set(const String &key, const Strings &values)
        {
            for (auto it : this->providers)
            {
                if (it.second->hasSetter(key))
                {
                    it.second->set(key, values);
                }
            }
        }

    private:
        typedef std::map<String, EnvironmentProvider *> Providers;
        Providers providers;
};

#endif // CPP_CALLBACK_SCRIPT_ENVIRONMENT_H

