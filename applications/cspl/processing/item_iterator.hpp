/* @file          item_iterator.hpp                                           */

#ifndef APPLICATIONS__CSPL__PROCESSING__ITEM_ITERATOR_HPP
#define APPLICATIONS__CSPL__PROCESSING__ITEM_ITERATOR_HPP


#include "item_source.hpp"

template <typename T>
class ItemIterator : public ItemSource<T>
{
public:
    virtual ~ItemIterator(){};
    virtual bool next() = 0;
};


#endif // APPLICATIONS__CSPL__PROCESSING__ITEM_ITERATOR_HPP
