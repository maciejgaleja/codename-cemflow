/* @file          log_handler.cpp                                             */
/* @date          2020-05-02                                                  */

#include "lotrame/log_handler.hpp"
#include "lotrame.hpp"
#include "lotrame/engine.hpp"

namespace ltr {

LogHandler::~LogHandler() {
  Message msg;
  msg.text = m_ss.str();
  m_engine.log(msg);
}

} // namespace ltr
