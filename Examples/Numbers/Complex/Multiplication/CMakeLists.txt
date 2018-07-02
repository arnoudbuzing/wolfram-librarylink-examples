cmake_minimum_required( VERSION 2.8.12 )

project( Multiplication )

include_directories( ../../../../Components/LibraryLink/include )
add_library( Multiplication SHARED Multiplication.cpp )
