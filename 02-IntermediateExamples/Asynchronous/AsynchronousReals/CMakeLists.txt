cmake_minimum_required( VERSION 2.8.12 )

project( AsynchronousReals )

include_directories( ../../../Components/LibraryLink/include )
add_library( AsynchronousReals SHARED AsynchronousReals.cpp )
