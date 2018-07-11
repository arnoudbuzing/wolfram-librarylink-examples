cmake_minimum_required( VERSION 2.8.12 )

project( Addition )

include_directories( ../../../../Components/LibraryLink/include )
add_library( Addition SHARED Addition.cpp )
