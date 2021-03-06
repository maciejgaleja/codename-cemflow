/* @file          log_handler.cpp                                             */

#include "lotrame/log_handler.hpp"

#include "lotrame.hpp"
#include "lotrame/engine.hpp"

namespace ltr
{

LogHandler::~LogHandler()
{
    Message msg;
    msg.severity = m_severity;
    msg.text     = m_ss.str();
    m_engine.log(msg);
}

} // namespace ltr
