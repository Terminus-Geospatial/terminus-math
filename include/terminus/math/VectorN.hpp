/**
 * @file    VectorN.hpp
 * @author  Marvin Smith
 * @date    7/30/2023
*/
#pragma once

// Terminus Math Libraries
#include "Vector.hpp"

// C++ Libraries
#include <initializer_list>

namespace tmns::math {

/**
 * @class VectorN
 * N-dimensional, resizable vector
*/
template <typename ValueT>
class VectorN : public Vector_<ValueT,0>
{
    public:

        VectorN() = default;

        /**
         * Constructor Given an Array
        */
        VectorN( std::initializer_list<ValueT> data )
          : m_data( data )
        {
        }

        /**
         * Get the current size of the array
        */
        size_t size() const override
        {
            return m_data.size();
        }

        /**
         * Clear the array
         */
        void clear()
        {
            m_data.clear();
        }

        /**
         * Index Operator
        */
        ValueT operator[]( size_t idx ) const override
        {
            return this->m_data[idx];
        }

        /**
         * Index Reference Operator
         */
        ValueT& operator[]( size_t idx ) override
        {
            return this->m_data[idx];
        }

        /**
         * Get copy of internal data at specific index
        */
        ValueT at( size_t idx ) const override
        {
            return m_data.at(idx);
        }

        /**
         * Get reference to internal data at specific index
        */
        ValueT& at( size_t idx ) override
        {
            return m_data.at(idx);
        }

        void push_back( ValueT new_entry )
        {
            m_data.push_back( new_entry );
        }

    private:

        std::vector<ValueT> m_data;

}; // End of VectorN Class

} // End of tmns::math namespace