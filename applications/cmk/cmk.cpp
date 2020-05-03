/* @file          cmk.cpp                                                     */
/* @date          2020-05-02                                                  */

#include "errors.hpp"
#include "run_config.hpp"

#include <clipp.h>
#include <cstdlib>
#if GCC_VERSION < 90000
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

#include <iostream>
#include <sstream>
#include <utilities/env.hpp>

using namespace clipp;
using std::cerr;
using std::cout;
using std::string;


static Result<std::string> read_env(const std::string& name)
{
    auto value = Env::get(name);
    if(value)
    {
        return Result<std::string>::ok(*value);
    }
    else
    {
        return Result<std::string>::err<EnvError>("Could not get \"" + name +
                                                  "\"");
    }
}

static bool generate(RunConfig& cfg)
{
    bool ret = true;

    fs::create_directory(cfg.build_dir);
    ret = fs::exists(cfg.build_dir);
    if(ret)
    {
        std::stringstream ss;
        ss << "cmake -DCMAKE_INSTALL_PREFIX=" << cfg.install_dir << " -S "
           << cfg.project_dir.string() << " -B " << cfg.build_dir.string();
        cout << ss.str() << '\n';
        system(ss.str().c_str());
    }
    return true;
}

static bool build(RunConfig& cfg)
{
    bool ret = true;

    ret = fs::exists(cfg.build_dir);
    if(ret)
    {
        std::stringstream ss;
        ss << "cmake --build " << cfg.build_dir.string();
        cout << ss.str() << '\n';
        system(ss.str().c_str());
    }
    else
    {
        cerr << "Build directory does not exist. Run \n\n\tcmk gen\n\n";
    }

    return true;
}

static bool install(RunConfig& cfg)
{
    bool ret = true;

    ret = fs::exists(cfg.build_dir);
    if(ret)
    {
        std::stringstream ss;
        ss << "cmake --build " << cfg.build_dir.string() << " --target install";
        cout << ss.str() << '\n';
        system(ss.str().c_str());
    }

    return ret;
}

static bool clean(RunConfig& cfg)
{
    bool ret = true;

    ret = fs::exists(cfg.build_dir);
    if(ret)
    {
        auto cnt = fs::remove_all(cfg.build_dir);
        cout << "Removed " << cnt << " files and directories\n";
    }

    return ret;
}

int main(int argc, char* argv[])
{
    int ret = 0;
    RunConfig cfg;
    bool rec = false, utf16 = false;
    string infile = "", fmt = "csv";

    auto cli_generate =
        (command("gen").set(cfg.mode, RunConfig::Mode::GENERATE));
    auto cli_build = (command("build").set(cfg.mode, RunConfig::Mode::BUILD));
    auto cli_install =
        (command("install").set(cfg.mode, RunConfig::Mode::INSTALL));
    auto cli_clean = (command("clean").set(cfg.mode, RunConfig::Mode::CLEAN));
    auto cli_rebuild =
        (command("rebuild").set(cfg.mode, RunConfig::Mode::REBUILD));

    auto cli = cli_generate | cli_build | cli_install | cli_clean | cli_rebuild;

    if(!parse(argc, argv, cli))
    {
        cout << make_man_page(cli, argv[0]);
    }
    else
    {
        cfg.project_dir = fs::current_path();
        cfg.build_dir   = cfg.project_dir;
        cfg.build_dir.append("_build");

        auto cmk_install_dir = read_env("CMK_INSTALL_DIR");

        if(cmk_install_dir)
        {
            cfg.install_dir = cmk_install_dir.value();
            switch(cfg.mode)
            {
            case RunConfig::Mode::GENERATE:
                generate(cfg);
                break;
            case RunConfig::Mode::BUILD:
                build(cfg);
                break;
            case RunConfig::Mode::INSTALL:
                build(cfg);
                install(cfg);
                break;
            case RunConfig::Mode::CLEAN:
                clean(cfg);
                break;
            case RunConfig::Mode::REBUILD:
                clean(cfg);
                generate(cfg);
                build(cfg);
                break;
            default:
                cout << "NOT IMPLEMENTED\n";
                ret = -1;
                break;
            }
        }
        else
        {
            cerr << cmk_install_dir.error().to_string();
            ret = -1;
        }
    }
    return ret;
}
