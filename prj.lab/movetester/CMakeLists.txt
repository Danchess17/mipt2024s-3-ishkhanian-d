add_library(movetester INTERFACE movetester.hpp)
set_property(TARGET movetester PROPERTY CXX_STANDARD 20)
target_include_directories(movetester INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)