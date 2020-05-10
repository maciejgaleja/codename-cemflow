/* @file          common.hpp                                                  */

#ifndef LIB__LOTRAME__INCLUDE__LOTRAME__COMMON_HPP
#define LIB__LOTRAME__INCLUDE__LOTRAME__COMMON_HPP


#include <chrono>
#include <string>

namespace ltr
{

using Timestamp = std::chrono::time_point<std::chrono::system_clock>;

enum class Severity
{
    Fatal,
    Error,
    Warning,
    Info,
    Debug,
    Trace
};

class Message
{
public:
    Severity severity;
    Timestamp timestamp;
    std::string text;
};

} // namespace ltr


#endif // LIB__LOTRAME__INCLUDE__LOTRAME__COMMON_HPP
