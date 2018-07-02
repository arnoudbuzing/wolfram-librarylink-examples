cmake_minimum_required( VERSION 2.8.12 )

project( Objects )

include_directories( ../../Components/LibraryLink/include )
add_library( Objects SHARED Objects.cpp Rectangle.cpp Rectangle.h )
