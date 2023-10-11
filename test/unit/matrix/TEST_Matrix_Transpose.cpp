/**
 * @file    TEST_Matrix_Transpose.cpp
 * @author  Marvin Smith
 * @date    10/10/2023
 */
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/math/matrix.hpp>

// C++ Libraries
#include <numeric>
#include <ranges>

namespace tmx = tmns::math;

/************************************************/
/*          Test the Standard Transpose         */
/************************************************/
TEST( Matrix_Transpose, transpose )
{
    // Create matrix
    std::array<double,12> data;
    std::iota( data.begin(), data.end(), 0 );

    std::array<double,12> trans_data { 0, 4, 8, 1, 5, 9, 2, 6, 10, 3, 7, 11 };

    tmx::Matrix<double,3,4> test_mat_01( data );

    // Verify non transpose shape
    size_t counter = 0;
    for( int r = 0; r < test_mat_01.rows(); r++ )
    for( int c = 0; c < test_mat_01.cols(); c++ )
    {
        ASSERT_NEAR( test_mat_01[r][c], data[counter++], 0.001 );
    }

    // Verify transpose
    counter = 0;
    auto mat_trans_01 = tmx::transpose( test_mat_01 );
    ASSERT_EQ( mat_trans_01.rows(), 4 );
    ASSERT_EQ( mat_trans_01.cols(), 3 );
    for( int r = 0; r < mat_trans_01.rows(); r++ )
    for( int c = 0; c < mat_trans_01.cols(); c++ )
    {
        ASSERT_NEAR( mat_trans_01[r][c], trans_data[counter++], 0.001 );
    }

}