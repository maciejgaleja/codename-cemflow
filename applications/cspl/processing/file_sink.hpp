/* @file          file_sink.hpp                                               */

#ifndef APPLICATIONS__CSPL__PROCESSING__FILE_SINK_HPP
#define APPLICATIONS__CSPL__PROCESSING__FILE_SINK_HPP


#include "item_sink.hpp"

#include <sstream>

#include <fstream>
#include <iostream>

class FileSink : public ItemSink<Char>, public ItemSink<Word>
{
public:
    FileSink(const std::string& filename) : m_file(filename) {}

    void add(const Char& c)
    {
        if(c != '\0')
        {
            m_buffer << c;
        }
    }

    void add(const Word& word)
    {
        m_buffer << word;
    }

    void flush()
    {
        std::ofstream outFile;
        outFile.open(m_file);
        outFile << m_buffer.str();
        outFile.close();
        m_buffer.str("");
    }

private:
    std::stringstream m_buffer;
    std::string m_file;
};


#endif // APPLICATIONS__CSPL__PROCESSING__FILE_SINK_HPP
