project(points_solver)
cmake_minimum_required(VERSION 2.8)

set(SOURCE
    points_solver.cpp
)

set(SOURCE_O
   PointsOnTheCircle.cpp
)

add_definitions(-D_knst)
set(WARNING_FLAGS "-pedantic -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wlogical-op -Wcast-qual -Wcast-align")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS} -std=c++11 -g")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D _GLIBCXX_DEBUG -fsanitize=address")

add_executable(points_solver ${SOURCE})
add_executable(points_original ${SOURCE_O})
