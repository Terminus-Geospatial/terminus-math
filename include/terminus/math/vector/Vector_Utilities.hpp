/**
 * @file    Vector_Utilities.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// Terminus Libraries
#include "../types/Functors.hpp"
#include "Vector_Functors.hpp"
#include "Vector_Transpose.hpp"
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
 * Index of the element with the largest magnitude
 */
template <typename VectorT>
size_t index_norm_inf( const Vector_Base<VectorT>& v )
{
    double maxval = -1;
    size_t index=0, result=0;
    typename VectorT::const_iter_t i = v.impl().begin(), end = v.impl().end();
    for( ; i != end ; ++i, ++index )
    {
        double a = std::fabs( *i );
        if( a > maxval )
        {
            maxval = a;
            result = index;
        }
    }
    return result;
}

/**
 * Elementwise sum of two vectors.
 */
template <typename Vector1T,
          typename Vector2T>
Vector_Binary_Functor<Vector1T, Vector2T, Arg_Arg_Sum_Functor>
    elem_sum( const Vector_Base<Vector1T>& v1,
              const Vector_Base<Vector2T>& v2 )
{
    return Vector_Binary_Functor<Vector1T, Vector2T, Arg_Arg_Sum_Functor>( v1.impl(), v2.impl() );
}

/**
 * Sum of two vectors (same as elem_sum).
 */
template <typename Vector1T,
          typename Vector2T>
    Vector_Binary_Functor<Vector1T, Vector2T, Arg_Arg_Sum_Functor>
    operator + ( const Vector_Base<Vector1T>& v1,
                 const Vector_Base<Vector2T>& v2 )
{
    return elem_sum( v1, v2 );
}

/**
 * Sum of two transposed vectors.
 */
template <typename Vector1T, typename Vector2T>
Vector_Transpose<const Vector_Binary_Functor<Vector1T, Vector2T, Arg_Arg_Sum_Functor> >
    operator + ( const Vector_Transpose<Vector1T>& v1,
                 const Vector_Transpose<Vector2T>& v2 )
{
    return transpose( v1.child() + v2.child() );
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
 * Elementwise product of two vectors.
 */
template <typename Vector1T,
          typename Vector2T>
Vector_Binary_Functor<Vector1T, Vector2T, Arg_Arg_Product_Functor>
    elem_prod( const Vector_Base<Vector1T>& v1,
               const Vector_Base<Vector2T>& v2 )
{
    return Vector_Binary_Functor<Vector1T, Vector2T, Arg_Arg_Product_Functor>( v1.impl(), v2.impl() );
}

/**
 * Elementwise product of a scalar and a vector.
 */
template <typename ScalarT,
          typename VectorT>
std::enable_if_t<Is_Scalar<ScalarT>::value,
                 Vector_Unary_Functor<VectorT, Val_Arg_Product_Functor<ScalarT>>>
    elem_prod( ScalarT s, const Vector_Base<VectorT>& v )
{
    return Vector_Unary_Functor<VectorT, Val_Arg_Product_Functor<ScalarT>>( v.impl(), s );
}

/**
 * Elementwise product of a vector and a scalar.
 */
template <typename ScalarT,
          typename VectorT>
std::enable_if_t<Is_Scalar<ScalarT>::value,
                             Vector_Unary_Functor<VectorT, Arg_Val_Product_Functor<ScalarT>>>
    elem_prod( const Vector_Base<VectorT>& v, ScalarT s )
{
    return Vector_Unary_Functor<VectorT, Arg_Val_Product_Functor<ScalarT> >( v.impl(), s );
}

/**
 * Product of a vector and a scalar (same as elem_prod).
 */
template <typename ScalarT,
          typename VectorT>
std::enable_if_t<Is_Scalar<ScalarT>::value,
                             Vector_Unary_Functor<VectorT, Arg_Val_Product_Functor<ScalarT>>>
    operator * ( const Vector_Base<VectorT>& v, ScalarT s )
{
    return elem_prod( v, s );
}

/**
 * Product of a transposed vector and a scalar.
 */
template <typename ScalarT,
          typename VectorT>
std::enable_if_t<Is_Scalar<ScalarT>::value,
                 Vector_Transpose<const Vector_Unary_Functor<VectorT, Arg_Val_Product_Functor<ScalarT>>>>
    operator * ( const Vector_Transpose<VectorT>& v, ScalarT s )
{
    return transpose( v.child() * s );
}

/**
 * Product of a scalar and a vector (same as elem_prod).
 */
template <typename ScalarT,
          typename VectorT>
std::enable_if_t<Is_Scalar<ScalarT>::value,
                 Vector_Unary_Functor<VectorT, Val_Arg_Product_Functor<ScalarT>>>
    operator * ( ScalarT                     s,
                 const Vector_Base<VectorT>& v )
{
    return elem_prod( s, v );
}

/**
 * Product of a scalar and a transposed vector.
 */
template <typename ScalarT,
          typename VectorT>
std::enable_if_t<Is_Scalar<ScalarT>::value,
                 Vector_Transpose<const Vector_Unary_Functor<VectorT,Val_Arg_Product_Functor<ScalarT>>>>
    operator * ( ScalarT                          s,
                 const Vector_Transpose<VectorT>& v )
{
    return transpose( s * v.child() );
}

/**
 * Elementwise quotient of two vectors.
 */
template <typename Vector1T,
          typename Vector2T>
Vector_Binary_Functor<Vector1T, Vector2T, Arg_Arg_Quotient_Functor>
    elem_quot( const Vector_Base<Vector1T>& v1,
               const Vector_Base<Vector2T>& v2 )
{
    return Vector_Binary_Functor<Vector1T, Vector2T, Arg_Arg_Quotient_Functor>( v1.impl(), v2.impl() );
}

/**
 * Elementwise quotient of a scalar and a vector.
 */
template <typename ScalarT,
          typename VectorT>
std::enable_if_t<Is_Scalar<ScalarT>::value,
                 Vector_Unary_Functor<VectorT, Val_Arg_Quotient_Functor<ScalarT>>>
    elem_quot( ScalarT s, const Vector_Base<VectorT>& v )
{
    return Vector_Unary_Functor<VectorT, Val_Arg_Quotient_Functor<ScalarT> >( v.impl(), s );
}

/**
 * Elementwise quotient of a vector and a scalar.
 */
template <typename ScalarT,
          typename VectorT>
std::enable_if_t<Is_Scalar<ScalarT>::value,
                 Vector_Unary_Functor<VectorT, Arg_Val_Quotient_Functor<ScalarT>>>
    elem_quot( const Vector_Base<VectorT>& v, ScalarT s )
{
    return Vector_Unary_Functor<VectorT, Arg_Val_Quotient_Functor<ScalarT> >( v.impl(), s );
}

/**
 * Quotient of a vector and a scalar (same as elem_quot).
 */
template <typename ScalarT,
          typename VectorT>
std::enable_if_t<Is_Scalar<ScalarT>::value,
                 Vector_Unary_Functor<VectorT, Arg_Val_Quotient_Functor<ScalarT>>>
    operator / ( const Vector_Base<VectorT>& v, ScalarT s )
{
    return elem_quot( v, s );
}

/**
 * Quotient of a transposed vector and a scalar.
 */
template <typename ScalarT,
          typename VectorT>
std::enable_if_t<Is_Scalar<ScalarT>::value,
                 Vector_Transpose<const Vector_Unary_Functor<VectorT, Arg_Val_Quotient_Functor<ScalarT>>>>
    operator / ( const Vector_Transpose<VectorT>& v,
                 ScalarT                          s )
{
    return transpose( v.child() / s );
}

} // End of tmns::math namespace