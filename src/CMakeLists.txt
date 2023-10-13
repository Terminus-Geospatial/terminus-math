#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    7/12/2023

include_directories( ../include/terminus/math )

# Find Boost
set( Boost_USE_MULTITHREADED ON )
add_definitions( -DBOOST_ALL_DYN_LINK )
find_package( Boost REQUIRED )
#include_directories( ${Boost_INCLUDE_DIRS} )


add_library( ${PROJECT_NAME} SHARED
                Quaternion.cpp
                Quaternion_Utilities.cpp )

target_link_libraries( ${PROJECT_NAME} PUBLIC
    Boost::headers
    Boost::stacktrace
)

terminus_lib_configure( ${PROJECT_NAME} )
