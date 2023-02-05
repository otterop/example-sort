add_executable(example_quicksort example/quicksort/quicksort.c)
include(./otterop/io/CMakeLists.txt)
target_link_libraries(example_quicksort otterop_io otterop_lang gc pthread dl)