cmake_minimum_required( VERSION 2.8.12 )

project( HelloWorld )

include_directories( ../../Components/LibraryLink/include )
add_library( HelloWorld SHARED HelloWorld.cpp )
