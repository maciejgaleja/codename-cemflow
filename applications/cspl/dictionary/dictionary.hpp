/* @file          dictionary.hpp                                              */
/* @date          2020-05-02                                                  */

#ifndef APPLICATIONS__CSPL__DICTIONARY__DICTIONARY_HPP
#define APPLICATIONS__CSPL__DICTIONARY__DICTIONARY_HPP


#if GCC_VERSION < 90000
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

#include <vector>

#include <hunspell.hxx>

#include "custom_dictionary.hpp"

class Dictionary
{
public:
    Dictionary(Hunspell& hs,
               const std::string& language,
               const std::string& root_path);
    ~Dictionary();
    Hunspell& hunspell()
    {
        return m_hs;
    }

    void add(Word word);

private:
    Hunspell& m_hs;
    std::vector<CustomDictionary> m_custom;
    std::vector<Word> m_added_words;

    std::vector<fs::path>
    get_parent_paths(const std::string& root_path);

    int ask_where_to_add_word(const Word& word);
};


#endif // APPLICATIONS__CSPL__DICTIONARY__DICTIONARY_HPP
