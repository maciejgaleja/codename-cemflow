/* @file          dictionary.cpp                                              */
/* @date          2020-05-02                                                  */

#include "dictionary.hpp"
#include "../log.hpp"

#include <iostream>

using std::cin;
using std::cout;

#if GCC_VERSION < 90000
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif


Dictionary::Dictionary(Hunspell& hs,
                       const std::string& language,
                       const std::string& root_path)
    : m_hs(hs)
{
    for(const auto& p : get_parent_paths(root_path))
    {
        fs::path dict_p = p;
        dict_p.append("." + language + ".cspl");
        if(fs::exists(dict_p))
        {
            m_custom.push_back(CustomDictionary(dict_p.string()));
        }
    }
    for(auto& d : m_custom)
    {
        for(auto& s : d.words())
        {
            m_hs.add(s);
        }
    }
}

Dictionary::~Dictionary()
{
    for(const auto& word : m_added_words)
    {
        int i = ask_where_to_add_word(word);
        m_custom[i].add(word);
    }
}

void Dictionary::add(Word word)
{
    m_hs.add(word);
    m_added_words.push_back(word);
}

std::vector<fs::path> Dictionary::get_parent_paths(const std::string& root_path)
{
    std::vector<fs::path> ret;
    fs::path p = root_path;

    p       = fs::absolute(p);
    auto pp = p.parent_path();

    while(pp != p)
    {
        pp = std::exchange(p, {p.parent_path()});
        ret.push_back(pp);
    }

    return ret;
}

int Dictionary::ask_where_to_add_word(const Word& word)
{
    cout << "You requested to add word \"" << word
         << "\" to dictionary. Which one to use?\n";
    int n = 1;
    for(auto& d : m_custom)
    {
        cout << n++ << ":  " << d.path() << "\n";
    }

    std::string decision_str;
    cin >> decision_str;

    int ret = -1;
    try
    {
        ret = std::stoi(decision_str) - 1;
    }
    catch(const std::invalid_argument& e)
    {}
    if(ret > m_custom.size() - 1)
    {
        ret = -1;
    }
    if(ret < 0)
    {
        cout << "Invalid option";
        ret = ask_where_to_add_word(word);
    }

    return ret;
}
