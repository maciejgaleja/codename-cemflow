/* @file          queue.hpp                                                   */

#ifndef LIB__LOTRAME__INCLUDE__LOTRAME__QUEUE_HPP
#define LIB__LOTRAME__INCLUDE__LOTRAME__QUEUE_HPP


#include <condition_variable>
#include <mutex>
#include <queue>

namespace ltr
{

namespace internal
{

template <class T>
class Queue
{
public:
    Queue(void) : m_queue(), m_mutex(), m_cv() {}
    ~Queue(void) {}

    void push(const T& element)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(element);
        m_cv.notify_one();
    }

    T pop(void)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        while(m_queue.empty())
        {
            m_cv.wait(lock);
        }
        T val = m_queue.front();
        m_queue.pop();
        return val;
    }

private:
    std::queue<T> m_queue;
    mutable std::mutex m_mutex;
    std::condition_variable m_cv;
};

} // namespace internal
} // namespace ltr


#endif // LIB__LOTRAME__INCLUDE__LOTRAME__QUEUE_HPP
