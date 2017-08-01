
#ifndef CPP_CALLBACK_SCRIPT_FILE_H
#define CPP_CALLBACK_SCRIPT_FILE_H

#include "Common.h"

#include <fstream>

String readFile(const char *fileName)
{
    std::ifstream in(fileName);
    if (!in.is_open())
    {
        printf("Cannot open file '%s'\n", fileName);
        return "";
    }
    String contents;
    String line;
    while (getline(in, line))
    {
        contents += line + "\n";
    }
    return contents;
}

#endif // CPP_CALLBACK_SCRIPT_FILE_H

