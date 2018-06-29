cmake_minimum_required( VERSION 2.8.12 )

project( ReverseString )

include_directories( ../../Components/LibraryLink/include )
add_library( ReverseString SHARED ReverseString.cpp )
