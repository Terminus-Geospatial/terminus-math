/**
 * @file    TEST_Matrix_Operations.cpp
 * @author  Marvin Smith
 * @date    10/12/2023
 */
#include <gtest/gtest.h>

#include <terminus/math/matrix/Matrix.hpp>
#include <terminus/math/matrix/Matrix_Operations.hpp>

namespace tmx = tmns::math;

/****************************************************/
/*          Test the Select Column Method           */
/****************************************************/
TEST( Matrix_Operations, select_col_test_01 )
{
    // Create some test matrices
    tmx::Matrix<double,4,3> mat01( {  1,  2,  3,
                                      4,  5,  6,
                                      7,  8,  9,
                                     10, 11, 12 } );
    tmx::Matrix<double,3,4> mat02( {  1,  2,  3,  4,
                                      5,  6,  7,  8,
                                      9, 10, 11, 12 } );

    // Verify picking a column works
    {
        auto col_check = tmx::select_col( mat01, 0 );
        ASSERT_EQ( col_check.size(), 4 );
        ASSERT_NEAR( col_check[0],  1, 0.001 );
        ASSERT_NEAR( col_check[1],  4, 0.001 );
        ASSERT_NEAR( col_check[2],  7, 0.001 );
        ASSERT_NEAR( col_check[3], 10, 0.001 );
        ASSERT_ANY_THROW( col_check[4] );
        ASSERT_ANY_THROW( col_check[30]  );
    }

    {
        auto col_check = tmx::select_col( mat01, 1 );
        ASSERT_EQ( col_check.size(), 4 );
        ASSERT_NEAR( col_check[0],  2, 0.001 );
        ASSERT_NEAR( col_check[1],  5, 0.001 );
        ASSERT_NEAR( col_check[2],  8, 0.001 );
        ASSERT_NEAR( col_check[3], 11, 0.001 );
        ASSERT_ANY_THROW( col_check[4] );
        ASSERT_ANY_THROW( col_check[30]  );
    }
    {
        auto col_check = tmx::select_col( mat01, 2 );
        ASSERT_EQ( col_check.size(), 4 );
        ASSERT_NEAR( col_check[0],  3, 0.001 );
        ASSERT_NEAR( col_check[1],  6, 0.001 );
        ASSERT_NEAR( col_check[2],  9, 0.001 );
        ASSERT_NEAR( col_check[3], 12, 0.001 );
        ASSERT_ANY_THROW( col_check[4] );
        ASSERT_ANY_THROW( col_check[30]  );
    }

    // This should fail
    {
        auto col_check = tmx::select_col( mat01, 3 );
        ASSERT_EQ( col_check.size(), 4 );
        ASSERT_ANY_THROW( col_check[0]  );
        ASSERT_ANY_THROW( col_check[1]  );
        ASSERT_ANY_THROW( col_check[2]  );
        ASSERT_ANY_THROW( col_check[3]  );
        ASSERT_ANY_THROW( col_check[4] );
        ASSERT_ANY_THROW( col_check[30]  );
    }

    // This should fail
    {
        auto col_check = tmx::select_col( mat01, 30 );
        ASSERT_ANY_THROW( col_check[0] );
    }

    // Check mat 2
    {
        auto col_check = tmx::select_col( mat02, 0 );
        ASSERT_EQ( col_check.size(), 3 );
        ASSERT_NEAR( col_check[0],  1, 0.001 );
        ASSERT_NEAR( col_check[1],  5, 0.001 );
        ASSERT_NEAR( col_check[2],  9, 0.001 );
        ASSERT_ANY_THROW( col_check[3] );
        ASSERT_ANY_THROW( col_check[30]  );
    }

    {
        auto col_check = tmx::select_col( mat02, 1 );
        ASSERT_EQ( col_check.size(), 3 );
        ASSERT_NEAR( col_check[0],  2, 0.001 );
        ASSERT_NEAR( col_check[1],  6, 0.001 );
        ASSERT_NEAR( col_check[2], 10, 0.001 );
        ASSERT_ANY_THROW( col_check[3] );
        ASSERT_ANY_THROW( col_check[30]  );
    }
    {
        auto col_check = tmx::select_col( mat02, 2 );
        ASSERT_EQ( col_check.size(), 3 );
        ASSERT_NEAR( col_check[0],  3, 0.001 );
        ASSERT_NEAR( col_check[1],  7, 0.001 );
        ASSERT_NEAR( col_check[2], 11, 0.001 );
        ASSERT_ANY_THROW( col_check[3] );
        ASSERT_ANY_THROW( col_check[30]  );
    }

    // This should fail
    {
        auto col_check = tmx::select_col( mat02, 4 );
        ASSERT_EQ( col_check.size(), 3 );
        ASSERT_ANY_THROW( col_check[0]  );
        ASSERT_ANY_THROW( col_check[1]  );
        ASSERT_ANY_THROW( col_check[2]  );
        ASSERT_ANY_THROW( col_check[3]  );
        ASSERT_ANY_THROW( col_check[30]  );
    }

    // This should fail
    {
        auto col_check = tmx::select_col( mat02, 30 );
        ASSERT_ANY_THROW( col_check[0] );
    }
}