
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_H

#include "EnvironmentListener.h"
#include "EnvironmentProvider.h"

#include <map>

class Environment
{
    public:
        Environment() { }
        ~Environment() { }

        void addListener(const String &key, EnvironmentListener *listener)
        {
            this->listeners.insert(
                std::pair<String, EnvironmentListener *>(key, listener));
        }

        Strings get(const String &key)
        {
            Strings stub;
            // TODO
            return stub;
        }
        //void report(const String &key, const Strings &values);
        void set(const String &key, const Strings &values)
        {
            // TODO

        }
        void setProvider(const String &key, EnvironmentProvider *provider)
        {
            // TODO

        }

    private:
        std::map<String, EnvironmentListener *> listeners;
        std::map<String, EnvironmentProvider *> providers;

};

#endif // CPP_CALLBACK_SCRIPT_ENVIRONMENT_H

