#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    7/12/2023

include_directories( ../include/terminus/math )

add_library( ${PROJECT_NAME} SHARED
                Quaternion.cpp )

target_include_directories( ${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

terminus_lib_configure( ${PROJECT_NAME} )
