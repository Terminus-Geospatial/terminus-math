/**
 * @file    MatrixN.hpp
 * @author  Marvin Smith
 * @date    9/16/2023
 */
#pragma once

// Terminus Libraries
#include "Matrix.hpp"

namespace tmns::math {

/**
 * Dynamicall allocated, arbitrary-dimension matrix class.
 */
template <typename ElementT>
class Matrix<ElementT,0,0> : public matrix::Matrix_Base<Matrix<ElementT> >
{
    public:

        /// @brief  Array Type
        using array_type = std::vector<ElementT>;
    
        /// @brief Underlying Element / Value Type
        using value_type = ElementT;

        /// @brief Reference Value Type
        using reference_type = ElementT&;

        /// @brief Const Reference Value Type
        using const_reference_type = ElementT const&;

        /// @brief Iterator Type
        using iter_t = array_type::iterator;

        /// @brief Const Iterator Type
        using const_iter_t = array_type::const_iterator;

        /**
         * Constructs a default (zero-size) matrix
         */
        Matrix() = default;

        /**
         * Constructs a matrix of zeros with the given size
         */
        Matrix( size_t rows,
                size_t cols )
            : m_rows( rows ),
              m_cols( cols ),
              m_data( rows * cols )
        {
            std::fill( m_data.begin(),
                       m_data.end(),
                       0 );
        }

        /**
         * Constructs a matrix of the given size from given 
         * densely-packed row-mjor data.  This constructor copies the
         * data.  If you wish to make a shallow proxy object instead,
         * Matrix_Proxy
         */
        Matrix( size_t          rows,
                size_t          cols,
                const ElementT* data )
            : m_data( data, data + rows * cols ),
              m_rows( rows ),
              m_cols( cols )
        {
        }

        /**
         * Standard Copy Constructor
         * @note Provided in case the next constructor accidentally auto-resolves without
         *       this
        */
       Matrix( const Matrix& mat )
           : m_data( mat.m_data ),
             m_rows( mat.m_rows ),
             m_cols( mat.m_cols )
        {
        }
        
        /**
         * Generalized copy constructor for any base type
         */
        template <typename OtherMatrixT>
        Matrix( const matrix::Matrix_Base<OtherMatrixT>& mat )
            : m_data( mat.impl().begin(),
                      mat.impl().end() ),
              m_rows( mat.rows() ),
              m_cols( mat.cols() )
        {
        }

        /**
         * Copy assignment operator
         */
        Matrix& operator = ( const Matrix& mat )
        {
            // Make a copy of the data
            Matrix temp( mat );
            m_rows = temp.m_rows;
            m_cols = temp.m_cols;
            m_data = temp.m_data;
            return (*this);
        }

        /**
         * Generalize Assignment Operator
         */
        template <typename OtherMatrixT>
        Matrix& operator = ( const matric::Matrix_Base<OtherMatrixT>& mat )
        {
            // Make a copy of the data
            Matrix temp( mat );
            m_rows = temp.m_rows;
            m_cols = temp.m_cols;
            m_data = temp.m_data;
            return (*this);
        }

        /**
         * Temporary-free generalized assignment operator, from arbitrary VW matrix expressions.
         * This is a performance-optimizing function to be used with caution!
         */
        template <typename OtherMatrixT>
        Matrix& operator = ( const MatrixNoTmp<OtherMatrixT>& mat )
        {
            if( mat.impl().rows() == rows() && 
                mat.impl().cols()==cols() )
            {
                std::copy( mat.impl().begin(),
                           mat.impl().end(),
                           begin() );
                return *this;
            }
            else 
            {
                std::cerr << "Matrix must have dimensions of " << rows() << " rows by "
                          << cols() << " cols.  Actual: " << mat.rows() << " rows x " 
                          << mat.cols() << " cols";
                return *this = mat.impl();
            } 
        }

        /**
         * Get matrix rows
         */
        size_t rows() const
        {
            return m_rows;
        }

        /**
         * Get matrix columns 
         */
        size_t cols() const
        {
            return m_cols;
        }

        /**
         * Resize the matrix.  Elements in memory are preserved when
         * specified.
         */
        void set_size( size_t rows,
                       size_t cols,
                       bool   preserve = false )
        {
            if( preserve )
            {
                // Create new array
                array_type other( rows * cols );
                
                size_t mr = (std::min)( rows, m_rows );
                size_t mc = (std::min)( cols, m_cols );
                for( size_t r=0; r<mr; ++r )
                for( size_t c=0; c<mc; ++c )
                {
                    other[ r * cols + c ] = m_data[ r * m_cols + c ];
                }

                m_data.swap( other );
            }
            else
            {
                m_data.resize( rows * cols, false );
            }
            m_rows = rows;
            m_cols = cols;
        }

        /**
         * Access an element
         */
        value_type& operator()( size_t row,
                                size_t col )
        {
            return m_data[ row * m_cols + col ];
        }

        /**
         * Access an element
         */
        value_type const& operator()( size_t row,
                                      size_t col ) const
        {
            return m_data[ row * m_cols + col ];
        }

        /**
         * Get pointer to underlying data
         */
        value_type* data()
        {
            return &(operator()(0,0));
        }
        
        /**
         * Get pointer to underlying data
         */
        const value_type* data() const
        {
            return &(operator()(0,0));
        }

        /**
         * Get the beginning of the matrix
         */
        const_iter_t begin()
        {
            return m_data.begin();
        }
        
        /**
         * Get the beginning of the matrix (const)
         */
        const_iter_t begin() const
        {
            return m_data.begin();
        }

        /**
         * Get the end of the matrix
         */
        iter_t end()
        {
            return m_data.end();
        }

        /**
         * Get the end of the matrix (const)
         */
        const_iter_t end() const
        {
            return m_data.end();
        }

    private:

        /// @brief Underlying array data
        array_type m_data;

        /// @brief Matrix Rows
        size_t m_rows { 0 };

        /// @brief Matrix Cols
        size_t m_cols { 0 };

};  // End of Matrix<ElementT,0,0> class

// Rename Matrix to MatrixN for this case
template <typename ElementT>
using MatrixN = Matrix<ElementT,0,0>;

} // End of tmns::math namespace