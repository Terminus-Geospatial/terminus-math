/**
 * @file    TEST_Matrix.cpp
 * @author  Marvin Smith
 * @date    9/16/2023
*/
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/math/Matrix.hpp>

namespace tmx = tmns::math;

/****************************************/
/*      Test the Matrix Constructor     */
/****************************************/
TEST( Matrix, constructor_tests )
{
    // Test a 3x3 matrix constructor
    tmx::Matrix<double,3,3> mat_01;
    ASSERT_EQ( mat_01.cols(), 3 );
    ASSERT_EQ( mat_01.rows(), 3 );

}