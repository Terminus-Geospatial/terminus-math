/**
 * @file    Vector_Base.hpp
 * @author  Marvin Smith
 * @date    9/16/2023
*/
#pragma once

// Terminus Libraries
#include "Vector_Traits.hpp"

namespace tmns::math {

/**
 * A CRTP base class for vectors and vector expressions.
 * Provides a mechanism for restricting function arguments to
 * vectors, and provides the various arithmetic assignment operators.
 */
template <typename VectorT>
class Vector_Base
{
    public:

        /**
         * Get the derived implementation type
         */
        VectorT& impl()
        {
            return *static_cast<VectorT*>(this);
        }

        /**
         * Get the const derived implementation type
        */
        VectorT const& impl() const
        {
            return *static_cast<VectorT const*>(this);
        }

        /**
         * Addition / Assignment Operator
         */
        template <typename T>
        VectorT&  operator += ( const T& v )
        {
            return impl() = impl() + v;
        }

        /**
         * Subtraction / Assignment Operator
         */
        template <typename T>
        VectorT& operator -= ( const T& v )
        {
            return impl() = impl() - v;
        }

        /**
         * Product / Assignment Operator
         */
        template <typename T>
        VectorT& operator *= ( const T& s )
        {
            return impl() = impl() * s;
        }

        /**
         * Division / Assignment Operator
         */
        template <typename T>
        VectorT& operator /= ( const T& s )
        {
            return impl() = impl() / s;
        }

        /**
         * Set all elements in the vector
         */
        template <typename ElementT>
        void fill( ElementT value )
        {
            impl().fill( value );
        }

}; // End of Vector_Base class

} // end of tmns::math namespace