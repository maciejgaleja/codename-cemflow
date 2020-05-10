/* @file          run_config.hpp                                              */

#ifndef APPLICATIONS__CSPL__RUN_CONFIG_HPP
#define APPLICATIONS__CSPL__RUN_CONFIG_HPP


#include <string>
#include <vector>

struct FilterSpecification
{
    std::string begin = "";
    std::string end   = "";
    bool inverted     = false;
};

class RunConfig
{
public:
    enum class OpMode
    {
        CHECK,
        CREATE,
        ADD
    };

    OpMode mode;
    std::string language = "en_US";
    std::string file     = "";
    bool interactive     = false;
    std::vector<std::string> words_to_add;

    std::vector<FilterSpecification> filter;

    bool validate();
    bool add_filter(const std::vector<std::string>& filters);
};


#endif // APPLICATIONS__CSPL__RUN_CONFIG_HPP
