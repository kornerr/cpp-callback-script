
#ifndef CPP_CALLBACK_SCRIPT_VECTOR_H
#define CPP_CALLBACK_SCRIPT_VECTOR_H

#include "Common.h"

// Vector is just a placeholder to keep Strings inside,
// because raw Strings usage crashes Sol2/Lua interpreter.
struct Vector
{
    Vector() { }

    void setValues(const Strings &values)
    {
        this->values = values;
    }

    Strings values;
};

#endif // CPP_CALLBACK_SCRIPT_VECTOR_H

