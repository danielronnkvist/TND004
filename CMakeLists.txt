cmake_minimum_required (VERSION 2.6)
project (lab4b)
set (CMAKE_CXX_FLAGS "-std=c++0x -stdlib=libc++ -g3 -Wall -O0")
add_executable(lab4b
  main.cpp
  edge.cpp edge.h
  list.cpp list.h
  dsets.cpp dsets.h
  graph.cpp graph.h
  heap.h)
