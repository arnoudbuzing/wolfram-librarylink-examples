cmake_minimum_required( VERSION 2.8.12 )

project( StringToNumber )

include_directories( ../../../Components/LibraryLink/include )
add_library( StringToNumber SHARED StringToNumber.cpp )
