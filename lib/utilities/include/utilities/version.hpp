#pragma once

#include <string>

namespace utils
{

class Version
{
public:
    unsigned major   = 0;
    unsigned minor   = 0;
    unsigned patch   = 0;
    unsigned extra   = 0;
    std::string hash = "";
};

} // namespace utils
