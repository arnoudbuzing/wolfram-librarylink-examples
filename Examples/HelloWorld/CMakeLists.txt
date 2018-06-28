cmake_minimum_required( VERSION 2.8.12 )

project( HelloWorld )

# Set the platform variable
if(WIN32)
	set( PLATFORM "Windows-x86-64" )
elseif( APPLE )
	set( PLATFORM "MacOSX-x86-64" )
else( UNIX AND NOT APPLE )
	set( PLATFORM "Linux-x86-64" )
endif()

message( "PLATFORM: ${PLATFORM}" )

include_directories( ../LibraryLink/include )
link_directories( ../LibraryLink/lib/${PLATFORM} )
add_library( HelloWorld SHARED HelloWorld.cpp )
# target_link_libraries( HelloWorld WolframRTL )
