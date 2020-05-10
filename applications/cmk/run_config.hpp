/* @file          run_config.hpp                                              */
/* @date          2020-05-02                                                  */

#ifndef APPLICATIONS__CMK__RUN_CONFIG_HPP
#define APPLICATIONS__CMK__RUN_CONFIG_HPP

#if GCC_VERSION < 90000
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

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
