cmake_minimum_required(VERSION 3.10)
project(StargateGatekeeper)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

# Link the JSON library we downloaded earlier
add_executable(gatekeeper_app src/main.cpp)
