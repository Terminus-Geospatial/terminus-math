/**
 * @file    Rectangle.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// Terminus Libraries
#include "Point_Utilities.hpp"

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