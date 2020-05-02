/* @file          hunspell_checker.hpp                                        */
/* @date          2020-05-02                                                  */

#ifndef APPLICATIONS__CSPL__PROCESSING__HUNSPELL_CHECKER_HPP
#define APPLICATIONS__CSPL__PROCESSING__HUNSPELL_CHECKER_HPP


#include "item_sink.hpp"
#include "item_source.hpp"

#include "../dictionary/dictionary.hpp"

class HunspellChecker : public ItemSink<Word>, public ItemSource<Word>
{
public:
    HunspellChecker(Dictionary& dict) : m_dict(dict){};

    void add(const Word& word);

    std::vector<Word>& errors()
    {
        return m_errors;
    }

protected:
    Dictionary& m_dict;
    std::vector<Word> m_errors;
};


#endif // APPLICATIONS__CSPL__PROCESSING__HUNSPELL_CHECKER_HPP
