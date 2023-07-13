#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    7/12/2023

include_directories( ../include/terminus/math )
add_library( ${PROJECT_NAME}
                Quaternion.cpp )
