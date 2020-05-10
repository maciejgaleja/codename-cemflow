/* @file          main.cpp                                                    */
/* @date          2020-05-02                                                  */

#ifndef CSPL_DICTIONARY_DIR
#error "CSPL_DICTIONARY_DIR not set. Define it with dictionary directory path"
#endif

#include <clipp.h>

#include <iostream>

#include "cspl.hpp"

#include <lotrame.hpp>

#include "filesystem.hpp"

using clipp::command;
using clipp::make_man_page;
using clipp::opt_values;
using clipp::option;
using clipp::parse;
using clipp::repeatable;
using clipp::usage_lines;
using clipp::value;
using clipp::values;

using std::cout;

int main(int argc, char** argv)
{
    logging.setSeverity(ltr::Severity::Fatal);

    int ret = -1;
    std::vector<std::string> filter_strings;

    RunConfig cfg;
    auto cli_check =
        (command("check")
             .doc("check spelling")
             .set(cfg.mode, RunConfig::OpMode::CHECK),
         (option("-i", "--interactive")
              .doc("fix errors interactively")
              .set(cfg.interactive),
          repeatable(
              option("-x", "--filter")
                  .doc("filter only words matching filter specification") &
              value("spec", filter_strings)),
          (option("-f", "--file") &
           value("file", cfg.file).doc("input file"))));

    auto cli_create = (command("create")
                           .doc("create dictionary")
                           .set(cfg.mode, RunConfig::OpMode::CREATE)) &
                      (option("-l", "--language").doc("select language") &
                       value("language").set(cfg.language));

    auto cli_add = (command("add")
                        .doc("add word(s) dictionary")
                        .set(cfg.mode, RunConfig::OpMode::ADD)) &
                   (option("-l", "--language").doc("select language") &
                    value("language").set(cfg.language)) &
                   values("word").set(cfg.words_to_add);


    auto cli = cli_check | cli_create | cli_add;

    if(parse(argc, argv, cli))
    {
        if(cfg.add_filter(filter_strings) && cfg.validate())
        {
            ret = cspl(cfg);
        }
    }
    else
    {
        cout << make_man_page(cli, argv[0]) << '\n';
        cout << "Dictionary directory: " << CSPL_DICTIONARY_DIR << "\n";
    }
    return ret;
}
