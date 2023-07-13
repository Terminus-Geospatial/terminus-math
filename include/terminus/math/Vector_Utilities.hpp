/**
 * @file    Vector_Utilities.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// Terminus Libraries
#include "Vector.hpp"

namespace tmns::math {

/**
 * Convert 3 scalars to 3D vector
 */
template <typename ValueT>
Vector3_<ValueT> ToVector3( double x,
                            double y,
                            double z )
{
    return {{ x, y, z }};
}


} // End of tmns::math namespace