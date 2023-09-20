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

        /// @brief Value Type
        using value_type = ValueT;

        /// @brief Array Type
        using array_type = std::vector<value_type>;

        /// @brief Reference Type
        using reference_type = ValueT&;

        /// @brief Const Reference Type
        using const_reference_type = const ValueT&;

        /// @brief Iterator Type
        using iter_t = typename array_type::iterator;

        /// @brief Const Iterator Type
        using const_iter_t = typename array_type::const_iterator;


        /**
         * @brief Create an empty vector
         */
        VectorN() = default;

        /**
         * @brief Create a zero vector of the specific size
         */
        VectorN( size_t vector_size )
            : m_data( vector_size, 0 )
        {}

        /**
         * @brief Constructor Given an Array
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
        const_reference_type operator[]( size_t idx ) const override
        {
            return this->m_data[idx];
        }

        /**
         * Index Reference Operator
         */
        reference_type operator[]( size_t idx ) override
        {
            return this->m_data[idx];
        }

        /**
         * Get copy of internal data at specific index
        */
        const_reference_type at( size_t idx ) const override
        {
            return m_data.at(idx);
        }

        /**
         * Get reference to internal data at specific index
        */
        reference_type at( size_t idx ) override
        {
            return m_data.at(idx);
        }

        /**
         * @brief Get X Value
         */
        const_reference_type x() const
        {
            return m_data[0];
        }

        /**
         * @brief Get X Reference
         */
        reference_type x()
        {
            return m_data[0];
        }

        /**
         * @brief Get Y Value
         */
        const_reference_type y() const
        {
            return m_data[1];
        }

        /**
         * @brief Get Y Reference
         */
        reference_type y()
        {
            return m_data[1];
        }

        /**
         * @brief Get Z Value
         */
        const_reference_type z() const
        {
            return m_data[2];
        }

        /**
         * @brief Get Z Reference
         */
        reference_type z()
        {
            return m_data[2];
        }

        /**
         * Get the starting iterator position
         */
        iter_t begin()
        {
            return m_data.begin();
        }

        /**
         * Get the starting iterator position
         */
        const_iter_t begin() const
        {
            return m_data.begin();
        }

        /**
         * Get the ending iterator position
         */
        iter_t end()
        {
            return m_data.end();
        }

        /**
         * Get the ending iterator position
         */
        const_iter_t end() const
        {
            return m_data.end();
        }

        /**
         * @brief Add entry to vector
         */
        void push_back( ValueT new_entry )
        {
            m_data.push_back( new_entry );
        }

        /**
         * @brief Set all elements in the vector
         */
        template <typename TP>
        void fill( TP value )
        {
            std::fill( begin(),
                       end(),
                       value );
        }

    private:

        std::vector<ValueT> m_data;

}; // End of VectorN Class

} // End of tmns::math namespace