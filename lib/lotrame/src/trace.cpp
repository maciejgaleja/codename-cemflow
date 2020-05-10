/* @file          trace.cpp                                                   */

#include "lotrame/trace.hpp"

#include "lotrame/engine.hpp"

#include <chrono>
#include <sstream>

using namespace std;

namespace ltr
{
Trace::Trace(Engine* engine, const Source& source, const std::string& extraInfo)
    : m_engine(engine), m_extraInfo(extraInfo), m_source(source)
{
    m_timeStart = chrono::system_clock::now();
    m_id        = std::this_thread::get_id();
    m_engine->traceRegister(this);
}

Trace::~Trace()
{
    m_timeEnd = chrono::system_clock::now();
    m_engine->traceUnRegister(this);
}

thread::id Trace::id() const
{
    return m_id;
}

string Trace::toString() const
{
    stringstream ss;
    ss << m_id;
    ss << " " << m_source;
    ss << "(" << m_extraInfo << ")";
    return ss.str();
}

string Trace::source() const
{
    return m_source;
}

chrono::microseconds Trace::time() const
{
    return chrono::duration_cast<chrono::microseconds>(m_timeEnd - m_timeStart);
}

} // namespace ltr
