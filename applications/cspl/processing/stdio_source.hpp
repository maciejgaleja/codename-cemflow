/* @file          stdio_source.hpp                                            */

#ifndef APPLICATIONS__CSPL__PROCESSING__STDIO_SOURCE_HPP
#define APPLICATIONS__CSPL__PROCESSING__STDIO_SOURCE_HPP


#include "item_iterator.hpp"

class StdioSource : public ItemIterator<Char>
{
public:
    bool next();
};


#endif // APPLICATIONS__CSPL__PROCESSING__STDIO_SOURCE_HPP
