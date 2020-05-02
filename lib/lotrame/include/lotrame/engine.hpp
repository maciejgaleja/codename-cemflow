/* @file          engine.h                                                    */
/* @date          2020-05-02                                                  */

#ifndef LIB__LOTRAME__INTERNAL__ENGINE_H
#define LIB__LOTRAME__INTERNAL__ENGINE_H


#include "common.hpp"
#include "log_handler.hpp"

#include <list>
#include <map>
#include <mutex>
#include <sstream>

namespace ltr {

class Trace;

class Engine {
public:
  void traceRegister(const Trace *trace);
  void traceUnRegister(const Trace *trace);

  void log(const Message &msg);

  LogHandler debug() { return LogHandler(*this, Severity::Debug); }

  LogHandler error() { return LogHandler(*this, Severity::Error); }

private:
  std::mutex m_mutex;
  std::map<std::thread::id, std::list<const Trace *>> m_traces;
};

} // namespace ltr


#endif // LIB__LOTRAME__INTERNAL__ENGINE_H
