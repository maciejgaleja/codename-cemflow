/* @file          custom_dictionary.hpp                                       */

#ifndef APPLICATIONS__CSPL__DICTIONARY__CUSTOM_DICTIONARY_HPP
#define APPLICATIONS__CSPL__DICTIONARY__CUSTOM_DICTIONARY_HPP


#include "../processing/common.hpp"
#include <string>
#include <vector>

class CustomDictionary
{
public:
    CustomDictionary(const std::string& filename);
    ~CustomDictionary();

    const std::vector<Word>& words() const
    {
        return m_words;
    }

    const std::string& path() const
    {
        return m_path;
    }

    void add(const Word& word);

private:
    std::vector<Word> m_words;
    std::string m_path;
};


#endif // APPLICATIONS__CSPL__DICTIONARY__CUSTOM_DICTIONARY_HPP
