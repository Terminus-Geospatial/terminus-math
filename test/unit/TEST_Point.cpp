/**
 * @file    TEST_Point.cpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/math/Point.hpp>
#include <terminus/math/Point_Utilities.hpp>

/****************************************/
/*          Test the Constructors       */
/****************************************/
TEST( Point, Constructors )
{
    const double EPS = 0.001;

    // Point2d tests
    tmns::math::Point2d pt1;
    ASSERT_NEAR( pt1.x(), 0, EPS );
    ASSERT_NEAR( pt1.y(), 0, EPS );
    ASSERT_ANY_THROW( pt1.z(); );

}

/************************************************/
/*          Test the Addition Operator          */
/************************************************/
TEST( Point, Addition_Operator )
{
    auto pt1 = tmns::math::ToPoint2<double>( 3, -5 );
    auto pt2 = tmns::math::ToPoint2<double>( 7, 8 );
    auto pt3 = pt1 + pt2;

    ASSERT_NEAR( pt3.x(), 10, 0.001 );
    ASSERT_NEAR( pt3.y(),  3, 0.001 );


    auto pt4 = tmns::math::ToPoint3<double>( 3, -5, 5);
    auto pt5 = tmns::math::ToPoint3<double>( 7, 8, -5 );
    auto pt6 = pt4 + pt5;

    ASSERT_NEAR( pt6.x(), 10, 0.001 );
    ASSERT_NEAR( pt6.y(),  3, 0.001 );
    ASSERT_NEAR( pt6.z(),  0, 0.001 );

}

/***************************************************/
/*          Test the Subtraction Operator          */
/***************************************************/
TEST( Point, Subtraction_Operator )
{
    auto pt1 = tmns::math::ToPoint2<double>( 3, -5 );
    auto pt2 = tmns::math::ToPoint2<double>( 7, 8 );
    auto pt3 = pt1 - pt2;

    ASSERT_NEAR( pt3.x(), -4, 0.001 );
    ASSERT_NEAR( pt3.y(),-13, 0.001 );


    auto pt4 = tmns::math::ToPoint3<double>( 3, -5, 5);
    auto pt5 = tmns::math::ToPoint3<double>( 7, 8, -5 );
    auto pt6 = pt4 - pt5;

    ASSERT_NEAR( pt6.x(), -4, 0.001 );
    ASSERT_NEAR( pt6.y(),-13, 0.001 );
    ASSERT_NEAR( pt6.z(), 10, 0.001 );

}
