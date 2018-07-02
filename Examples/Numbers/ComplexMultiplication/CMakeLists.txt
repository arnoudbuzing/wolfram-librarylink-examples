cmake_minimum_required( VERSION 2.8.12 )

project( ComplexMultiplication )

include_directories( ../../../Components/LibraryLink/include )
add_library( ComplexMultiplication SHARED ComplexMultiplication.cpp )
