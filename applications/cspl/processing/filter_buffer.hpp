/* @file          filter_buffer.hpp                                           */

#ifndef APPLICATIONS__CSPL__PROCESSING__FILTER_BUFFER_HPP
#define APPLICATIONS__CSPL__PROCESSING__FILTER_BUFFER_HPP


#include <deque>

#include "common.hpp"
#include <map>

class FilterBuffer
{
public:
    FilterBuffer(const std::string& pattern);
    std::pair<bool, Char> add(Char c);
    size_t size() const;

private:
    std::deque<Char> m_buffer;
    std::deque<Char> m_pattern;

    std::string debugToString(const std::deque<Char>& m_buffer);
};


#endif // APPLICATIONS__CSPL__PROCESSING__FILTER_BUFFER_HPP
