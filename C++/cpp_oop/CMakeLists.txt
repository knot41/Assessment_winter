cmake_minimum_required(VERSION 3.2)
project(oop)

include_directories(include)
aux_source_directory(src DIR_SRCS)
add_executable(oop ${DIR_SRCS})