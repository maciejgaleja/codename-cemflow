/* @file          item_sink.hpp                                               */

#ifndef APPLICATIONS__CSPL__PROCESSING__ITEM_SINK_HPP
#define APPLICATIONS__CSPL__PROCESSING__ITEM_SINK_HPP


template <typename T>
class ItemSink
{
public:
    virtual ~ItemSink() {}
    virtual void add(const T& item) = 0;
};


#endif // APPLICATIONS__CSPL__PROCESSING__ITEM_SINK_HPP
