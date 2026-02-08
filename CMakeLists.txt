cmake_minimum_required(VERSION 3.20)

project(unlock-saa2)

set(CMAKE_SHARED_LIBRARY_PREFIX "../")
set(CMAKE_SHARED_LIBRARY_SUFFIX ".asi")

add_library(unlock-saa2 SHARED main.cpp)

set_target_properties(unlock-saa2 PROPERTIES
		CXX_STANDARD 23
		CXX_STANDARD_REQUIRED ON
		CXX_EXTENSIONS ON
)