set(DICT_LANGUAGE en_US)

set(DICT_FILE_AFF ${DICT_LANGUAGE}.aff)
if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/${DICT_FILE_AFF})
  message("Downloading dictionary")
  file(
    DOWNLOAD
    https://cgit.freedesktop.org/libreoffice/dictionaries/tree/en/${DICT_FILE_AFF}
    ${CMAKE_CURRENT_BINARY_DIR}/${DICT_FILE_AFF}
    SHOW_PROGRESS)
endif()

set(DICT_FILE_DIC ${DICT_LANGUAGE}.dic)
if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/${DICT_FILE_DIC})
  message("Downloading dictionary")
  file(
    DOWNLOAD
    https://cgit.freedesktop.org/libreoffice/dictionaries/tree/en/${DICT_FILE_DIC}
    ${CMAKE_CURRENT_BINARY_DIR}/${DICT_FILE_DIC}
    SHOW_PROGRESS)
endif()

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${DICT_FILE_AFF}
              ${CMAKE_CURRENT_BINARY_DIR}/${DICT_FILE_DIC}
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR})
