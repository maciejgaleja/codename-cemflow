/* @file          custom_dictionary.cpp                                       */
/* @date          2020-05-02                                                  */

#include "custom_dictionary.hpp"

#include "../log.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>


CustomDictionary::CustomDictionary(const std::string& filename)
    : m_path(filename)
{
    std::ifstream infile(filename);
    std::string word;
    while(infile >> word)
    {
        m_words.push_back(word);
    }
}

CustomDictionary::~CustomDictionary()
{
    std::ofstream out(m_path);
    std::sort(m_words.begin(), m_words.end());
    for(const auto& word : m_words)
    {
        out << word << "\n";
    }
    out.close();
}

void CustomDictionary::add(const Word& word)
{
    m_words.push_back(word);
}
