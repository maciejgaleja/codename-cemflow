add_library(
  lotrame STATIC
  lotrame.cpp
  include/lotrame.hpp
  include/lotrame/common.hpp
  src/engine.cpp
  include/lotrame/engine.hpp
  src/log_handler.cpp
  include/lotrame/log_handler.hpp
  src/trace.cpp
  include/lotrame/queue.hpp
  include/lotrame/trace.hpp)
target_include_directories(lotrame PUBLIC ./include)
