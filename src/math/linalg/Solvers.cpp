/**
 * @file    Solvers.cpp
 * @author  Marvin Smith
 * @date    10/15/2023
 */
#include <terminus/math/linalg/Solvers.hpp>

// Project Libraries
#include "../../thirdparty/eigen/Eigen_Utilities.hpp"

namespace tmns::math::linalg {

/************************************************************/
/*          Solve the system of linear equations            */
/************************************************************/
ImageResult<VectorN<double>> solve_symmetric( const MatrixN<double>& A,
                                              const VectorN<double>& b )
{
    // Create Eigen matrix
    auto eigen_A = eigen::to_eigen<::Eigen::MatrixXd>( A );
    auto eigen_b = eigen::to_eigen<::Eigen::VectorXd>( b );

    auto x = eigen_A.value().colPivHouseholderQr().solve( eigen_b.value() );

    return eigen::from_eigen<VectorN<double>>( x );
}

} // End of tmns::math::linalg namespace