function(find_package_or_add_subdirectory)
  cmake_parse_arguments(FPOASU "" "DIR;LIBRARY" "INCLUDE" ${ARGN})

  message("Looking for library: ${FPOASU_LIBRARY} / ${FPOASU_INCLUDE}")
  set(LIB_NAME "${FPOASU_DIR}")

  find_library(
    ${LIB_NAME}_LIB
    NAMES ${FPOASU_LIBRARY}
    PATHS /usr/lib/x86_64-linux-gnu
    PATH_SUFFIXES .so)

  find_path(
    ${LIB_NAME}_INC
    NAMES ${FPOASU_INCLUDE}
    PATHS /usr/include)

  if(${LIB_NAME}_LIB AND ${LIB_NAME}_INC)
    message("    ${${LIB_NAME}_LIB}")
    message("    ${${LIB_NAME}_INC}")
    add_library(${FPOASU_LIBRARY} INTERFACE)
    target_include_directories(${FPOASU_LIBRARY} INTERFACE ${${LIB_NAME}_INC})
    target_link_libraries(${FPOASU_LIBRARY} INTERFACE ${${LIB_NAME}_LIB})
  else()
    message("    adding subdirectory: ${FPOASU_DIR}")
    add_subdirectory(${FPOASU_DIR})
  endif()

endfunction()

function(find_and_add_library)
  cmake_parse_arguments(FAAL "" "NAME;LIBRARY" "INCLUDE" ${ARGN})

  message("Looking for library: ${FAAL_LIBRARY} / ${FAAL_INCLUDE}")
  set(LIB_NAME "${FAAL_NAME}")

  find_library(
    ${LIB_NAME}_LIB
    NAMES ${FAAL_LIBRARY}
    PATHS /usr/lib/x86_64-linux-gnu ${CMAKE_INSTALL_PATH}/lib
    PATH_SUFFIXES .so)

  find_path(
    ${LIB_NAME}_INC
    NAMES ${FAAL_INCLUDE}
    PATHS /usr/include)

  if(${LIB_NAME}_LIB AND ${LIB_NAME}_INC)
    message("    ${${LIB_NAME}_LIB}")
    message("    ${${LIB_NAME}_INC}")
    add_library(${FAAL_NAME} INTERFACE)
    target_include_directories(${FAAL_NAME} INTERFACE ${${LIB_NAME}_INC})
    target_link_libraries(${FAAL_NAME} INTERFACE ${${LIB_NAME}_LIB})
  else()
    message(FATAL_ERROR "    failed")
  endif()
endfunction()

add_subdirectory(libresult)
add_subdirectory(clipp)
add_subdirectory(utilities)
add_subdirectory(libcmake)
find_package_or_add_subdirectory(LIBRARY libhunspell INCLUDE hunspell.hxx DIR
                                 hunspell)
find_and_add_library(NAME git2 LIBRARY git2 INCLUDE git2.h)
add_subdirectory(hunspell-dictionary)
add_subdirectory(lotrame)
