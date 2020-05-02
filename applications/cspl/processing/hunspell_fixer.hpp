/* @file          hunspell_fixer.hpp                                          */
/* @date          2020-05-02                                                  */

#ifndef APPLICATIONS__CSPL__PROCESSING__HUNSPELL_FIXER_HPP
#define APPLICATIONS__CSPL__PROCESSING__HUNSPELL_FIXER_HPP


#include "hunspell_checker.hpp"

struct UserDecision
{
    enum class Choice
    {
        REPLACE,
        IGNORE,
        ADD,
        CUSTOM
    };
    Choice choice   = Choice::IGNORE;
    int chosen_word = -1;
    std::string custom_word;
};

class HunspellFixer : public HunspellChecker
{
public:
    HunspellFixer(Dictionary& dict) : HunspellChecker(dict){};
    void add(const Word& word);

private:
    UserDecision ask_user(std::string error_word,
                          std::vector<std::string>& options);
};


#endif // APPLICATIONS__CSPL__PROCESSING__HUNSPELL_FIXER_HPP
