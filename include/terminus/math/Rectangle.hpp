/**
 * @file    Rectangle.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// Terminus Libraries
#include "Point_Utilities.hpp"
#include "Vector_Utilities.hpp"

// C++ Libraries
#include <cmath>

namespace tmns::math {

/**
 * Rectangle
*/
template <typename ValueT>
class Rectangle
{
    public:

        /**
         * Default constructor
        */
        Rectangle() = default;

        /**
         * Parameterized Constructor
         *
         * @param x
         * @param y
         * @param width
         * @param height
        */
        Rectangle( const ValueT& x,
                   const ValueT& y,
                   const ValueT& width,
                   const ValueT& height )
          : m_bl( ToPoint2<ValueT>( x, y ) ),
            m_width( width ),
            m_height( height )
        {}

        /**
         * Parameterized Constructor
         *
         * @param bl Bottom-Left Corner
         * @param width
         * @param height
        */
        Rectangle( const Point2_<ValueT>& bl,
                   const ValueT&          width,
                   const ValueT&          height )
          : m_bl( bl ),
            m_width( width ),
            m_height( height )
        {}

        /**
         * Parameterized Constructor
         *
         * @param min_corner
         * @param max_corner
        */
        Rectangle( const Point2_<ValueT>& min_corner,
                   const Point2_<ValueT>& max_corner )
          : m_bl( ToPoint2<ValueT>( std::min( min_corner.x(),
                                              max_corner.x() ),
                                    std::min( min_corner.y(),
                                              max_corner.y() ) ) ),
            m_width(  std::fabs( max_corner.x() - min_corner.x() ) ),
            m_height( std::fabs( max_corner.y() - min_corner.y() ) )
        {}


        /**
         * Get the Width
        */
        ValueT width() const
        {
            return m_width;
        }

        /**
         * Get the height
        */
        ValueT height() const
        {
            return m_height;
        }

        /**
         * Get the bottom-left corner
        */
        Point2_<ValueT> bl() const
        {
            return m_bl;
        }

        /**
         * Get the top-left corner
        */
        Point2_<ValueT> tl() const
        {
            return m_bl + math::ToPoint2<double>( 0, m_height );
        }

        /**
         * Get the bottom-left corner
        */
        Point2_<ValueT> tr() const
        {
            return m_bl + math::ToPoint2<double>( m_width,
                                                  m_height );
        }

        /**
         * Get the bottom-left corner
        */
        Point2_<ValueT> br() const
        {
            return m_bl + math::ToPoint2<double>( m_width, 0 );
        }

        /**
         * Return point of the minimum range
        */
        Point2_<ValueT> min() const
        {
            return bl();
        }

        /**
         * Return point of the maximum range
        */
        Point2_<ValueT> max() const
        {
            return tr();
        }

        /**
         * Shift the rectangle by the specified amount
         */
        Rectangle<ValueT> operator + ( const Point2_<ValueT>& offset ) const
        {
            return Rectangle<ValueT>( bl() + offset,
                                      width(),
                                      height() );
        }

        /**
         * Shift the rectangle by the specified amount
         */
        Rectangle<ValueT> operator + ( const Vector2_<ValueT>& offset ) const
        {
            return Rectangle<ValueT>( bl() + offset,
                                      width(),
                                      height() );
        }

        /**
         * Shift the rectangle by the specified amount
         */
        Rectangle<ValueT> operator - ( const Point2_<ValueT>& offset ) const
        {
            return Rectangle<ValueT>( bl() - offset,
                                      width(),
                                      height() );
        }

        /**
         * Shift the rectangle by the specified amount
         */
        Rectangle<ValueT> operator - ( const Vector2_<ValueT>& offset ) const
        {
            return Rectangle<ValueT>( bl() - offset,
                                      width(),
                                      height() );
        }

        /**
         * Check if point inside bounding box.
        */
        template <typename PointValueT>
        bool is_inside( const Point2_<PointValueT>& pt ) const
        {
            return ( pt.x() >= bl().x() &&
                     pt.x() <= tr().x() &&
                     pt.y() >= bl().y() &&
                     pt.y() <= tr().y() );
        }

        /**
         * Check if rectangle is inside bounding box
        */
        template <typename OtherValueT>
        bool is_inside( const Rectangle<OtherValueT>& obox ) const
        {
            return ( bl().x() <= obox.bl().x() &&
                     bl().y() <= obox.bl().y() &&
                     tr().x() >= obox.tr().x() &&
                     tr().y() >= obox.tr().y() );
        }

        /**
         * Compute the Rectangle Intersection
        */
        template <typename ValueT1, typename ValueT2>
        static Rectangle<ValueT1> intersection( const Rectangle<ValueT1>& rect1,
                                                const Rectangle<ValueT2>& rect2 )
        {
            return Rectangle<ValueT1>( Point2_<ValueT1>::elementwise_max( rect1.min(),
                                                                          rect2.min() ),
                                       Point2_<ValueT1>::elementwise_min( rect1.max(),
                                                                          rect2.max() ) );
        }

        /**
         * Print to log-friendly string
        */
        std::string to_string() const
        {
            std::stringstream sout;
            sout << "Rectangle<>: bl: " << bl().to_string() << ", width: " << width() << ", height: " << height();
            return sout.str();
        }

    private:

        Point2_<ValueT> m_bl;
        ValueT m_width;
        ValueT m_height;

}; // End of Box class

// Common aliases
using Rect2i = Rectangle<int>;
using Rect2f = Rectangle<float>;
using Rect2d = Rectangle<double>;

} // end of tmns::math