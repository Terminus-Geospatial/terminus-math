/**
 * @file    Quaternion.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// C++ Includes
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

    private:

        /// Real Component
        double m_real { 0 };

        /// Imaginary Component
        Vector3d m_imag { { 1, 0, 0 } };

}; // End of Quaternion Class

} // end of tmns::math API