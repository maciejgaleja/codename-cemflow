/* @file          stdio_source.cpp                                            */

#include "stdio_source.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

bool StdioSource::next()
{
    bool ret = true;
    Char c;
    if(std::cin.get(c))
    {
        notify_all(c);
    }
    else
    {
        notify_all('\0');
        ret = false;
    }
    return ret;
}
