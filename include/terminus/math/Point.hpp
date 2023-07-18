/**
 * @file    Point.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// Terminus Libraries
#include "Vector.hpp"

// C++ Libraries
#include <sstream>

namespace tmns::math {

/**
 * N-dimensional point class
 *
 * This differs from the vector in that it's designed for geometric
 * operations, whereas the vector is more geared towards linear algebra
 * and trigonametric operations.
*/
template <typename ValueT, int Dims>
class Point_ : public Vector_<ValueT,Dims>
{
    public:

        /**
         * Default Constructor
        */
        Point_() = default;

        /**
         * Parameterized Constructor
        */
        Point_( std::array<ValueT,Dims> data )
          : Vector_<ValueT,Dims>( std::move(data) )
        {
        }

        /**
         * Addition Operator
        */
        template< typename OtherValueT>
        Point_<ValueT,Dims> operator + ( const Point_<OtherValueT,Dims>& rhs ) const
        {
            Point_<ValueT,Dims> result;
            for( size_t i=0; i < this->m_data.size(); i++ )
            {
                result.m_data[i] = this->m_data[i] + rhs.m_data[i];
            }
            return result;
        }

        /**
         * Subtraction Operator
        */
        template< typename OtherValueT>
        Point_<ValueT,Dims> operator - ( const Point_<OtherValueT,Dims>& rhs ) const
        {
            Point_<ValueT,Dims> result;
            for( size_t i=0; i < this->m_data.size(); i++ )
            {
                result.m_data[i] = this->m_data[i] - rhs.m_data[i];
            }
            return result;
        }

        /**
         * Print to string
        */
        std::string to_string() const
        {
            std::stringstream sout;
            sout << "Point (Dims: " << Dims << "): ";
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


}; // End of Point class

// Alias for Point2_ object
template <typename ValueT> using Point2_ = Point_<ValueT,2>;
template <typename ValueT> using Point3_ = Point_<ValueT,3>;
template <typename ValueT> using Point4_ = Point_<ValueT,4>;

// Double-Precision Points
using Point2d = Point2_<double>;
using Point3d = Point3_<double>;
using Point4d = Point4_<double>;

// Integer Points
using Point2i = Point2_<int>;
using Point3i = Point3_<int>;
using Point4i = Point4_<int>;


} // End of tmns::math