#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    7/12/2023
#

#  Configure GoogleTest
find_package( GTest REQUIRED )
include( GoogleTest )

include_directories( ${CMAKE_SOURCE_DIR}/include )

set( TEST ${PROJECT_NAME}_test )
add_executable( ${TEST}
    TEST_Matrix.cpp
    TEST_MatrixN.cpp
    TEST_Point.cpp
    TEST_Quaternion.cpp
    TEST_Rectangle.cpp
    TEST_Size.cpp
    TEST_Vector.cpp
    TEST_VectorN.cpp
)

target_link_libraries( ${TEST} PRIVATE
    GTest::gtest_main
    ${PROJECT_NAME}
)

gtest_discover_tests( ${TEST} )