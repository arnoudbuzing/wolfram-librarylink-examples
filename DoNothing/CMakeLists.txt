cmake_minimum_required( VERSION 3.11.4 )

project( DONOTHING )

include_directories( ../include )
link_directories( ../lib )
add_library( DoNothing SHARED DoNothing.cpp )
