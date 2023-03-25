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
find_static_library(gc GC)
target_link_libraries(example_sort otterop_io otterop_lang ${GC} pthread dl)
set_property(TARGET example_sort PROPERTY C_STANDARD 99)
include_directories(.)
