find_package(doctest REQUIRED)

add_executable(stackarr_doctest stackarr_doctest.cpp)
target_link_libraries(stackarr_doctest doctest::doctest stackarr)

add_executable(stacklst_doctest stacklst_doctest.cpp)
target_link_libraries(stacklst_doctest doctest::doctest stacklst)

add_executable(stackarrT_doctest stackarrT_doctest.cpp)
target_link_libraries(stackarrT_doctest doctest::doctest 
templ_stackarr)

add_executable(stacklstT_doctest stacklstT_doctest.cpp)
target_link_libraries(stacklstT_doctest doctest::doctest 
templ_stacklst)