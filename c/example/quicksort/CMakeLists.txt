add_executable(example_quicksort example/quicksort/quicksort.c
example/quicksort/service/quicksort_service.c)
include(./otterop/io/CMakeLists.txt)
find_static_library(gc GC)
target_link_libraries(example_quicksort otterop_io otterop_lang ${GC} pthread dl)
