/**
 * @file    TEST_VectorN.cpp
 * @author  Marvin Smith
 * @date    7/30/2023
*/
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/math/vector/VectorN.hpp>

/***************************************************/
/*      Test Constructors, Getters, and Setters    */
/***************************************************/
TEST( VectorN, simple_operations )
{
    // Create a vector
    tmns::math::VectorN<double> vec01( { 0, 1, 2, 3 } );

    ASSERT_EQ( vec01.size(), 4 );

    // Set a specific value
    ASSERT_NEAR( vec01[2], 2, 0.001 );
    vec01[2] = -1;
    ASSERT_NEAR( vec01[2], -1, 0.001 );

    ASSERT_NEAR( vec01.x(), 0, 0.001 );
    ASSERT_NEAR( vec01.y(), 1, 0.001 );
    ASSERT_NEAR( vec01.z(),-1, 0.001 );

    // Test 2nd constructor
    tmns::math::Vector4_<double> vec_temp( { 0, 1, 2, 3 } );
    tmns::math::VectorN<double> vec02( vec_temp );

    ASSERT_NEAR( vec02.x(), 0, 0.001 );
    ASSERT_NEAR( vec02.y(), 1, 0.001 );
    ASSERT_NEAR( vec02.z(), 2, 0.001 );
    ASSERT_NEAR( vec02[3],  3, 0.001 );
    
}