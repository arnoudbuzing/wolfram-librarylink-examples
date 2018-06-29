cmake_minimum_required( VERSION 2.8.12 )

project( EchoRawArray )

include_directories( ../../../Components/LibraryLink/include )
add_library( EchoRawArray SHARED EchoRawArray.cpp )
