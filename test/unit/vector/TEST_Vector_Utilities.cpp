/**
 * @file    TEST_Vector_Utilities.cpp
 * @author  Marvin Smith
 * @date    7/23/2023
*/
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/math/Vector_Utilities.hpp>

/********************************************/
/*          Check To Vector Methods         */
/********************************************/
TEST( Vector_Utilities, ToVector_Methods )
{
    auto vec1 = tmns::math::ToVector2<double>( 0, 1 );
    ASSERT_NEAR( vec1.x(), 0, 0.0001 );
    ASSERT_NEAR( vec1.y(), 1, 0.0001 );

    auto vec2 = tmns::math::ToVector3<double>( 0, 1, -2);
    ASSERT_NEAR( vec2.x(), 0, 0.0001 );
    ASSERT_NEAR( vec2.y(), 1, 0.0001 );
    ASSERT_NEAR( vec2.z(),-2, 0.0001 );
}

/****************************************************/
/*      Test Vector / Scalar Multiplication         */
/****************************************************/
TEST( Vector_Utilities, vector_scalar_multiplication )
{
    //  Create test inputs
    tmns::math::Vector3d vec_01 ( { -1, 2.1, 0.5 } );
    double scalar_01 = 3;

    // Test Scalar x Vector
    auto res_01 = vec_01 * scalar_01;
    ASSERT_NEAR( res_01.x(), -3, 0.001 );
    ASSERT_NEAR( res_01.y(), 6.3, 0.001 );
    ASSERT_NEAR( res_01.z(), 1.5, 0.001 );

    // Test Vector x Scalar
    auto res_02 = scalar_01 * vec_01;
    ASSERT_NEAR( res_02.x(), -3, 0.001 );
    ASSERT_NEAR( res_02.y(), 6.3, 0.001 );
    ASSERT_NEAR( res_02.z(), 1.5, 0.001 );
}

/****************************************************/
/*      Test Vector / Scalar Division         */
/****************************************************/
TEST( Vector_Utilities, vector_scalar_division )
{
    //  Create test inputs
    tmns::math::Vector3d vec_01 ( { -1, 2.2, 0.8 } );
    double scalar_01 = 2;

    // Test Scalar x Vector
    auto res_01 = vec_01 / scalar_01;
    ASSERT_NEAR( res_01.x(), -0.5, 0.001 );
    ASSERT_NEAR( res_01.y(), 1.1, 0.001 );
    ASSERT_NEAR( res_01.z(), 0.4, 0.001 );
}
