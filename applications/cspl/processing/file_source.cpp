/* @file          file_source.cpp                                             */

#include "file_source.hpp"

#include <iostream>

FileSource::FileSource(const std::string& filename) : m_in(filename) {}

bool FileSource::next()
{
    bool ret = true;
    Char c;
    if(m_in.good())
    {
        if(m_in.get(c))
        {
            notify_all(c);
        }
    }
    else
    {
        notify_all('\0');
        ret = false;
    }
    return ret;
}
