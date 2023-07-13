/**
 * @file    TEST_Point.cpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/math/Point.hpp>

TEST( Point, Constructors )
{
    const double EPS = 0.001;

    // Point2d tests
    tmns::math::Point2d pt1;
    ASSERT_NEAR( pt1.x(), 0, EPS );
    ASSERT_NEAR( pt1.y(), 0, EPS );
    ASSERT_ANY_THROW( pt1.z(); );

}