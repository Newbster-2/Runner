cmake_minimum_required(VERSION 3.15)
project(ulexite CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  
set(CMAKE_CXX_STANDARD 17)
  
find_package(Urho3D REQUIRED)
  
add_executable(ulexite main.cpp)
target_link_libraries(ulexite PRIVATE Urho3D)
