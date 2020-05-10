/* @file          env.cpp                                                     */

#include "utilities/env.hpp"

using std::optional;
using std::string;

std::optional<std::string> Env::get(const std::string& name)
{
    optional<string> ret;
    char* c_str = getenv(name.c_str());
    if(c_str != nullptr)
    {
        ret = string(c_str);
    }
    return ret;
}
