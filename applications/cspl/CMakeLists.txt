set(CSPL_DICTIONARY_DIR
	${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/hunspell)

add_executable(cspl
	main.cpp
	cspl.hpp                           cspl.cpp
	run_config.hpp                     run_config.cpp
	processing/stdio_source.hpp        processing/stdio_source.cpp
	processing/file_source.hpp         processing/file_source.cpp
	processing/char_filter.hpp         processing/char_filter.cpp
	processing/file_sink.hpp
	processing/filter_buffer.hpp       processing/filter_buffer.cpp
	processing/common.hpp
	processing/word_converter.hpp      processing/word_converter.cpp
	processing/hunspell_checker.hpp    processing/hunspell_checker.cpp
	processing/hunspell_fixer.hpp      processing/hunspell_fixer.cpp
	dictionary/custom_dictionary.hpp   dictionary/custom_dictionary.cpp
	dictionary/dictionary.hpp          dictionary/dictionary.cpp
)
target_link_libraries(cspl hunspell clipp lotrame -lstdc++fs)
target_compile_definitions(cspl
	PRIVATE
		CSPL_DICTIONARY_DIR="${CSPL_DICTIONARY_DIR}")
install(TARGETS cspl)
