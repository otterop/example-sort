include_directories(
${CMAKE_CURRENT_LIST_DIR}/tests
${CMAKE_CURRENT_LIST_DIR}/unity/src
${CMAKE_CURRENT_LIST_DIR}/unity/extras/fixture/src
)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unity)
include(${CMAKE_CURRENT_LIST_DIR}/tests/example/sort/CMakeLists.txt)
target_sources(example_sort_tests PUBLIC
${CMAKE_CURRENT_LIST_DIR}/unity/src/unity.c
${CMAKE_CURRENT_LIST_DIR}/unity/extras/fixture/src/unity_fixture.c)
add_definitions(-DUNITY_FIXTURE_NO_EXTRAS)

