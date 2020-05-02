/* @file          item_source.hpp                                             */
/* @date          2020-05-02                                                  */

#ifndef APPLICATIONS__CSPL__PROCESSING__ITEM_SOURCE_HPP
#define APPLICATIONS__CSPL__PROCESSING__ITEM_SOURCE_HPP


#include "common.hpp"
#include "item_sink.hpp"
#include <memory>
#include <vector>

template <typename T>
class ItemSource
{
private:
    std::vector<std::shared_ptr<ItemSink<T>>> m_sinks;

public:
    virtual ~ItemSource() {}
    void add_sink(std::shared_ptr<ItemSink<T>> sink)
    {
        m_sinks.push_back(sink);
    }

protected:
    void notify_all(T item)
    {
        for(auto& sink : m_sinks)
        {
            sink->add(item);
        }
    }
};



#endif // APPLICATIONS__CSPL__PROCESSING__ITEM_SOURCE_HPP
