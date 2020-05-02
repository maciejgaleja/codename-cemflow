/* @file          hunspell_checker.cpp                                        */
/* @date          2020-05-02                                                  */

#include "hunspell_checker.hpp"

#include <iostream>

void HunspellChecker::add(const Word& word)
{
    if(!m_dict.hunspell().spell(word.c_str()))
    {
        m_errors.push_back(word);
    }
    notify_all(word);
}
