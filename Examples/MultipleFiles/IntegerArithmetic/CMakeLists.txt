cmake_minimum_required( VERSION 2.8.12 )

project( IntegerArithmetic )

include_directories( ../../../Components/LibraryLink/include )
add_library( IntegerArithmetic SHARED Initialize.cpp Add.cpp Multiply.cpp )
