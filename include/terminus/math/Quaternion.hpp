/**
 * @file    Quaternion.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// C++ Includes
#include "Matrix.hpp"
#include "Vector.hpp"

namespace tmns::math {

class Quaternion
{
    public:

        /**
         * Default Constructor
        */
        Quaternion() = default;

        /**
         * Parameterized Constructor
         * @param real
         * @param x
         * @param y
         * @param z
        */
        Quaternion( double real,
                    double x,
                    double y,
                    double z );
        
        /**
         * Parameterized Constructor
         */
        Quaternion( double          real,
                    const Vector3d& imag );


        /**
         * Get the real component
        */
        double real() const;

        /**
         * Get the imaginary component
        */
        Vector3d imag() const;

        /**
         * Get the magnitude of the quaternion
         * @note:  This really should be 1.  
         */
        double magnitude() const;

        /**
         * Get the squared magnitude
         * @note:  This really should be 1.
         */
        double magnitude_sq() const;

        /**
         * Return a normalize quaternion. 
         * This effectively makes it unit-length in case it isn't.
         */
        Quaternion normalize() const;

        /**
         * Get the conjugate of the quaternion
         */
        Quaternion conj() const;

        /**
         * @brief get the inverse of this quaternion
         */
        Quaternion inverse() const;

        /**
         * Quaternion Division
         */
        Quaternion operator / ( const Quaternion& rhs ) const;

        /**
         * Build a quaternion from a rotation matrix
         */
        template <typename MatrixT>
        static Quaternion from_matrix( const MatrixT& mat )
        {
            // Get diagonal parts
            auto diag = mat.diagonal();

            double ww = 1.0 + diag[0] + diag[1] + diag[2];
            double xx = 1.0 + diag[0] - diag[1] - diag[2];
            double yy = 1.0 - diag[0] + diag[1] - diag[2];
            double zz = 1.0 - diag[0] - diag[1] + diag[2];

            double max_val = std::max( ww, std::max( xx, std::max( yy, zz ) ) );
            
            // Depending on the max, we need to determine how to parse the quaternion
            std::array<double,4> components;
            
            static constexpr double EPS { 0.00001 };

            if( std::fabs( ww - max_val ) < EPS )
            {
                double w4 = std::sqrt( ww * 4.0 );
                components[0] = w4 / 4.0;
                components[1] = (mat(2,1) - mat(1,2)) / w4;
                components[2] = (mat(0,2) - mat(2,0)) / w4;
                components[3] = (mat(1,0) - mat(0,1)) / w4;
            }
            
            else if( std::fabs( xx - max_val ) < EPS )
            {
                double x4 = std::sqrt( xx * 4.0 );
                components[0] = ( mat(2,1) - mat(1,2) ) / x4;
                components[1] = x4 / 4;
                components[2] = ( mat(0,1) + mat(1,0) ) / x4;
                components[3] = ( mat(0,2) + mat(2,0) ) / x4;
            }
            
            else if( std::fabs( yy - max_val) < EPS )
            {
                double y4 = std::sqrt(yy * 4.0);
                components[0] = ( mat(0,2) - mat(2,0) ) / y4;
                components[1] = ( mat(0,1) + mat(1,0) ) / y4;
                components[2] =  y4 / 4;
                components[3] = ( mat(1,2) + mat(2,1) ) / y4;
            }
            
            else
            {
                double z4 = std::sqrt( zz * 4.0 );
                components[0] = ( mat(1,0) - mat(0,1) ) / z4;
                components[1] = ( mat(0,2) + mat(2,0) ) / z4;
                components[2] = ( mat(1,2) + mat(2,1) ) / z4;
                components[3] =  z4 / 4;
            }

            return Quaternion( components[0],
                               components[1],
                               components[2],
                               components[3] );
        }

    private:

        /// Real Component
        double m_real { 0 };

        /// Imaginary Component
        Vector3d m_imag { { 1, 0, 0 } };

}; // End of Quaternion Class

} // end of tmns::math API