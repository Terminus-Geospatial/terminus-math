/**
 * @file    Vector.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// C++ Libraries
#include <array>
#include <iostream>
#include <sstream>

namespace tmns::math {

/**
 * N-dimensional vector class
*/
template <typename ValueT, int Dims>
class Vector_
{
    public:

        /**
         * Default Constructor
        */
        Vector_() = default;

        /**
         * Constructor given an array
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
            std::copy( data.begin(), data.end(), m_data.begin() );
        }

        /**
         * Constructor given a fill value
        */
        Vector_( const ValueT& fill_value )
        {
            m_data.fill( fill_value );
        }

        /**
         * Get the size of the vector
        */
        virtual size_t size() const
        {
            return m_data.size();
        }

        /**
         * Get X Value
        */
        ValueT x() const
        {
            return this->at(0);
        }

        /**
         * Get X Reference
        */
        ValueT& x()
        {
            return this->at(0);
        }

        /**
         * Get Y Value
        */
        ValueT y() const
        {
            return this->at(1);
        }

        /**
         * Get Y Reference
        */
        ValueT& y()
        {
            return this->at(1);
        }

        /**
         * Get Z Value
        */
        ValueT z() const
        {
            return this->at(2);
        }

        /**
         * Get Z Reference
        */
        ValueT& z()
        {
            return this->at(2);
        }

        /**
         * Get copy of internal data at specific index
        */
        virtual ValueT operator[] ( size_t idx ) const
        {
            return m_data[idx];
        }

        /**
         * Get reference to internal data at specific index
        */
        virtual ValueT& operator[] ( size_t idx )
        {
            return m_data[idx];
        }

        /**
         * Get copy of internal data at specific index
        */
        virtual ValueT at( size_t idx ) const
        {
            return m_data.at(idx);
        }

        /**
         * Get reference to internal data at specific index
        */
        virtual ValueT& at( size_t idx )
        {
            return m_data.at(idx);
        }

        /**
         * @brief Return copy of internal data array
        */
        std::array<ValueT,Dims> const& data() const
        {
            return m_data;
        }

        /**
         * @brief Return reference of internal data array
        */
        std::array<ValueT,Dims>& data()
        {
            return m_data;
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

        std::array<ValueT,Dims> m_data { 0 };

}; // End of Vector class

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