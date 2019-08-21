cmake_minimum_required( VERSION 2.8.12 )

project( NumberToString )

include_directories( ../../../Components/LibraryLink/include )
add_library( NumberToString SHARED NumberToString.cpp )
