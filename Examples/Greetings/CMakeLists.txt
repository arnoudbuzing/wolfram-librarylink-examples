cmake_minimum_required( VERSION 2.8.12 )

project( Greetings )

include_directories( ../LibraryLink/include )
add_library( Greetings SHARED Greetings.cpp )
