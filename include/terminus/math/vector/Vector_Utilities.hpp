/**
 * @file    Vector_Utilities.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// Terminus Libraries
#include "../types/Functors.hpp"
#include "Vector_Functors.hpp"
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

/**
 * Difference of two vectors (same as elem_diff).
 */
template <typename Vector1T,
          typename Vector2T>
Vector_Binary_Functor<Vector1T, Vector2T, Arg_Arg_Difference_Functor>
    operator - ( const Vector_Base<Vector1T>& v1,
                 const Vector_Base<Vector2T>& v2 )
{
    return Vector_Binary_Functor<Vector1T,
                                 Vector2T,
                                 Arg_Arg_Difference_Functor>( v1.impl(), v2.impl() );
}

/**
 * Multiply a Vector with a Scalar
*/
template <typename  ValueT,
          size_t    Dims,
          typename  OtherValueT>
Vector_<ValueT,Dims> operator * ( const Vector_<ValueT,Dims>& vec,
                                  const OtherValueT&          sc )
{
    auto output = vec;
    for( auto& val : output.data() )
    {
        val = val * sc;
    }
    return output;
}

/**
 * Multiply a Scalar with a Vector
*/
template <typename  ValueT,
          size_t    Dims,
          typename  OtherValueT>
Vector_<ValueT,Dims> operator * ( const OtherValueT&          sc,
                                  const Vector_<ValueT,Dims>& vec )
{
    auto output = vec;
    for( auto& val : output.data() )
    {
        val = val * sc;
    }
    return output;
}

/**
 * Divide a Vector with a Scalar
*/
template <typename  ValueT,
          size_t    Dims,
          typename  OtherValueT>
Vector_<ValueT,Dims> operator / ( const Vector_<ValueT,Dims>& vec,
                                  const OtherValueT&          sc )
{
    auto output = vec;
    for( auto& val : output.data() )
    {
        val = val / sc;
    }
    return output;
}

} // End of tmns::math namespace