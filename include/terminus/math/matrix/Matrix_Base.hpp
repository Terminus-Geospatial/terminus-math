/**
 * @file    Matrix_Base.hpp
 * @author  Marvin Smith
 * @date    9/16/2023
*/
#pragma once

// Terminus Math Libraries
#include "Matrix_Row.hpp"
#include "Matrix_Traits.hpp"

namespace tmns::math {

/**
 * @class Matrix_Base
 * 
 * I'm really torn on using VW's concept of a Matrix
 * or simply making a dynamic double-precision matrix that
 * is super simple to read.  I like how Eigen does things, but
 * they also are template-based, which means I'd have to 
 * expose this to customers.  I really don't think it's realistic
 * to do a template-heavy API beind PIMPL, so it's just going to 
 * be this for now.
 */
template <typename MatrixT>
class Matrix_Base
{
    public:

        /**
         * Get the derived matrix type
         */
        MatrixT& impl()
        {
            return *static_cast<MatrixT*>(this);
        }

        /**
         * Get the derived const matrix type
         */
        MatrixT const& impl() const
        {
            return *static_cast<MatrixT const*>(this);
        }

        /**
         * Matrix Addition Assignment
         */
        template <typename T> 
        MatrixT& operator += ( const T& m )
        {
            return impl() = impl() + m;
        }
        
        /**
         * Matrix Subtraction Assignment
         */
        template <typename T>
        MatrixT& operator -= ( const T& m )
        {
            return impl() = impl() - m;
        }  
        
        /**
         * Matrix Multiplication Assignment
         */
        template <typename T>
        MatrixT& operator*=( const T& s )
        {
            return impl() = impl() * s;
        }

        /**
         * Matrix Division Assignment
         */
        template <typename T>
        MatrixT& operator /= ( const T& s )
        {
            return impl() = impl() / s;
        }

        /**
         * Access an individual matrix row, for further access using a second
         * operator[].
         */
        Matrix_Row<MatrixT> operator[]( size_t row )
        {
            return Matrix_Row<MatrixT>( impl(), row );
        }

        /**
         * Access an individual matrix row, for further access using a second
         * operator[].
         */
        Matrix_Row<const MatrixT> operator[]( size_t row ) const
        {
            return Matrix_Row<const MatrixT>( impl(), row );
        }


}; // End of Matrix_Base class

} // End of tmns::math namespace