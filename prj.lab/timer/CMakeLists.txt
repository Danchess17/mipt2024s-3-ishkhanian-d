add_library(timer INTERFACE timer.hpp)
set_property(TARGET timer PROPERTY CXX_STANDARD 20)
target_include_directories(timer INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)