cmake_minimum_required (VERSION 2.8)
project (NavXTimeStamp)
add_definitions(-std=c++11 -Wall -Wextra -Wno-switch)

FIND_PACKAGE (Threads REQUIRED)



file(GLOB SOURCES
	"include/*.h"
	"src/*.cpp"
)

include_directories("./include")
include_directories("./src")

add_library(navx ${SOURCES})
target_include_directories(navx PUBLIC ./include src)

add_executable(NavXTimeStamp NavXTimeStamp/main.cpp)
target_link_libraries(NavXTimeStamp navx)

target_link_libraries(navx ${CMAKE_THREAD_LIBS_INIT})
#target_compile_features(navx PRIVATE cxx_range_for)

