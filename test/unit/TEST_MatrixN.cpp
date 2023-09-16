/**
 * @file    TEST_Matrix.cpp
 * @author  Marvin Smith
 * @date    9/16/2023
*/
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/math/MatrixN.hpp>

namespace tm = tmns::math;

/****************************************/
/*      Test the Matrix Constructor     */
/****************************************/
TEST( MatrixN, constructor_tests )
{
    // Test a 3x3 matrix constructor
    tm::MatrixN<double> mat_01( 3, 3 );
    ASSERT_EQ( mat_01.cols(), 3 );
    ASSERT_EQ( mat_01.rows(), 3 );

}