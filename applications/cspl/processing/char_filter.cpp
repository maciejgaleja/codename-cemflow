/* @file          char_filter.cpp                                             */
/* @date          2020-05-02                                                  */

#include "char_filter.hpp"

#include <lotrame.hpp>
#include <iomanip>
#include <iostream>

using std::cout;

CharFilter::CharFilter(const std::string& start,
                       const std::string& end,
                       bool inverted)
    : m_buf_begin(start), m_buf_end(end), m_invert(inverted)
{
    if(inverted)
    {
        m_on_match   = [this](char c) { notify_unmatch(c); };
        m_on_unmatch = [this](char c) { notify_match(c); };
    }
    else
    {
        m_on_match   = [this](char c) { notify_match(c); };
        m_on_unmatch = [this](char c) { notify_unmatch(c); };
    }
}


void CharFilter::add(const Char& c)
{
    m_delay          = --m_delay < -1 ? -1 : m_delay;
    auto match_begin = m_buf_begin.add(c);
    auto match_end   = m_buf_end.add(c);
    if(match_begin.first && match_end.first)
    {
        trace() << "both hits " << m_active;
        if(m_active == false)
        {
            match_end.first = false;
        }
        else
        {
            match_begin.first = false;
        }
    }
    if(match_begin.first)
    {
        trace() << "begin hit";
        m_active = true;
        m_delay  = m_buf_end.size();
    }
    Char c_fwd = match_end.second;
    if(c_fwd != '\0')
    {
        if(m_active && (m_delay < 0))
        {
            trace() << c_fwd << "_";
            m_on_match(c_fwd);
        }
        else
        {
            trace() << "_" << c_fwd;
            m_on_unmatch(c_fwd);
        }
    }
    if(match_end.first)
    {
        trace() << "end hit";
        m_active = false;
        m_on_match(ASCII_ACK);
    }
}
