/* @file          stdio_source.hpp                                            */
/* @date          2020-05-02                                                  */

#ifndef APPLICATIONS__CSPL__PROCESSING__STDIO_SOURCE_HPP
#define APPLICATIONS__CSPL__PROCESSING__STDIO_SOURCE_HPP


#include "item_iterator.hpp"

class StdioSource : public ItemIterator<Char>
{
public:
    bool next();
};


#endif // APPLICATIONS__CSPL__PROCESSING__STDIO_SOURCE_HPP
