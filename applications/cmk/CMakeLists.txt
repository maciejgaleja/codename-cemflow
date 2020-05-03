add_executable(cmk cmk.cpp run_config.hpp)
target_link_libraries(cmk clipp utilities libresult)
install(TARGETS cmk)
