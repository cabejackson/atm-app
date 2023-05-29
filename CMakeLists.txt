cmake_minimum_required(VERSION 3.26.3)

project(atm_app LANGUAGES CXX)

add_executable(atm_app main.cpp)

# Add Catch2 as a subdirectory
add_subdirectory(Catch2)

# Link Catch2 to the executable
target_link_libraries(atm_app PRIVATE Catch2::Catch2)