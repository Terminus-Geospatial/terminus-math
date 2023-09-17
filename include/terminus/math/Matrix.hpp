/**
 * @file    Matrix.hpp
 * @author  Marvin Smith
 * @date    9/16/2023
 */
#pragma once

// Terminus Libraries
#include "matrix/Matrix_Base.hpp"

// Boost Libraries
#include <boost/mpl/min_max.hpp>

// C++ Libraries
#include <cassert>
#include <iterator>

namespace tmns::math {

/**
 * A statically-allocated fix-dimension matrix class.
 */
template <typename ElementT,
          size_t   RowsN = 0,
          size_t   ColsN = 0>
class Matrix : public matrix::Matrix_Base<Matrix<ElementT,RowsN,ColsN> >
{
    public:

        /// @brief Array Type
        using array_type = std::array<ElementT, RowsN * ColsN>;

        /// @brief Value Element Type
        using value_type = ElementT;

        /// @brief Reference Type
        using reference_type = ElementT&;

        /// @brief Const Reference Type
        using const_reference_type = const ElementT&;

        /// @brief Standard Iterator Type
        using iter_t = typename array_type::iterator;

        /// @brief Const Iterator Type
        using const_iter_t = typename array_type::const_iterator;
        
        /**
         * Default Constructor
         */
        Matrix()
        {
            std::fill( m_data.begin(),
                       m_data.end(),
                       0 );
        }

        /**
         * Constructor given an array of data
         */
        Matrix( std::array<value_type,RowsN*ColsN> data )
        {
            // Copy the first X elements
            std::copy( data.begin(), 
                       data.end(),
                       m_data.begin() );
            
            // Fill in the remaining items
            auto pos = m_data.begin();
            std::advance( pos, RowsN * ColsN );

            std::fill( pos,
                       m_data.end(),
                       0 );
        }

        /**
         * Constructor given an array of data
         */
        template <typename OtherValueT,
                  size_t ArrayDims>
        Matrix( std::array<OtherValueT,ArrayDims> data ) requires ( ArrayDims <= ColsN * RowsN )
        {
            // Copy the first X elements
            std::copy( data.begin(), 
                       data.end(),
                       m_data.begin() );
            
            // Fill in the remaining items
            auto pos = m_data.begin();
            std::advance( pos, ArrayDims );

            std::fill( pos,
                       m_data.end(),
                       0 );
        }

        /**
         * Copy Constructor
         */
        Matrix( const Matrix& mat )
            : m_data( mat.m_data )
        {
        }

        /**
         * Copy Constructor from another Base Matrix-Type
         */
        template <typename OtherMatrixT>
        Matrix( const matrix::Matrix_Base<OtherMatrixT>& mat )
        {
            // Log error if incoming matrix is of incorrect size
            if( mat.impl().rows() != RowsN ||
                mat.impl().cols() != ColsN )
            {
                std::cerr << "Matrix must have dimensions " << RowsN << " rows by " 
                          << ColsN << " cols.";
            }
            else
            {
                // Copy elements
                std::copy( mat.impl().begin(), 
                           mat.impl().end(),
                           begin() );
            }
        }

        /**
         * Copy assignment operator
         */
        Matrix& operator = ( const Matrix& rhs )
        {
            Matrix temp( rhs );
            m_data = temp.m_data;
            return (*this);
        }

        /**
         * General assignment operator
         */
        template <typename OtherMatrixT>
        Matrix& operator = ( const matrix::Matrix_Base<OtherMatrixT>& mat )
        {
            if( mat.impl().rows() != RowsN ||
                mat.impl().cols() != ColsN )
            {
                std::cerr << "Matrix must have dimensions " << RowsN << " rows x " << ColsN
                          << " cols.  Actual: " << mat.impl().rows() << " rows x " << mat.impl().cols()
                          << " cols.  Skipping assignment.";
                return (*this);
            }
            
            // Create a new instance
            Matrix tmp( mat );
            m_data = tmp.m_data;
            return *this;
        }

        /**
         * Temporary-free generalized assignment operator, from arbitrary matrix
         * expressions. This is a performance-optimizing function to be used with
         * caution!
         */
        template <typename OtherMatrixT>
        Matrix& operator = ( const matrix::Matrix_No_Tmp<OtherMatrixT>& mat )
        {
            if( mat.impl().rows() != RowsN ||
                mat.impl().cols() != ColsN )
            {
                std::cerr << "Matrix must have dimensions " << RowsN << " rows x " << ColsN
                          << " cols.  Actual: " << mat.impl().rows() << " rows x " << mat.impl().cols()
                          << " cols.  Skipping assignment.";
                return (*this);
            }

            std::copy( mat.impl().begin(),
                       mat.impl().end(),
                       begin() );
            return *this;
        }

        /**
         * Get the number of matrix rows
         */
        size_t rows() const
        {
            return RowsN;
        }

        /**
         * Get the number of matrix columns
         */
        size_t cols() const
        {
            return ColsN;
        }

        /**
         * Resize the matrix
         */
        bool set_size( size_t new_rows,
                       size_t new_cols,
                       [[maybe_unused]] bool preserve = false )
        {
            if( new_rows != rows() ||
                new_cols != cols() )
            {
                std::cerr << "Cannot resize a fixed-size matrix.";
                return false;
            }
            return true;
        }

        /**
         * Access a specific element
         */
        value_type& operator()( size_t row,
                                size_t col )
        {
            return m_data[ row * ColsN + col ];
        }

        /**
         * Access a specific element
         */
        value_type const& operator()( size_t row,
                                      size_t col ) const
        {
            return m_data[ row * ColsN + col ];
        }

        /**
         * Get underlying data
         */
        value_type* data()
        {
            // This is designed to function when the underlying type isn't an array.
            return &(operator()(0,0));
        }

        /**
         * Get underlying data
         */
        const value_type* data() const
        {
            return &(operator()(0,0));
        }

        /**
         * Get the beginning of the array
         */
        iter_t begin()
        {
            return m_data.begin();
        }

        /**
         * Get the beginning of the array
         */
        const_iter_t begin() const
        {
            return m_data.begin();
        }

        /**
         * Get the end of the array
         */
        iter_t end()
        {
            return m_data.end();
        }

        /**
         * Get the end of the array
         */
        const_iter_t end() const
        {
            return m_data.end();
        }

        /**
         * Return all diagonal components
         */
        Vector_<ElementT,std::min(RowsN,ColsN)> diagonal() const
        {
            Vector_<ElementT,std::min(RowsN,ColsN)> output;
            for( size_t x = 0; x < output.size(); x++ )
            {
                output[x] = this->operator()( x, x );
            }
            return std::move( output );
        }

        /**
         * Return a zero matrix
         */
        static Matrix zeros()
        {
            return Matrix();
        }

        /**
         * Return a 1 matrix
         */
        static Matrix ones()
        {
            auto output = Matrix();
            for( auto it = output.begin(); it != output.end(); it++ )
            {
                (*it) = 1;
            }
            return output;
        }

        /**
         * Return an identity matrix
         */
        static Matrix identity()
        {
            // Create a zero matrix
            auto output = zeros();

            // Set 1 column
            size_t diag = std::min( output.cols(), output.rows() );
            for( size_t d = 0; d < diag; d++ )
            {
                output.impl()( d, d ) = ( value_type( 1 ) );
            }
            return output;
        }

    private:

        /// Array Information
        array_type m_data { 0 };

}; // End of Matrix class

// Overload a few type traits
namespace matrix {

/**
 * Matrix implementation for Matrix_Rows
 */
template <typename ElementT,
          size_t RowsN,
          size_t ColsN>
struct Matrix_Rows<Matrix<ElementT,RowsN,ColsN> >
{
    static const size_t value = RowsN;
};

/**
 * Matrix implementation for Matrix_Rows
 */
template <typename ElementT,
          size_t RowsN,
          size_t ColsN>
struct Matrix_Cols<Matrix<ElementT,RowsN,ColsN> >
{
    static const size_t value = ColsN;
};

} // End of matrix namespace

} // End of tmns::math namespace