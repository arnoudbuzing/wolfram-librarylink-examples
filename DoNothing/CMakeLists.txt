cmake_minimum_required( VERSION 2.8.12 )

project( DoNothing )

include_directories( ../LibraryLink/include )
add_library( DoNothing SHARED DoNothing.cpp )
