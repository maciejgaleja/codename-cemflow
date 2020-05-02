/* @file          trace.h                                                     */
/* @date          2020-05-02                                                  */

#ifndef LIB__LOTRAME__INTERNAL__TRACE_H
#define LIB__LOTRAME__INTERNAL__TRACE_H


#include "common.hpp"
#include <string>
#include <thread>

namespace ltr {

class Engine;

class Trace {
public:
  using Source = std::string;

  Trace(Engine *engine, const Source &source,
        const std::string &extraInfo = "");
  ~Trace();

  std::thread::id id() const;
  std::string toString() const;
  Source source() const;
  std::chrono::microseconds time() const;

private:
  std::thread::id m_id;
  std::string m_extraInfo;
  Source m_source;
  Engine *m_engine;
  Timestamp m_timeStart;
  Timestamp m_timeEnd;
};

} // namespace ltr


#endif // LIB__LOTRAME__INTERNAL__TRACE_H
