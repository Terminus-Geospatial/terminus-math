/**
 * @file    Matrix_Operations.hpp
 * @author  Marvin Smith
 * @date    9/16/2023
 */
#pragma once

// Terminus Libraries
#include "../types/Functors.hpp"
#include "../types/Math_Functors.hpp"
#include "../vector/Vector_Transpose.hpp"
#include "Matrix_Col.hpp"
#include "Matrix_Functors.hpp"
#include "Matrix_Vector_Product.hpp"

// C++ Libraries
#include <type_traits>

namespace tmns::math {

/**
 * Extract a column of a matrix as a vector.
 */
template <typename MatrixT>
Matrix_Col<MatrixT> select_col( Matrix_Base<MatrixT>& matrix,
                                size_t                col )
{
    return Matrix_Col<MatrixT>( matrix.impl(), col );
}

/**
 * Extract a column of a matrix as a vector (const overload).
 */
template <typename MatrixT>
Matrix_Col<const MatrixT> select_col( const Matrix_Base<MatrixT>& matrix,
                                      size_t                      col )
{
    return Matrix_Col<const MatrixT>( matrix.impl(), col );
}

/**
 * Extract a row of a matrix as a vector.
 */
template <typename MatrixT>
Matrix_Row<MatrixT> select_row( Matrix_Base<MatrixT>& matrix,
                                size_t                row )
{
    return Matrix_Row<MatrixT>( matrix.impl(), row );
}

/**
 * Extract a row of a matrix as a vector (const overload).
 */
template <typename MatrixT>
Matrix_Row<const MatrixT> select_row( const Matrix_Base<MatrixT>& matrix,
                                      size_t                      row )
{
    return Matrix_Row<const MatrixT>( matrix.impl(), row );
}

/**
 * Negate a matrix.
 */
template <typename MatrixT>
Matrix_Unary_Functor<MatrixT, Arg_Negation_Functor>
    operator - ( const Matrix_Base<MatrixT>& m )
{
    return Matrix_Unary_Functor<MatrixT, Arg_Negation_Functor>( m.impl() );
}

/**
 * Absolute of a matrix
 */
template <typename MatrixT>
Matrix_Unary_Functor<MatrixT, Arg_Abs_Functor>
   abs( const Matrix_Base<MatrixT>& m )
{
    return Matrix_Unary_Functor<MatrixT, Arg_Abs_Functor>( m.impl() );
}

/**
 * Elementwise sum of two matrices.
 */
template <typename Matrix1T,
          typename Matrix2T>
Matrix_Binary_Functor<Matrix1T, Matrix2T, Arg_Arg_Sum_Functor>
    elem_sum( const Matrix_Base<Matrix1T>& m1,
              const Matrix_Base<Matrix2T>& m2 )
{
    return Matrix_Binary_Functor<Matrix1T, Matrix2T, Arg_Arg_Sum_Functor>( m1.impl(), m2.impl() );
}

/**
 * Sum of a matrix and a matrix (same as elem_sum).
 */
template <typename Matrix1T,
          typename Matrix2T>
Matrix_Binary_Functor<Matrix1T, Matrix2T, Arg_Arg_Sum_Functor>
    operator + ( const Matrix_Base<Matrix1T>& m1,
                 const Matrix_Base<Matrix2T>& m2 )
{
    return elem_sum( m1, m2 );
}

/**
 * Elementwise sum of a scalar and a matrix.
 */
template <typename ScalarT,
          typename MatrixT>
Matrix_Unary_Functor<MatrixT,Val_Arg_Sum_Functor<ScalarT>>
    elem_sum( ScalarT                     s, 
              const Matrix_Base<MatrixT>& m ) requires Is_Scalar<ScalarT>::type
{
    return Matrix_Unary_Functor<MatrixT, Val_Arg_Sum_Functor<ScalarT> >( m.impl(), s );
}

/**
 * Elementwise sum of a matrix and a scalar.
 */
template <typename MatrixT,
          typename ScalarT>
Matrix_Unary_Functor<MatrixT, Arg_Val_Sum_Functor<ScalarT>>
    elem_sum( const Matrix_Base<MatrixT>& m,
              ScalarT                     s ) requires Is_Scalar<ScalarT>::type
{
    return Matrix_Unary_Functor<MatrixT, Arg_Val_Sum_Functor<ScalarT> >( m.impl(), s );
}

/**
 * Elementwise difference of two matrices.
 */
template <typename Matrix1T,
          typename Matrix2T>
Matrix_Binary_Functor<Matrix1T, Matrix2T, Arg_Arg_Difference_Functor>
    elem_diff( const Matrix_Base<Matrix1T>& m1,
               const Matrix_Base<Matrix2T>& m2 )
{
    return Matrix_Binary_Functor<Matrix1T, Matrix2T, Arg_Arg_Difference_Functor>( m1.impl(), m2.impl() );
}

/**
 * Difference of two matrices (same as elem_diff).
 */
template <typename Matrix1T,
          typename Matrix2T>
Matrix_Binary_Functor<Matrix1T, Matrix2T, Arg_Arg_Difference_Functor>
    operator - ( const Matrix_Base<Matrix1T>& m1,
                 const Matrix_Base<Matrix2T>& m2 )
{
    return elem_diff( m1, m2 );
}

/**
 * Elementwise difference of a scalar and a matrix.
 */
template <typename ScalarT,
          typename MatrixT>
Matrix_Unary_Functor<MatrixT, Val_Arg_Difference_Functor<ScalarT>>
    elem_diff( ScalarT                     s,
               const Matrix_Base<MatrixT>& m ) requires Is_Scalar<ScalarT>::type
{
    return Matrix_Unary_Functor<MatrixT, Val_Arg_Difference_Functor<ScalarT> >( m.impl(), s );
}

/**
 * Elementwise difference of a matrix and a scalar.
 */
template <typename ScalarT,
          typename MatrixT>
Matrix_Unary_Functor<MatrixT, Arg_Val_Difference_Functor<ScalarT>>
    elem_diff( const Matrix_Base<MatrixT>& m,
               ScalarT                     s ) requires Is_Scalar<ScalarT>::type
{
    return Matrix_Unary_Functor<MatrixT, Arg_Val_Difference_Functor<ScalarT> >( m.impl(), s );
}

/**
 * Elementwise product of two matrices.
 */
template <typename Matrix1T,
          typename Matrix2T>
Matrix_Binary_Functor<Matrix1T, Matrix2T, Arg_Arg_Product_Functor>
   elem_prod( const Matrix_Base<Matrix1T>& m1,
              const Matrix_Base<Matrix2T>& m2 )
{
    return Matrix_Binary_Functor<Matrix1T, Matrix2T, Arg_Arg_Product_Functor>( m1.impl(), m2.impl() );
}

/**
 * Elementwise product of a scalar and a matrix.
 */
template <typename ScalarT,
          typename MatrixT>
Matrix_Unary_Functor<MatrixT,Val_Arg_Product_Functor<ScalarT>>
    elem_prod( ScalarT                     s,
               const Matrix_Base<MatrixT>& m ) requires Is_Scalar<ScalarT>::type
{
    return Matrix_Unary_Functor<MatrixT, Val_Arg_Product_Functor<ScalarT> >( m.impl(), s );
}

/**
 * Product of a scalar and a matrix (same as elem_prod)
 */
template <typename ScalarT,
          typename MatrixT>
std::enable_if_t<Is_Scalar<ScalarT>::type,
                 Matrix_Unary_Functor<MatrixT, Val_Arg_Product_Functor<ScalarT>>>
    operator * ( ScalarT                    s,
                 const Matrix_Base<MatrixT>& m )
{
    return elem_prod( s, m );
}

/**
 * Elementwise product of a matrix and a scalar.
 */
template <typename ScalarT,
          typename MatrixT>
std::enable_if_t<Is_Scalar<ScalarT>::type,
                 Matrix_Unary_Functor<MatrixT, Arg_Val_Product_Functor<ScalarT>>>
    elem_prod( const Matrix_Base<MatrixT>& m,
               ScalarT                     s )
{
    return Matrix_Unary_Functor<MatrixT, Arg_Val_Product_Functor<ScalarT> >( m.impl(), s );
}

/**
 * Product of a matrix and a scalar (same as elem_prod).
 */
template <typename ScalarT,
          typename MatrixT>
std::enable_if_t<Is_Scalar<ScalarT>::type,
                 Matrix_Unary_Functor<MatrixT, Arg_Val_Product_Functor<ScalarT>>>
    operator * ( const Matrix_Base<MatrixT>& m,
                 ScalarT                     s )
{
    return elem_prod( m, s );
}


/**
 * Elementwise quotient of two matrices.
 */
template <typename Matrix1T,
          typename Matrix2T>
Matrix_Binary_Functor<Matrix1T, Matrix2T, Arg_Arg_Quotient_Functor>
   elem_quot( const Matrix_Base<Matrix1T>& m1,
              const Matrix_Base<Matrix2T>& m2 )
{
    return Matrix_Binary_Functor<Matrix1T,Matrix2T,Arg_Arg_Quotient_Functor>( m1.impl(), m2.impl() );
}

/**
 * Elementwise quotient of a scalar and a matrix
 */
template <typename ScalarT,
          typename MatrixT>
Matrix_Unary_Functor<MatrixT, Val_Arg_Quotient_Functor<ScalarT>>
   elem_quot( ScalarT                     s,
              const Matrix_Base<MatrixT>& m ) requires Is_Scalar<ScalarT>::type
{
    return Matrix_Unary_Functor<MatrixT, Val_Arg_Quotient_Functor<ScalarT> >( m.impl(), s );
}

/**
 * Elementwise quotient of a matrix and a scalar.
 */
template <typename ScalarT,
          typename MatrixT>
Matrix_Unary_Functor<MatrixT, Arg_Val_Quotient_Functor<ScalarT>>
    elem_quot( const Matrix_Base<MatrixT>& m,
               ScalarT                     s ) requires Is_Scalar<ScalarT>::type
{
    return Matrix_Unary_Functor<MatrixT, Arg_Val_Quotient_Functor<ScalarT>>( m.impl(), s );
}

/**
 * Quotient of a matrix and a scalar (same as elem_quot).
 */
template <typename ScalarT,
          typename MatrixT>
Matrix_Unary_Functor<MatrixT, Arg_Val_Quotient_Functor<ScalarT>>
    operator / ( const Matrix_Base<MatrixT>& m, ScalarT s ) requires Is_Scalar<ScalarT>::type
{
    return elem_quot( m, s );
}

/**
 * Product of a matrix and a vector
 */
template <typename MatrixT,
          typename VectorT>
Matrix_Vector_Product<MatrixT,VectorT,false>
    operator * ( const Matrix_Base<MatrixT>& m,
                 const Vector_Base<VectorT>& v )
{
    return Matrix_Vector_Product<MatrixT,VectorT,false>( m.impl(), v.impl() );
}

/**
 * Product of a transposed matrix and a vector
 */
template <typename MatrixT,
          typename VectorT>
Matrix_Vector_Product<MatrixT,VectorT,true>
    operator * ( const Matrix_Transpose<MatrixT>& m,
                 const Vector_Base<VectorT>&      v )
{
    return Matrix_Vector_Product<MatrixT,VectorT,true>( m.child(), v.impl() );
}

/**
 * Product of a transposed vector and a matrix
 */
template <typename VectorT,
          typename MatrixT>
Vector_Transpose<const Matrix_Vector_Product<MatrixT,VectorT,true> >
    operator * ( const Vector_Transpose<VectorT>& v,
                 const Matrix_Base<MatrixT>&      m )
{
    return transpose( Matrix_Vector_Product<MatrixT,VectorT,true>( m.impl(), v.child() ));
}

} // End of tmns::math namespace