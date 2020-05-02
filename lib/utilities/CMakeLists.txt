add_library(utilities STATIC include/utilities/version.hpp src/version.cpp)
target_include_directories(utilities PUBLIC ./include/)