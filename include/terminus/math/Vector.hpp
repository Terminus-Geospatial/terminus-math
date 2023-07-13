/**
 * @file    Vector.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// C++ Libraries
#include <array>

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

// Integer Vectors
using Vector2i = Vector2_<int>;
using Vector3i = Vector3_<int>;
using Vector4i = Vector4_<int>;



} // End of tmns::math