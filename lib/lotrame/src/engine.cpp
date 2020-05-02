/* @file          engine.cpp                                                  */
/* @date          2020-05-02                                                  */

#include "lotrame/engine.hpp"
#include "lotrame/trace.hpp"

#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::stringstream;

namespace ltr {

void Engine::traceRegister(const Trace *trace) {
  stringstream ss;
  ss << "START ";
  ss << trace->id() << " (" << std::setw(6) << 0 << " us) ";
  for (auto &t : m_traces[trace->id()]) {
    ss << t->toString() << " -> ";
  }
  ss << trace->toString() << endl;
  cout << ss.str();

  std::lock_guard<std::mutex> lock(m_mutex);
  m_traces[trace->id()].push_back(trace);
}

void Engine::traceUnRegister(const Trace *trace) {
  std::lock_guard<std::mutex> lock(m_mutex);
  assert(m_traces[trace->id()].back() == trace);
  m_traces[trace->id()].pop_back();

  stringstream ss;
  ss << "STOP  ";
  ss << trace->id() << " (" << std::setw(6) << trace->time().count() << " us) ";
  for (auto &t : m_traces[trace->id()]) {
    ss << t->toString() << " -> ";
  }
  ss << trace->toString() << endl;
  cout << ss.str();
}

void Engine::log(const Message &msg) {
  if(msg.severity <= m_severity_level) {
    std::thread::id threadId = std::this_thread::get_id();
    stringstream ss;
    ss << "WORK  ";
    ss << threadId << " (" << std::setw(6) << 0 << " us) ";
    for (auto &t : m_traces[threadId]) {
      ss << t->toString() << " -> ";
    }
    ss << msg.text << endl;
    cout << ss.str();
  }
}

void Engine::setSeverity(Severity sev)
{
  m_severity_level = sev;
}


} // namespace ltr
