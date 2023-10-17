/**
 * @file    Eigen_Utilities.hpp
 * @author  Marvin Smith
 * @date    10/15/2023
 */
#pragma once

// Terminus Libraries
#include <terminus/core/error/ErrorCategory.hpp>
#include <terminus/math/matrix.hpp>
#include <terminus/math/vector/VectorN.hpp>

// Eigen Libraries
#include <Eigen/Dense>

namespace tmns::math::eigen {

/**
 * Convert Matrix to Eigen Matrix
*/
template <typename OutMatrixT,
          typename MatrixT>
ImageResult<OutMatrixT> to_eigen( const MatrixT& mat ) requires ( std::is_same_v<::Eigen::MatrixXd,OutMatrixT> )
{
    ::Eigen::MatrixXd result = Eigen::Map<Eigen::MatrixXd>( const_cast<double*>( mat.data() ),
                                                            mat.rows(),
                                                            mat.cols() );

    return outcome::ok<::Eigen::MatrixXd>( result );
}

/**
 * Convert Vector to Eigen Vector
*/
template <typename OutVectorT,
          typename VectorT>
ImageResult<OutVectorT> to_eigen( const VectorT& vec ) requires ( std::is_same_v<OutVectorT,::Eigen::VectorXd> )
{
    ::Eigen::VectorXd result = Eigen::VectorXd::Map( &vec.data()[0], vec.size() );

    return outcome::ok<::Eigen::MatrixXd>( result );
}

/**
 * Convert Eigen Vector to Vector
*/
template <typename VectorT>
ImageResult<VectorT> from_eigen( const ::Eigen::VectorXd& vec )
{
    return outcome::ok<VectorT>( VectorT( vec.data(),
                                          vec.size() ) );
}

} // End of tmns::math::eigen namespace