/**
 * @file    Size.hpp
 * @author  Marvin Smith
 * @date    7/20/2023
*/
#pragma once

// Terminus Math Libraries
#include "Vector.hpp"

namespace tmns::math {

/**
 * Simple data structure for dimensional sizes info without ranges
 * Rectangle is a good class for size, but it has corners.
*/
template <typename ValueT, int Dims>
class Size_
{
    public:

        /// Value Type
        typedef ValueT value_type;

        /// Number of dimensions
        

        /// Default Constructor
        Size_() = default;

        /**
         * Parameterized Constructor
        */
        Size_( const std::array<ValueT,Dims>& data )
         : m_data( data )
        {
        }

        /**
         * Get the width
        */
        ValueT width() const
        {
            return m_data.x();
        }

        /**
         * Get the width value
        */
        ValueT& width()
        {
            return m_data.x();
        }

        /**
         * Get the height
        */
        ValueT height() const
        {
            return m_data.y();
        }

        /**
         * Get the height value
        */
        ValueT& height()
        {
            return m_data.y();
        }

        /**
         * Get the depth value
        */
        ValueT& depth()
        {
            if( Dims < 3 )
            {
                throw std::runtime_error("Cannot call a 3d member on structure with < 3 dimensions." );
            }
            return m_data.z();
        }

        /**
         * Indexing Operator (Const/Copy)
        */
        ValueT operator[]( size_t id ) const
        {
            return m_data[id];
        }

        /**
         * Indexing Operator (Ref)
        */
        ValueT& operator[]( size_t id )
        {
            return m_data[id];
        }

        /**
         * Convert to a string
        */
        std::string to_string() const
        {
            std::stringstream sout;
            sout << "Size (Dims: " << Dims << ", Width: " << std::fixed << width() << ", Height: " << height() << ")";
            return sout.str();
        }

    private:

        /// Underlying Data Structure
        Vector_<ValueT,Dims> m_data { { 0 } };

}; // End of Size Class

/// Simple Aliases
using Size2i = Size_<int,2>;
using Size3i = Size_<int,3>;
using Size2f = Size_<float,2>;
using Size3f = Size_<float,3>;
using Size2d = Size_<double,2>;
using Size3d = Size_<double,3>;

} // End of tmns::math namespace