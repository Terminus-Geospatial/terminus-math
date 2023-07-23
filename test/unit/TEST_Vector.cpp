/**
 * @file    TEST_Vector.cpp
 * @author  Marvin Smith
 * @date    7/23/2023
*/
#include <gtest/gtest.h>

// Terminus Math Libraries
#include <terminus/math/Vector.hpp>

/************************************/
/*      Test Simple Operations      */
/************************************/
TEST( Vector, Simple_Operations )
{
    // Check the default constructor
    tmns::math::Vector3i v1;
    ASSERT_EQ( v1.x(), 0 );
    ASSERT_EQ( v1.y(), 0 );
    ASSERT_EQ( v1.z(), 0 );

    // Check the fill constructor
    auto v2 = tmns::math::Vector3i( 3 );
    ASSERT_EQ( v2.x(), 3 );
    ASSERT_EQ( v2.y(), 3 );
    ASSERT_EQ( v2.z(), 3 );
}