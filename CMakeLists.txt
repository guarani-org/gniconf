﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("gniconf")

# Include sub-projects.
add_subdirectory ("gniconf")
add_subdirectory ("pugixml")

 
enable_testing()

