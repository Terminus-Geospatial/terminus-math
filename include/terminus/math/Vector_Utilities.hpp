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
 * Convert 2 scalars to 2D vector
 */
template <typename ValueT>
Vector2_<ValueT> ToVector2( const ValueT& x,
                            const ValueT& y )
{
    return {{ x, y }};
}

/**
 * Convert 3 scalars to 3D vector
 */
template <typename ValueT>
Vector3_<ValueT> ToVector3( const ValueT& x,
                            const ValueT& y,
                            const ValueT& z )
{
    return {{ x, y, z }};
}


} // End of tmns::math namespace