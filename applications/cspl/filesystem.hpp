/* @file          filesystem.hpp                                              */

#ifndef APPLICATIONS__CSPL__FILESYSTEM_HPP
#define APPLICATIONS__CSPL__FILESYSTEM_HPP

#if GCC_VERSION < 90000
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

#endif // APPLICATIONS__CSPL__FILESYSTEM_HPP
