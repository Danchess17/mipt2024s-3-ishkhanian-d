find_package(nlohmann_json 3.7.0 REQUIRED)
add_executable(jsonreader jsonreader.cpp)
target_link_libraries(jsonreader nlohmann_json::nlohmann_json)