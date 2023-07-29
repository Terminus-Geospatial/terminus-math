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

/************************************/
/*      Getter Reference Test       */
/************************************/
TEST( Rectangle, Getter_Setter_References )
{
    // Create a rectangle
    tmns::math::Rectangle<int> rect1;

    rect1.min().x() = 3;
    rect1.min().y() = 4;
    rect1.width() = 5;
    rect1.height() = 6;

    ASSERT_EQ( rect1.bl().x(), 3 );
    ASSERT_EQ( rect1.bl().y(), 4 );
    ASSERT_EQ( rect1.tr().x(), 8 );
    ASSERT_EQ( rect1.tr().y(), 10 );
}

/************************************/
/*          Set Min/Max             */
/************************************/
TEST( Rectangle, min_max_ops )
{
    // Create Rectangle
    const tmns::math::Rectangle<int> test_rect01( 1, 2, 3, 4 );

    // Set a new max (beyond the rectangle)
    auto test_rect02 = test_rect01;
    test_rect02.set_max( tmns::math::ToPoint2<size_t>( 9, 8 ) );
    ASSERT_EQ( test_rect02.min().x(), 1 );
    ASSERT_EQ( test_rect02.min().y(), 2 );
    ASSERT_EQ( test_rect02.max().x(), 9 );
    ASSERT_EQ( test_rect02.max().y(), 8 );

    // Set a new max (inside the rectangle)
    auto test_rect03 = test_rect01;
    test_rect03.set_max( tmns::math::ToPoint2<double>( 3, 3 ) );
    ASSERT_EQ( test_rect03.min().x(), 1 );
    ASSERT_EQ( test_rect03.min().y(), 2 );
    ASSERT_EQ( test_rect03.max().x(), 3 );
    ASSERT_EQ( test_rect03.max().y(), 3 );
}

/****************************************************/
/*          Addition and Subtraction Operators      */
/****************************************************/
TEST( Rectangle, Addition_Subtraction_Operators )
{
    // Create Rectangle
    tmns::math::Rectangle<double> r1( 0, 0, 10, 20 );
    auto r2 = r1 + tmns::math::ToPoint2<double>( 7, 3 );
    ASSERT_NEAR( r2.bl().x(), 7, 0.0001 );
    ASSERT_NEAR( r2.bl().y(), 3, 0.0001 );
    ASSERT_NEAR( r2.width(),  10, 0.001 );
    ASSERT_NEAR( r2.height(), 20, 0.001 );

    auto r3 = r1 - tmns::math::ToPoint2<double>( 7, 3 );
    ASSERT_NEAR( r3.bl().x(),-7, 0.0001 );
    ASSERT_NEAR( r3.bl().y(),-3, 0.0001 );
    ASSERT_NEAR( r3.width(),  10, 0.001 );
    ASSERT_NEAR( r3.height(), 20, 0.001 );


    // Test with vectors
    auto r4 = r1 + tmns::math::ToVector2<double>( 7, 3 );
    ASSERT_NEAR( r4.bl().x(), 7, 0.0001 );
    ASSERT_NEAR( r4.bl().y(), 3, 0.0001 );
    ASSERT_NEAR( r4.width(),  10, 0.001 );
    ASSERT_NEAR( r4.height(), 20, 0.001 );

    auto r5 = r1 - tmns::math::ToVector2<double>( 7, 3 );
    ASSERT_NEAR( r5.bl().x(),-7, 0.0001 );
    ASSERT_NEAR( r5.bl().y(),-3, 0.0001 );
    ASSERT_NEAR( r5.width(),  10, 0.001 );
    ASSERT_NEAR( r5.height(), 20, 0.001 );

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

/********************************************/
/*      Test the Intersection Function      */
/********************************************/
TEST( Rectangle, intersection )
{
    // Create 2 rectangles
    tmns::math::Rect2d rect1( tmns::math::ToPoint2<double>(-1, 1 ),
                              tmns::math::ToPoint2<double>( 3, 3 ) );
    tmns::math::Rect2d rect2( tmns::math::ToPoint2<double>( 1, 0 ),
                              tmns::math::ToPoint2<double>( 4, 2 ) );

    // Intersection should be [[1, 1], [3, 2]]
    auto res_1 = tmns::math::Rect2d::intersection( rect1, rect2 );
    ASSERT_NEAR( res_1.min().x(), 1, 0.0001 );
    ASSERT_NEAR( res_1.min().y(), 1, 0.0001 );
    ASSERT_NEAR( res_1.max().x(), 3, 0.0001 );
    ASSERT_NEAR( res_1.max().y(), 2, 0.0001 );
}

/*******************************************************/
/*      Expand the Rectangle to grab the coordinate    */
/*******************************************************/
TEST( Rectangle, set_union )
{
    // Create 2 rectangles
    tmns::math::Rect2d rect_01( -1, -1, 2, 2 );
    tmns::math::Rect2d rect_02( 3, 3, 4, 5 );

    // Test 1 - 2 rectangle union
    auto res_1 = tmns::math::Rect2i::set_union( rect_01,
                                                rect_02 );

    ASSERT_NEAR( res_1.bl().x(), -1, 0.001 );
    ASSERT_NEAR( res_1.bl().y(), -1, 0.001 );
    ASSERT_NEAR( res_1.tr().x(),  7, 0.001 );
    ASSERT_NEAR( res_1.tr().y(),  8, 0.001 );

    // Test 2 - 1 rectangle and a point
    auto point_01 = tmns::math::ToPoint2<double>( 9, -1 );
    auto res_2 = tmns::math::Rect2i::set_union( rect_01,
                                                point_01 );

    ASSERT_NEAR( res_2.bl().x(), -1, 0.001 );
    ASSERT_NEAR( res_2.bl().y(), -1, 0.001 );
    ASSERT_NEAR( res_2.tr().x(),  9, 0.001 );
    ASSERT_NEAR( res_2.tr().y(),  1, 0.001 );
}