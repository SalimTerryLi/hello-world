cmake_minimum_required(VERSION 2.8)
project(test)
add_executable(test0 "equation.c")

link_libraries(m)
add_executable(test1 "equation1.c")
