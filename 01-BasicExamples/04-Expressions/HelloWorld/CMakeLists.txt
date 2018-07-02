cmake_minimum_required( VERSION 2.8.12 )

project( HelloWorld )

include_directories( ../../../Components/LibraryLink/include ../../../Components/WSTP/include )
link_directories( ../../../Components/WSTP/lib/Windows-x86-64 )
add_library( HelloWorld SHARED HelloWorld.cpp )
target_link_libraries( HelloWorld wstp64i4 )
