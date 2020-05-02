/* @file          run_config.hpp                                              */
/* @date          2020-05-02                                                  */

#ifndef APPLICATIONS__CMK__RUN_CONFIG_HPP
#define APPLICATIONS__CMK__RUN_CONFIG_HPP

#include <filesystem>

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
    std::filesystem::path project_dir;
    std::filesystem::path build_dir;
    std::string install_dir;
};

#endif // APPLICATIONS__CMK__RUN_CONFIG_HPP
