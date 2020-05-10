/* @file          word_converter.hpp                                          */

#ifndef APPLICATIONS__CSPL__PROCESSING__WORD_CONVERTER_HPP
#define APPLICATIONS__CSPL__PROCESSING__WORD_CONVERTER_HPP


#include "common.hpp"
#include "item_sink.hpp"
#include "item_source.hpp"

#include <sstream>

class WordConverter : public ItemSink<Char>, public ItemSource<Word>
{
private:
    std::vector<std::shared_ptr<ItemSink<Word>>> m_word_sinks;
    std::vector<std::shared_ptr<ItemSink<Char>>> m_char_sinks;
    std::stringstream m_buffer;

    void notify_all_words(Word word);
    void notify_all_chars(Char c);

    bool is_separator(Char c);

public:
    void add(const Char& c);

    void add_word_sink(std::shared_ptr<ItemSink<Word>> sink);
    void add_char_sink(std::shared_ptr<ItemSink<Char>> sink);
};


#endif // APPLICATIONS__CSPL__PROCESSING__WORD_CONVERTER_HPP
