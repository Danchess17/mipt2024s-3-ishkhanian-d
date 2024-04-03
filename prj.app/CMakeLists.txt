add_executable(stack_profiler stack_profiler.cpp)
target_link_libraries(stack_profiler stackarr stacklst)

add_subdirectory(jsonreader)

add_executable(string_tester string_tester.cpp)
target_link_libraries(string_tester movetester)
