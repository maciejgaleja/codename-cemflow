add_library(utilities STATIC include/utilities/version.hpp src/version.cpp
include/utilities/env.hpp src/env.cpp)
target_include_directories(utilities PUBLIC ./include/)