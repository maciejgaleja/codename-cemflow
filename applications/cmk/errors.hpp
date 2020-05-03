/* @file          errors.hpp                                                  */
/* @date          2020-05-03                                                  */

#ifndef APPLICATIONS__CMK__ERRORS_HPP
#define APPLICATIONS__CMK__ERRORS_HPP

#include <libresult.hpp>

DefineError(CmkError, Error, 1, "cmk error", "Unspecified error");
DefineError(EnvError, CmkError, 2, "env error", "Environment variable error");

#endif // APPLICATIONS__CMK__ERRORS_HPP
