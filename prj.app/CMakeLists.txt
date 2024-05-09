add_subdirectory(stack_profiler)

add_subdirectory(jsonreader)

add_executable(string_tester string_tester.cpp)
target_link_libraries(string_tester movetester)
