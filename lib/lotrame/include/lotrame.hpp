/* @file          lotrame.hpp                                                 */

#ifndef LIB__LOTRAME__INCLUDE__LOTRAME_HPP
#define LIB__LOTRAME__INCLUDE__LOTRAME_HPP


#include "lotrame/engine.hpp"
#include "lotrame/log_handler.hpp"
#include "lotrame/queue.hpp"
#include "lotrame/trace.hpp"

#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <thread>

extern ltr::Engine logging;

#define debug() ltr::LogHandler(logging, ltr::Severity::Debug)
#define trace() ltr::LogHandler(logging, ltr::Severity::Trace)


#endif // LIB__LOTRAME__INCLUDE__LOTRAME_HPP
