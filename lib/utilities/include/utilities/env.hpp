/* @file          env.hpp                                                     */
/* @date          2020-05-02                                                  */

#ifndef LIB__UTILITIES__INCLUDE__UTILITIES__ENV_HPP
#define LIB__UTILITIES__INCLUDE__UTILITIES__ENV_HPP

#include <optional>
#include <string>

class Env
{
public:
    static std::optional<std::string> get(const std::string& name);
};

#endif // LIB__UTILITIES__INCLUDE__UTILITIES__ENV_HPP
