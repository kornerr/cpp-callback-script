
#ifndef CPP_CALLBACK_SCRIPT_ENVIRONMENT_H
#define CPP_CALLBACK_SCRIPT_ENVIRONMENT_H

#include "EnvironmentClient.h"

class Environment
{
    public:
        Environment() { }

        void addClient(EnvironmentClient *client)
        {
            this->clients.push_back(client);
        }

        Strings call(const String &key, const Strings &values)
        {
            for (auto client : this->clients)
            {
                if (client->respondsToKey(key))
                {
                    return client->call(key, values);
                }
            }
            printf("No one found to respond to key '%s'", key.c_str());
            Strings stub;
            return stub;
        }
        void print(const Strings &values)
        {
            printf("%s\n", stringsToString(values).c_str());
        }

    private:
        std::vector<EnvironmentClient *> clients;
};

#endif // CPP_CALLBACK_SCRIPT_ENVIRONMENT_H

