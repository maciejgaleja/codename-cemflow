/* @file          engine.hpp                                                  */

#ifndef LIB__LOTRAME__INCLUDE__LOTRAME__ENGINE_HPP
#define LIB__LOTRAME__INCLUDE__LOTRAME__ENGINE_HPP


#include "common.hpp"
#include "log_handler.hpp"

#include <list>
#include <map>
#include <mutex>
#include <sstream>
#include <thread>

namespace ltr
{

class Trace;

class Engine
{
public:
    void traceRegister(const Trace* trace);
    void traceUnRegister(const Trace* trace);

    void log(const Message& msg);

    void setSeverity(Severity sev);

    LogHandler debug()
    {
        return LogHandler(*this, Severity::Debug);
    }

    LogHandler error()
    {
        return LogHandler(*this, Severity::Error);
    }

private:
    std::mutex m_mutex;
    std::map<std::thread::id, std::list<const Trace*>> m_traces;
    Severity m_severity_level = Severity::Trace;
};

} // namespace ltr


#endif // LIB__LOTRAME__INCLUDE__LOTRAME__ENGINE_HPP
