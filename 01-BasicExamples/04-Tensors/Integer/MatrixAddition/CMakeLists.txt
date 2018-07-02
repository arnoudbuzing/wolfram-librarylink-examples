cmake_minimum_required( VERSION 2.8.12 )

project( MatrixAddition )

include_directories( ../../../../Components/LibraryLink/include )
add_library( MatrixAddition SHARED MatrixAddition.cpp )
