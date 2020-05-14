function(find_package_or_add_subdirectory)
    cmake_parse_arguments(FPOASU "" "DIR;LIBRARY" "INCLUDE" ${ARGN})
    
    message("Looking for library: ${FPOASU_LIBRARY} / ${FPOASU_INCLUDE}")
    set(LIB_NAME "${FPOASU_DIR}")

    find_library(${LIB_NAME}_LIB NAMES ${FPOASU_LIBRARY}
        PATHS
            /usr/lib/x86_64-linux-gnu
        PATH_SUFFIXES .so)

    find_path(${LIB_NAME}_INC NAMES ${FPOASU_INCLUDE} 
        PATHS
            /usr/include)

    if(${LIB_NAME}_LIB AND ${LIB_NAME}_INC)
        message("    ${${LIB_NAME}_LIB}")
        message("    ${${LIB_NAME}_INC}")
        add_library(${FPOASU_DIR} INTERFACE)
    else()
        message("    adding subdirectory: ${FPOASU_DIR}")
        add_subdirectory(${FPOASU_DIR})
    endif()

endfunction()

add_subdirectory(libresult)
add_subdirectory(clipp)
add_subdirectory(utilities)
add_subdirectory(libcmake)
find_package_or_add_subdirectory(LIBRARY libhunspell INCLUDE hunspell.hxx DIR hunspell)
find_package_or_add_subdirectory(LIBRARY git2 INCLUDE git2.h DIR libgit2)
add_subdirectory(hunspell-dictionary)
add_subdirectory(lotrame)