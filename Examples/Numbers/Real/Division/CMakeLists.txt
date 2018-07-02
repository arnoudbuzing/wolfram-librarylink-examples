cmake_minimum_required( VERSION 2.8.12 )

project( Division )

include_directories( ../../../../Components/LibraryLink/include )
add_library( Division SHARED Division.cpp )
