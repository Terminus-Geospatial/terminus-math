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

        typedef ValueT value_type;

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
         * Index Operator
        */
        ValueT operator[]( size_t idx ) const
        {
            return this->m_data[idx];
        }

        /**
         * Index Reference Operator
         */
        ValueT& operator[]( size_t idx )
        {
            return this->m_data[idx];
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
         * Addition Operator
        */
        template< typename OtherValueT>
        Point_<ValueT,Dims> operator + ( const Vector_<OtherValueT,Dims>& rhs ) const
        {
            Point_<ValueT,Dims> result;
            for( size_t i=0; i < this->m_data.size(); i++ )
            {
                result.m_data[i] = this->m_data[i] + rhs.m_data[i];
            }
            return result;
        }

        /**
         * Addition assignment operator
        */
        template <typename OtherT>
        Point_<ValueT,Dims>& operator += ( const Point_<OtherT,Dims>& rhs )
        {
            for( size_t i = 0; i < this->m_data.size(); i++ )
            {
                this->m_data[i] += rhs.m_data[i];
            }
            return (*this);
        }

        /**
         * Subtraction assignment operator
        */
        template <typename OtherT>
        Point_<ValueT,Dims>& operator -= ( const Point_<OtherT,Dims>& rhs )
        {
            for( size_t i = 0; i < this->m_data.size(); i++ )
            {
                this->m_data[i] -= rhs.m_data[i];
            }
            return (*this);
        }

        /**
         * Return the number of elements or "dimensions"
        */
        size_t size() const
        {
            return this->m_data.size();
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
         * Subtraction Operator
        */
        template< typename OtherValueT>
        Point_<ValueT,Dims> operator - ( const Vector_<OtherValueT,Dims>& rhs ) const
        {
            Point_<ValueT,Dims> result;
            for( size_t i=0; i < this->m_data.size(); i++ )
            {
                result.m_data[i] = this->m_data[i] - rhs.m_data[i];
            }
            return result;
        }

        /**
         * Return the element-wise min of N points
         *
         * Really F-ing cool solution:
         *  https://stackoverflow.com/a/63330289/2142228
        */
        template< typename    Point1,
                  typename    Point2,
                  typename... Tail>
        static constexpr Point1 elementwise_min( const Point1&  point1,
                                                 const Point2&  point2,
                                                 const Tail&... tail )
        {
            if constexpr (sizeof...(tail) == 0)
            {
                Point1 result;
                for( size_t i=0; i < result.size(); i++ )
                {
                    result[i] = std::min( point1[i],
                                          static_cast<typename Point1::value_type>( point2[i] ) );
                }
                return std::move( result );
            }
            else
            {
                return elementwise_min( elementwise_min( point1,
                                                         point2 ),
                                        tail... );
            }
        }

        /**
         * Return the element-wise max of N points
        */
        template< typename    Point1,
                  typename    Point2,
                  typename... Tail>
        static constexpr Point1 elementwise_max( const Point1&  point1,
                                                 const Point2&  point2,
                                                 const Tail&... tail )
        {
            if constexpr (sizeof...(tail) == 0)
            {
                Point1 result;
                for( size_t i=0; i < result.size(); i++ )
                {
                    result[i] = std::max( point1[i],
                                          static_cast<typename Point1::value_type>( point2[i] ) );
                }
                return std::move( result );
            }
            else
            {
                return elementwise_max( elementwise_max( point1,
                                                         point2 ),
                                        tail... );
            }
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