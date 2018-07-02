cmake_minimum_required( VERSION 2.8.12 )

project( MatrixMultiplication )

include_directories( ../../../../Components/LibraryLink/include )
add_library( MatrixMultiplication SHARED MatrixMultiplication.cpp )
