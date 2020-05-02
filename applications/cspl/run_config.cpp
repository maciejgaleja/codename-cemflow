/* @file          run_config.cpp                                              */
/* @date          2020-05-02                                                  */

#include "run_config.hpp"
#include "log.hpp"

#include <iterator>
#include <sstream>

bool RunConfig::validate()
{
    bool ret = true;

    if(interactive && (file.size() == 0))
    {
        ret = false;
    }

    return ret;
}

bool RunConfig::add_filter(const std::vector<std::string>& filters)
{
    bool ret = true;
    for(const std::string& s : filters)
    {
        FilterSpecification spec;
        std::istringstream iss(s);
        std::vector<std::string> tokens(
            (std::istream_iterator<std::string>(iss)),
            std::istream_iterator<std::string>());
        for(std::string& t : tokens)
        {
            if(t == "\\n")
            {
                t = "\n";
            }
        }
        if(tokens.size() >= 2)
        {
            spec.begin = tokens[0];
            spec.end   = tokens[1];
            if(tokens.size() >= 3)
            {
                if(tokens[2] == "!")
                {
                    spec.inverted = true;
                }
            }
        }
        else
        {
            ret = false;
            break;
        }
        filter.push_back(spec);
    }
    return ret;
}
