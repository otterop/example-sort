project(example_sort)

cmake_minimum_required(VERSION 3.16)
set(CMAKE_BINARY_DIR out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

function(find_static_library LIB_NAME OUT)

    if (WIN32 OR MSVC)
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
    elseif (UNIX)
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    endif()

    find_library(
        FOUND_${LIB_NAME}_STATIC
        ${LIB_NAME}
        )

    if (FOUND_${LIB_NAME}_STATIC)
        get_filename_component(ABS_FILE ${FOUND_${LIB_NAME}_STATIC} ABSOLUTE)
    else()
        message(SEND_ERROR "Unable to find library ${LIB_NAME}")
    endif()

    set(${OUT} ${ABS_FILE} PARENT_SCOPE)

endfunction()

include(./example/sort/CMakeLists.txt)
include(./otterop/io/CMakeLists.txt)
include(./otterop/lang/CMakeLists.txt)
include(./otterop/test/CMakeLists.txt)
include(./test/CMakeLists.txt)
find_static_library(gc GC)
set(EXAMPLE_SORT_LIBS otterop_io otterop_lang ${GC} pthread dl)
target_link_libraries(example_sort ${EXAMPLE_SORT_LIBS})
target_link_libraries(example_sort_tests ${EXAMPLE_SORT_LIBS} example_sort__lib otterop_test unity)
set_property(TARGET example_sort PROPERTY C_STANDARD 99)
set_property(TARGET example_sort__lib PROPERTY C_STANDARD 99)
set_property(TARGET example_sort_tests PROPERTY C_STANDARD 99)
add_custom_target(test ./out/bin/example_sort_tests)
include_directories(.)
