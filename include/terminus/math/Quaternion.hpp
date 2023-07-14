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
         * Get the real component
        */
        double real() const;

        /**
         * Get the imaginary component
        */
        Vector3d imag() const;

    private:

        /// Real Component
        double m_real { 0 };

        /// Imaginary Component
        Vector3d m_imag {{ 1, 0, 0 }};

}; // End of Quaternion Class

} // end of tmns::math API