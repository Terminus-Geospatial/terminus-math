/**
 * @file    Rectangle.hpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#pragma once

// Terminus Libraries
#include "Point.hpp"

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