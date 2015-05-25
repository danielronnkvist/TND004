cmake_minimum_required (VERSION 2.6)
project (lab4)
set (CMAKE_CXX_FLAGS "-std=c++0x -stdlib=libc++ -g3 -Wall -O0")
add_executable(lab4
  main.cpp
  digraph.cpp digraph.h
  list.cpp list.h
  queue.h)
