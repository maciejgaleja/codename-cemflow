/* @file          filter_buffer.cpp                                           */
/* @date          2020-05-02                                                  */

#include "filter_buffer.hpp"
#include <algorithm>
#include <iostream>

#include <lotrame.hpp>

FilterBuffer::FilterBuffer(const std::string& pattern)
{
    debug() << "Creating filter for " << pattern;
    for(char c : pattern)
    {
        m_pattern.push_back(c);
        m_buffer.push_back('\0');
    }
}

size_t FilterBuffer::size() const
{
    return m_pattern.size();
}

std::pair<bool, Char> FilterBuffer::add(Char c)
{
    Char ret_c = m_buffer[0];
    m_buffer.pop_front();
    m_buffer.push_back(c);

    bool ret = std::equal(m_pattern.begin(), m_pattern.end(), m_buffer.begin());

    return {ret, ret_c};
}

std::string FilterBuffer::debugToString(const std::deque<Char>& buffer)
{
    std::string ret = "[";
    for(char c : buffer)
    {
        ret += c;
    }
    ret += "]";
    return ret;
}
