
#ifndef CPP_CALLBACK_SCRIPT_COMMON_H
#define CPP_CALLBACK_SCRIPT_COMMON_H

#include <string>
#include <vector>

typedef std::string String;

typedef std::vector<String> Strings;

String stringsToString(const Strings &strings)
{
    String output;
    for (String item : strings)
    {
        output += item;
    }
    return output;
}

#endif // CPP_CALLBACK_SCRIPT_COMMON_H

