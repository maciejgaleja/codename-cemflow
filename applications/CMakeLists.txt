function(add_python_executable)
  cmake_parse_arguments(APE "" "NAME;DIR;ENTRYPOINT" "" ${ARGN})

  message("Adding python executable: ${APE_NAME}")

  find_program(PYINSTALLER_EXECUTABLE pyinstaller)

  set(${APE_NAME}_DIST_DIR ${CMAKE_CURRENT_BINARY_DIR}/${APE_NAME}/dist)
  set(${APE_NAME}_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/${APE_NAME}/build)

  add_custom_target(
    ${APE_NAME} ALL
    COMMAND ${PYINSTALLER_EXECUTABLE} ${APE_ENTRYPOINT} -F --distpath
            "${${APE_NAME}_DIST_DIR}" --workpath "${${APE_NAME}_BUILD_DIR}" --name ${APE_NAME}
    WORKING_DIRECTORY ${APE_DIR})

    set(${APE_NAME}_EXECUTABLE ${APE_NAME}.exe)

    install(PROGRAMS ${${APE_NAME}_DIST_DIR}/${${APE_NAME}_EXECUTABLE} DESTINATION bin)

endfunction(add_python_executable)

add_subdirectory(cmk)
add_subdirectory(cspl)

add_python_executable(NAME cpro DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpro/cpro
                      ENTRYPOINT cpro.py)
# message(FATAL_ERROR "FORCE_ERROR")
