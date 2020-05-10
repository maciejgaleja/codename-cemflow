/* @file          char_filter.hpp                                             */

#ifndef APPLICATIONS__CSPL__PROCESSING__CHAR_FILTER_HPP
#define APPLICATIONS__CSPL__PROCESSING__CHAR_FILTER_HPP


#include <functional>

#include "common.hpp"
#include "filter_buffer.hpp"
#include "item_sink.hpp"
#include "item_source.hpp"

class CharFilter : public ItemSink<Char>
{
public:
    CharFilter(const std::string& start,
               const std::string& end,
               bool inverted = false);
    ~CharFilter() {}
    void add(const Char& c);

    void add_match_sink(std::shared_ptr<ItemSink<Char>> sink)
    {
        m_match_sinks.push_back(sink);
    }
    void add_unmatch_sink(std::shared_ptr<ItemSink<Char>> sink)
    {
        m_unmatch_sinks.push_back(sink);
    }

private:
    std::vector<std::shared_ptr<ItemSink<Char>>> m_match_sinks;
    std::vector<std::shared_ptr<ItemSink<Char>>> m_unmatch_sinks;

    FilterBuffer m_buf_begin;
    FilterBuffer m_buf_end;

    std::function<void(Char)> m_on_match;
    std::function<void(Char)> m_on_unmatch;

    bool m_invert = false;
    bool m_active = false;
    int m_delay;

    void notify_match(Char c)
    {
        for(auto& sink : m_match_sinks)
        {
            sink->add(c);
        }
    }

    void notify_unmatch(Char c)
    {
        for(auto& sink : m_unmatch_sinks)
        {
            sink->add(c);
        }
    }
};


#endif // APPLICATIONS__CSPL__PROCESSING__CHAR_FILTER_HPP
