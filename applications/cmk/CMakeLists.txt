add_executable(cmk cmk.cpp)
target_link_libraries(cmk clipp)
install(TARGETS cmk)
