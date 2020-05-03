add_executable(cmk cmk.cpp run_config.hpp)
target_link_libraries(cmk clipp utilities libresult -lstdc++fs)
install(TARGETS cmk)
