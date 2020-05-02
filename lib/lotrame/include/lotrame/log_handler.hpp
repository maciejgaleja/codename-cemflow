/* @file          log_handler.hpp                                             */
/* @date          2020-05-02                                                  */

#ifndef LIB__LOTRAME__INCLUDE__LOTRAME__LOG_HANDLER_HPP
#define LIB__LOTRAME__INCLUDE__LOTRAME__LOG_HANDLER_HPP


#include "common.hpp"

#include <sstream>

namespace ltr
{

class Engine;

class LogHandler
{
public:
    LogHandler(Engine& engine, Severity severity)
        : m_engine(engine), m_severity(severity)
    {}
    LogHandler(LogHandler& other) : m_engine(other.m_engine) {}
    ~LogHandler();

    template <typename T>
    LogHandler& operator<<(T const& data)
    {
        m_ss << data;
        return *this;
    }

private:
    Engine& m_engine;
    Severity m_severity;
    std::stringstream m_ss;
};

} // namespace ltr


#endif // LIB__LOTRAME__INCLUDE__LOTRAME__LOG_HANDLER_HPP
