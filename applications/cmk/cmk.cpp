#include <clipp.h>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <sstream>

using namespace clipp;
using std::cout;
using std::cerr;
using std::string;

namespace fs = std::filesystem;

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
    fs::path project_dir;
    fs::path build_dir;
    std::string install_dir;
};

static bool read_env(const std::string& name, std::string& dst)
{
    bool ret             = true;
    char* install_path_c = getenv(name.c_str());
    ret                  = (install_path_c != nullptr);
    if(ret)
    {
        dst = std::string(install_path_c);
    }
    else
    {
        std::cerr << "Environment variable \"" << name << "\" not found\n";
    }
    return ret;
}

static bool generate(RunConfig& cfg)
{
    bool ret = true;

    fs::create_directory(cfg.build_dir);
    ret = fs::exists(cfg.build_dir);
    if(ret)
    {
        std::stringstream ss;
        ss << "cmake -DCMAKE_INSTALL_PREFIX=" << cfg.install_dir << " -S " << cfg.project_dir.string() << " -B "
           << cfg.build_dir.string();
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
    auto cli_rebuild = (command("rebuild").set(cfg.mode, RunConfig::Mode::REBUILD));

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

        bool ok = read_env("CMK_INSTALL_DIR", cfg.install_dir);

        if(ok)
        {
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
            ret = -1;
        }
    }
    return ret;
}