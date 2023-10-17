/**
 * @file    TEST_Quaternion.cpp
 * @author  Marvin Smith
 * @date    9/15/2023
 */
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/math/Quaternion.hpp>

/************************************************/
/*      Test the Quaternion Constructors        */
/************************************************/
TEST( Quaternion, Constructors )
{
    tmns::math::Quaternion q1;
    ASSERT_NEAR( q1.real(),     0, 0.001 );
    ASSERT_NEAR( q1.imag().x(), 1, 0.001 );
    ASSERT_NEAR( q1.imag().y(), 0, 0.001 );
    ASSERT_NEAR( q1.imag().z(), 0, 0.001 );

}
