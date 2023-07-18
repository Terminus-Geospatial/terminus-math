/**
 * @file    TEST_Rectangle.cpp
 * @author  Marvin Smith
 * @date    7/14/2023
*/
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/math/Rectangle.hpp>

/********************************************************/
/*          Test the Constructors and Accessors         */
/********************************************************/
TEST( Rectangle, Constructors_and_Getters )
{
    // Create a rectangle and check values
    tmns::math::Rectangle<double> rect1;
    ASSERT_NEAR( rect1.bl().x(), 0, 0.0001 );
    ASSERT_NEAR( rect1.bl().y(), 0, 0.0001 );
    ASSERT_NEAR( rect1.width(),  0, 0.0001 );
    ASSERT_NEAR( rect1.height(), 0, 0.0001 );
    ASSERT_NEAR( rect1.min().x(), 0, 0.0001 );
    ASSERT_NEAR( rect1.min().y(), 0, 0.0001 );

    tmns::math::Rectangle<double> rect2( 1, 2, 3, 4);
    ASSERT_NEAR( rect2.bl().x(), 1, 0.0001 );
    ASSERT_NEAR( rect2.bl().y(), 2, 0.0001 );
    ASSERT_NEAR( rect2.width(),  3, 0.0001 );
    ASSERT_NEAR( rect2.height(), 4, 0.0001 );
    ASSERT_NEAR( rect2.min().x(), 1, 0.0001 );
    ASSERT_NEAR( rect2.min().y(), 2, 0.0001 );

    tmns::math::Rectangle<double> rect3( tmns::math::ToPoint2<double>( 1, 2 ), 3, 4);
    ASSERT_NEAR( rect3.bl().x(), 1, 0.0001 );
    ASSERT_NEAR( rect3.bl().y(), 2, 0.0001 );
    ASSERT_NEAR( rect3.width(),  3, 0.0001 );
    ASSERT_NEAR( rect3.height(), 4, 0.0001 );

    tmns::math::Rectangle<double> rect4( tmns::math::ToPoint2<double>(  1, -2 ),
                                         tmns::math::ToPoint2<double>( -3,  4 ) );
    ASSERT_NEAR( rect4.bl().x(), -3, 0.0001 );
    ASSERT_NEAR( rect4.bl().y(), -2, 0.0001 );
    ASSERT_NEAR( rect4.br().x(),  1, 0.0001 );
    ASSERT_NEAR( rect4.br().y(), -2, 0.0001 );
    ASSERT_NEAR( rect4.tr().x(),  1, 0.0001 );
    ASSERT_NEAR( rect4.tr().y(),  4, 0.0001 );
    ASSERT_NEAR( rect4.tl().x(), -3, 0.0001 );
    ASSERT_NEAR( rect4.tl().y(),  4, 0.0001 );
    ASSERT_NEAR( rect4.width(),   4, 0.0001 );
    ASSERT_NEAR( rect4.height(),  6, 0.0001 );
    ASSERT_NEAR( rect4.min().x(), -3, 0.0001 );
    ASSERT_NEAR( rect4.min().y(), -2, 0.0001 );
}

/****************************************************/
/*      Check if point is inside rectangle          */
/****************************************************/
TEST( Rectangle, is_inside_point )
{
    // Create a big rectangle
    tmns::math::Rectangle<int> test_rect01( -5, -4, 10, 12 );
    ASSERT_TRUE(  test_rect01.is_inside( tmns::math::ToPoint2<double>( 0, 0 ) ) );
    ASSERT_TRUE(  test_rect01.is_inside( tmns::math::ToPoint2<double>(-5,-4 ) ) );
    ASSERT_TRUE(  test_rect01.is_inside( tmns::math::ToPoint2<double>( 5, 6 ) ) );
    ASSERT_FALSE( test_rect01.is_inside( tmns::math::ToPoint2<double>(-6, 0 ) ) );
}

/********************************************************/
/*          Check if rectangle is inside rectangle      */
/********************************************************/
TEST( Rectangle, is_inside_rectangle )
{
    // Create a big rectangle
    tmns::math::Rectangle<int> test_rect01( -5, -4, 10, 12 );

    // Valid cases
    ASSERT_TRUE( test_rect01.is_inside( tmns::math::Rect2d( -1, -1, 1, 1 ) ) );
    ASSERT_TRUE( test_rect01.is_inside( test_rect01 ) );

    // Invalid cases
    ASSERT_FALSE( test_rect01.is_inside( tmns::math::Rect2f( -6, -4, 1, 1 ) ) );
}
