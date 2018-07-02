cmake_minimum_required( VERSION 2.8.12 )

project( AddRawArrays )

include_directories( ../../../Components/LibraryLink/include )
add_library( AddRawArrays SHARED AddRawArrays.cpp )
