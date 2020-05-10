/* @file          file_source.hpp                                             */

#ifndef APPLICATIONS__CSPL__PROCESSING__FILE_SOURCE_HPP
#define APPLICATIONS__CSPL__PROCESSING__FILE_SOURCE_HPP


#include "item_iterator.hpp"

#include <fstream>

class FileSource : public ItemIterator<Char>
{
public:
    FileSource(const std::string& filename);
    bool next();

private:
    std::ifstream m_in;
};


#endif // APPLICATIONS__CSPL__PROCESSING__FILE_SOURCE_HPP
