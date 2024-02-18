cmake_minimum_required(VERSION 3.27)
project(mynginx C)

set(CMAKE_C_STANDARD 11)

add_executable(mynginx
        nginx.c)
