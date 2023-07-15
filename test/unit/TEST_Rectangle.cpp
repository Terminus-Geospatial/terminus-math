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

    tmns::math::Rectangle<double> rect2( 1, 2, 3, 4);
    ASSERT_NEAR( rect2.bl().x(), 1, 0.0001 );
    ASSERT_NEAR( rect2.bl().y(), 2, 0.0001 );
    ASSERT_NEAR( rect2.width(),  3, 0.0001 );
    ASSERT_NEAR( rect2.height(), 4, 0.0001 );

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
}