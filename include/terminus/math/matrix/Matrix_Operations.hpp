/**
 * @file    Matrix_Operations.hpp
 * @author  Marvin Smith
 * @date    9/16/2023
 */
#pragma

// Terminus Libraries
#include "Matrix_Col.hpp"

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

} // End of tmns::math namespace