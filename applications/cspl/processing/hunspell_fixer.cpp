/* @file          hunspell_fixer.cpp                                          */
/* @date          2020-05-02                                                  */

#include "hunspell_fixer.hpp"

#include <iostream>

using std::cin;
using std::cout;

void HunspellFixer::add(const Word& word)
{
    bool ok = m_dict.hunspell().spell(word.c_str());
    if(!ok)
    {
        m_errors.push_back(word);
        auto alternatives = m_dict.hunspell().suggest(word);
        auto choice       = ask_user(word, alternatives);
        if(choice.choice == UserDecision::Choice::IGNORE)
        {
            notify_all(word);
        }
        else if(choice.choice == UserDecision::Choice::ADD)
        {
            m_dict.add(word);
            notify_all(word);
        }
        else if(choice.choice == UserDecision::Choice::CUSTOM)
        {
            add(choice.custom_word);
        }
        else
        {
            notify_all(alternatives[choice.chosen_word]);
        }
    }
    else
    {
        notify_all(word);
    }
}

UserDecision HunspellFixer::ask_user(std::string error_word,
                                     std::vector<std::string>& options)
{
    UserDecision ret;
    ret.choice      = UserDecision::Choice::IGNORE;
    ret.chosen_word = -1;

    cout << "----> " << error_word << " <----\n";
    int n = 1;
    for(const auto& s : options)
    {
        cout << n << ": " << s << "\n";
        ++n;
    }
    cout << "i: ignore\n";
    cout << "a: add to dictionary\n";
    cout << "c: custom word\n";

    std::string decision_str;
    cin >> decision_str;

    try
    {
        ret.chosen_word = std::stoi(decision_str) - 1;
        ret.choice      = UserDecision::Choice::REPLACE;
    }
    catch(const std::invalid_argument&)
    {
        if(decision_str == "i")
            ret.choice = UserDecision::Choice::IGNORE;
        else if(decision_str == "a")
            ret.choice = UserDecision::Choice::ADD;
        else if(decision_str == "c")
        {
            ret.choice = UserDecision::Choice::CUSTOM;
            cout << "Type the correct wor below\n";
            cin >> decision_str;
            ret.custom_word = decision_str;
        }
        else
        {
            cout << "Invalid option";
            ret = ask_user(error_word, options);
        }
    }

    return ret;
}
