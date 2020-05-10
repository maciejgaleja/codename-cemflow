/* @file          word_converter.cpp                                          */

#include "word_converter.hpp"

#include <iostream>

void WordConverter::add(const Char& c)
{
    if(is_separator(c))
    {
        std::string word = m_buffer.str();
        m_buffer.str("");
        if(word.length() > 0)
        {
            notify_all_words(word);
        }
        if(c != ASCII_ACK)
        {
            notify_all_chars(c);
        }
    }
    else
    {
        m_buffer << c;
    }
}

void WordConverter::add_word_sink(std::shared_ptr<ItemSink<Word>> sink)
{
    m_word_sinks.push_back(sink);
}

void WordConverter::notify_all_words(Word word)
{
    for(auto& sink : m_word_sinks)
    {
        sink->add(word);
    }
}

void WordConverter::add_char_sink(std::shared_ptr<ItemSink<Char>> sink)
{
    m_char_sinks.push_back(sink);
}

void WordConverter::notify_all_chars(Char c)
{
    for(auto& sink : m_char_sinks)
    {
        sink->add(c);
    }
}

bool WordConverter::is_separator(Char c)
{
    return !((c >= '0' && c <= '9') || (c >= 'A' && c <= 'z'));
}
