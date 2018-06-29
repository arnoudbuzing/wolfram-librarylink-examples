cmake_minimum_required( VERSION 2.8.12 )

project( Squared )

include_directories( ../../Components/LibraryLink/include )
add_library( Squared SHARED Squared.cpp )
