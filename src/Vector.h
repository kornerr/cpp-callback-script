
#ifndef CPP_CALLBACK_SCRIPT_VECTOR_H
#define CPP_CALLBACK_SCRIPT_VECTOR_H

#include "Common.h"

// Vector is just a placeholder to keep Strings inside,
// because raw Strings usage crashes Sol2/Lua interpreter.
struct Vector
{
    Vector() { }

    void setStrings(const Strings &strings)
    {
        this->strings = strings;
    }

    Strings strings;
};

#endif // CPP_CALLBACK_SCRIPT_VECTOR_H

