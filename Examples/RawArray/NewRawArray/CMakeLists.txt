cmake_minimum_required( VERSION 2.8.12 )

project( NewRawArray )

include_directories( ../../../Components/LibraryLink/include )
add_library( NewRawArray SHARED NewRawArray.cpp )
