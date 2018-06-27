cmake_minimum_required( VERSION 2.8.12 )

project( DONOTHING )

include_directories( ../LibraryLink/include )
# link_directories( ../LibraryLink/lib/Linux-x86-64 )
add_library( DoNothing SHARED DoNothing.cpp )
# target_link_libraries( DoNothing WolframRTL )
