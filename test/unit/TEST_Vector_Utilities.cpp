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