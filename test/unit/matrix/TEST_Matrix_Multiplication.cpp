/**
 * @file    TEST_Matrix_Multiplication.cpp
 * @author  Marvin Smith
 * @date    10/11/2023
 */
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/math/matrix.hpp>

namespace tmx = tmns::math;

/************************************************/
/*      Test Matrix/Matrix Multiplication       */
/************************************************/
TEST( Matrix_Matrix_Product, multiply_2_matrices )
{
    // Create 2 matrices
    tmx::Matrix<double,4,3> mat01( { 1, 2, 3, 4, 5, 6, 7,  8, 9, 10, 11, 12 } );
    tmx::Matrix<double,3,4> mat02( { 1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12 } );

    // Result
    auto mat03_act = mat01 * mat02;
    tmx::Matrix<double,4,4> mat03_exp( {  38,  44,  50, 56,
                                          83,  98, 113, 128,
                                         128, 152, 176, 200,
                                         173, 206, 239, 272 } );

    std::cout << mat03_exp.to_log_string( 4, 2 );
    std::cout << mat03_act.to_log_string( 4, 2 );

    ASSERT_EQ( mat03_act.cols(), mat03_exp.cols() );
    ASSERT_EQ( mat03_act.rows(), mat03_exp.rows() );
    for( size_t r = 0; r < mat03_act.rows(); r++ )
    for( size_t c = 0; c < mat03_act.cols(); c++ )
    {
        ASSERT_NEAR( mat03_act[r][c], mat03_exp[r][c], 0.1 );
    }
}
