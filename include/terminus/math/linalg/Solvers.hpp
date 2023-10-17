/**
 * @file    Solvers.hpp
 * @author  Marvin Smith
 * @date    10/15/2023
 */
#pragma once

// Terminus Libraries
#include <terminus/core/error/ErrorCategory.hpp>
#include <terminus/math/matrix/MatrixN.hpp>
#include <terminus/math/types/Type_Deduction.hpp>
#include <terminus/math/vector/VectorN.hpp>

namespace tmns::math::linalg {

ImageResult<VectorN<double>> solve_symmetric( const MatrixN<double>& A,
                                              const VectorN<double>& b );

/**
 * Solve the equation Ax=b where A is a symmetric positive definite matrix.  This version of
 * this method will not modify A and b. The result (x) is returned as the return value.
 */
template <typename AMatrixT,
          typename BVectorT>
ImageResult<VectorN<typename Promote_Type<typename AMatrixT::value_type,
                                          typename BVectorT::value_type>::type>>
    solve_symmetric( const AMatrixT& A,
                     const BVectorT& B )
{
    using real_type = typename Promote_Type<typename AMatrixT::value_type,
                                            typename BVectorT::value_type>::type;
    MatrixN<real_type> Abuf = A;
    VectorN<real_type> result = B;
    
    return solve_symmetric( A, B );
}

} // End of tmns::math::linalg