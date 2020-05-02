/* @file          lotrame.h                                                   */
/* @date          2020-05-02                                                  */

#ifndef LIB__LOTRAME__LOTRAME_H
#define LIB__LOTRAME__LOTRAME_H

#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <thread>

#include "lotrame/engine.hpp"
#include "lotrame/log_handler.hpp"
#include "lotrame/queue.hpp"
#include "lotrame/trace.hpp"

extern ltr::Engine logging;

#define debug() ltr::LogHandler(logging, ltr::Severity::Debug)
#define trace() ltr::LogHandler(logging, ltr::Severity::Trace)

#endif // LIB__LOTRAME__LOTRAME_H
