/**
 * @file    Vector.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// C++ Libraries
#include <array>
#include <cmath>
#include <iostream>
#include <sstream>

// Terminus Libraries
#include "vector/Vector_Base.hpp"

namespace tmns::math {

/**
 * N-dimensional vector class
*/
template <typename ValueT, int Dims>
class Vector_ : public vector::Vector_Base<Vector_<ValueT,Dims>>
{
    public:

        /// @brief Value Type
        using value_type = ValueT;

        /// @brief Array Type
        using array_type = std::array<value_type,Dims>;

        /// @brief Reference Type
        using reference_type = ValueT&;

        /// @brief Const Reference Type
        using const_reference_type = const ValueT&;

        /// @brief Iterator Type
        using iter_t = typename array_type::iterator;

        /// @brief Const Iterator Type
        using const_iter_t = typename array_type::const_iterator;

        /**
         * Default Constructor
        */
        Vector_()
        {
            std::fill( m_data.begin(), m_data.end(), 0 );
        }

        /**
         * Constructor given an array.  Performs a deep copy.  If 
         * you want a shallow copy, use the Vector_Proxy class
        */
        Vector_( std::array<ValueT,Dims> data )
          : m_data( std::move(data) )
        {
        }

        /**
         * Constructor given an array of a different datatype
        */
        template <typename OtherValueT>
        Vector_( std::array<OtherValueT,Dims> data )
        {
            std::copy( data.begin(),
                       data.end(),
                       m_data.begin() );
        }

        /**
         * Constructor given a fill value
         */
        Vector_( const ValueT& fill_value )
        {
            m_data.fill( fill_value );
        }

        /**
         * Standard Copy-Constructor
         */
        Vector_( const Vector_& v )
            : m_data( v.m_data )
        {
        }

        /**
         * Generalized copy constructor from any base vector.
         */
        template <typename OtherVectorT>
        Vector_( const vector::Vector_Base<OtherVectorT>& v )
        {
            if( v.impl().size() != Dims )
            {
                std::cerr << "Vector must have dimension " << Dims << ". Actual: "
                          << v.impl().size() << ".  Performing No-Op.";
            }
            else
            {
                std::copy( v.impl().begin(),
                           v.impl().end(),
                           begin() );
            }
        }

        /**
         * General Assignment Operator
         */
        Vector_& operator = ( const Vector_& v )
        {
            Vector_ temp( v );
            m_data = temp.m_data;
            return (*this);
        }

        /**
         * Assignment operator for any vector type.
         */
        template <typename OtherVectorT>
        Vector_& operator = ( const vector::Vector_Base<OtherVectorT>& v )
        {
            if( v.impl().size() != Dims )
            {
                std::cerr << "Vector must have dimensions: " << Dims << ", Actual: "
                          << v.impl().size() << ".";
            }
            Vector_ tmp( v );
            m_data = tmp.m_data;
            return *this;
        }

        /**
         * Get the size of the vector
        */
        virtual size_t size() const
        {
            return m_data.size();
        }

        /**
         * @brief Get X Value
         */
        const_reference_type x() const
        {
            return m_data[0];
        }

        /**
         * @brief Get X Reference
         */
        reference_type x()
        {
            return m_data[0];
        }

        /**
         * @brief Get Y Value
         */
        const_reference_type y() const requires ( Dims >= 2 )
        {
            return m_data[1];
        }

        /**
         * @brief Get Y Reference
         */
        reference_type y() requires ( Dims >= 2 )
        {
            return m_data[1];
        }

        /**
         * @brief Get Z Value
         */
        const_reference_type z() const requires ( Dims >= 3 )
        {
            return m_data[2];
        }

        /**
         * @brief Get Z Reference
         */
        reference_type z() requires ( Dims >= 3 )
        {
            return m_data[2];
        }

        /**
         * Get copy of internal data at specific index
        */
        virtual const_reference_type operator[] ( size_t idx ) const
        {
            return m_data[idx];
        }

        /**
         * Get reference to internal data at specific index
        */
        virtual reference_type operator[] ( size_t idx )
        {
            return m_data[idx];
        }

        /**
         * Get copy of internal data at specific index
        */
        virtual const_reference_type operator() ( size_t idx ) const
        {
            return m_data[idx];
        }

        /**
         * Get reference to internal data at specific index
        */
        virtual reference_type operator() ( size_t idx )
        {
            return m_data[idx];
        }

        /**
         * Get copy of internal data at specific index
        */
        virtual const_reference_type at( size_t idx ) const
        {
            return m_data.at(idx);
        }

        /**
         * Get reference to internal data at specific index
        */
        virtual reference_type at( size_t idx )
        {
            return m_data.at(idx);
        }

        /**
         * @brief Return copy of internal data array
        */
        array_type const& data() const
        {
            return m_data;
        }

        /**
         * @brief Return reference of internal data array
         */
        array_type& data()
        {
            return m_data;
        }

        /**
         * Get the starting iterator position
         */
        iter_t begin()
        {
            return m_data.begin();
        }

        /**
         * Get the starting iterator position
         */
        const_iter_t begin() const
        {
            return m_data.begin();
        }

        /**
         * Get the ending iterator position
         */
        iter_t end()
        {
            return m_data.end();
        }

        /**
         * Get the ending iterator position
         */
        const_iter_t end() const
        {
            return m_data.end();
        }

        /**
         * @brief Set all elements in the vector
         */
        template <typename TP>
        void fill( TP value )
        {
            std::fill( begin(),
                       end(),
                       value );
        }

        /**
         * Addition Operator
        */
        template< typename OtherValueT>
        Vector_<ValueT,Dims> operator + ( const Vector_<OtherValueT,Dims>& rhs ) const
        {
            Vector_<ValueT,Dims> result;
            for( size_t i=0; i<m_data.size(); i++ )
            {
                result.m_data[i] = m_data[i] + rhs.m_data[i];
            }
            return result;
        }

        /**
         * Subtraction Operator
        */
        template< typename OtherValueT>
        Vector_<ValueT,Dims> operator - ( const Vector_<OtherValueT,Dims>& rhs ) const
        {
            Vector_<ValueT,Dims> result;
            for( size_t i=0; i<m_data.size(); i++ )
            {
                result.m_data[i] = m_data[i] - rhs.m_data[i];
            }
            return result;
        }

        /**
         * Normalize the vector
         */
        Vector_<ValueT,Dims> normalize() const
        {
            Vector_<ValueT,Dims> output = (*this);
            auto mag = magnitude();
            for( size_t i = 0; i < Dims; i++ )
            {
                output[i] /= mag;
            }
            return output;
        }

        /**
         * Compute the vector magnitude
        */
        double magnitude() const
        {
            return std::sqrt( magnitude_sq() );
        }

        /**
         * Compute the square of the magnitude
        */
        double magnitude_sq() const
        {
            double mag = 0;
            for( const auto& elem : this->data() )
            {
                mag += elem * elem;
            }
            return mag;
        }

        /**
         * Perform a Dot-Product
         */
        static double dot( const Vector_<ValueT,Dims>& vec1,
                           const Vector_<ValueT,Dims>& vec2 )
        {
            double mag = 0;
            for( int i = 0; i < Dims; i++ )
            {
                mag += vec1[i] * vec2[i];
            }
            return mag;
        }

        /**
         * Print to string
        */
        std::string to_string() const
        {
            std::stringstream sout;
            sout << "Vector (Dims: " << Dims << "): ";
            for( size_t i = 0; i < this->m_data.size(); i++ )
            {
                if( i != 0 )
                {
                    sout << ", ";
                }
                sout << this->m_data[i];
            }
            return sout.str();
        }

    private:

        array_type m_data;

}; // End of Vector class

namespace vector {

/**
 * Handle for getting the size
 */
template <typename ValueT,
          size_t   Dims>
struct Vector_Size<Vector_<ValueT,Dims>>
{
    const static size_t value = Dims;
};

} // End of vector namespace

// Alias for Point2_ object
template <typename ValueT> using Vector2_ = Vector_<ValueT,2>;
template <typename ValueT> using Vector3_ = Vector_<ValueT,3>;
template <typename ValueT> using Vector4_ = Vector_<ValueT,4>;

// Double-Precision Vectors
using Vector2d = Vector2_<double>;
using Vector3d = Vector3_<double>;
using Vector4d = Vector4_<double>;

// Single-Precision Vectors
using Vector2f = Vector2_<float>;
using Vector3f = Vector3_<float>;
using Vector4f = Vector4_<float>;

// Integer Vectors
using Vector2i = Vector2_<int>;
using Vector3i = Vector3_<int>;
using Vector4i = Vector4_<int>;



} // End of tmns::math