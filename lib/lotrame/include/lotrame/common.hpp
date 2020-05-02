/* @file          common.h                                                    */
/* @date          2020-05-02                                                  */

#ifndef LIB__LOTRAME__INTERNAL__COMMON_H
#define LIB__LOTRAME__INTERNAL__COMMON_H


#include <chrono>
#include <string>

namespace ltr {

using Timestamp = std::chrono::time_point<std::chrono::system_clock>;

enum class Severity { Fatal, Error, Warning, Info, Debug, Trace };

class Message {
public:
  Severity severity;
  Timestamp timestamp;
  std::string text;
};

} // namespace ltr


#endif // LIB__LOTRAME__INTERNAL__COMMON_H
