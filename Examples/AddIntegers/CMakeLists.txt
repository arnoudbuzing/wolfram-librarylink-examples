cmake_minimum_required( VERSION 2.8.12 )

project( AddIntegers )

include_directories( ../../Components/LibraryLink/include )
add_library( AddIntegers SHARED AddIntegers.cpp )
