cmake_minimum_required( VERSION 3.11.4 )

project( HELLOWORLD )

include_directories( ../LibraryLink/include )
link_directories( ../LibraryLink/lib/Windows-x86-64 )
add_library( HelloWorld SHARED HelloWorld.cpp )
target_link_libraries( HelloWorld WolframRTL )
