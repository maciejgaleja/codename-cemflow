/* @file          run_config.hpp                                              */

#ifndef APPLICATIONS__CMK__RUN_CONFIG_HPP
#define APPLICATIONS__CMK__RUN_CONFIG_HPP

#include "filesystem.hpp"

class RunConfig
{
public:
    enum class Mode
    {
        GENERATE,
        BUILD,
        INSTALL,
        CLEAN,
        REBUILD
    };
    Mode mode = Mode::GENERATE;
    std::vector<std::string> cmake_extra_args;
    fs::path project_dir;
    fs::path build_dir;
    std::string install_dir;
};

#endif // APPLICATIONS__CMK__RUN_CONFIG_HPP
