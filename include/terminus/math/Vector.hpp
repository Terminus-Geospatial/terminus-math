/**
 * @file    Vector.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// C++ Libraries
#include <array>
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

        Vector_( std::array<ValueT,Dims> data )
          : m_data( std::move(data) )
        {
        }

        /**
         * Get X Value
        */
        ValueT x() const
        {
            return m_data.at(0);
        }

        /**
         * Get X Reference
        */
        ValueT& x()
        {
            return m_data.at(0);
        }

        /**
         * Get Y Value
        */
        ValueT y() const
        {
            return m_data.at(1);
        }

        /**
         * Get Y Reference
        */
        ValueT& y()
        {
            return m_data.at(1);
        }

        /**
         * Get Z Value
        */
        ValueT z() const
        {
            return m_data.at(2);
        }

        /**
         * Get Z Reference
        */
        ValueT& z()
        {
            return m_data.at(2);
        }

        /**
         * Get copy of internal data at specific index
        */
        ValueT operator[] ( size_t idx ) const
        {
            return m_data[idx];
        }

        /**
         * Get reference to internal data at specific index
        */
        ValueT& operator[] ( size_t idx )
        {
            return m_data[idx];
        }

        /**
         * @brief Return copy of internal data array
        */
        std::array<ValueT,Dims> data() const
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

// Integer Vectors
using Vector2i = Vector2_<int>;
using Vector3i = Vector3_<int>;
using Vector4i = Vector4_<int>;



} // End of tmns::math