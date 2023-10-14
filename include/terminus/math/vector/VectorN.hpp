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
class Vector_<ValueT,0> : public Vector_Base<Vector_<ValueT>>
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
         * Default Constructor
         */
        Vector_() = default;

        /**
         * @brief Constructor from any other Vector type.
         */
        template <typename OtherVectorT>
        Vector_( const Vector_Base<OtherVectorT>& v )
            : m_data( v.impl().begin(),
                      v.impl().end() )
        {
        }

        /**
         * @brief Create a zero vector of the specific size
         */
        Vector_( size_t vector_size )
            : m_data( vector_size, 0 )
        {}

        /**
         * @brief Create a vector of the specific size and value
         */
        Vector_( size_t vector_size, ValueT val )
            : m_data( vector_size, val )
        {}

        /**
         * @brief Constructor Given an Array
         */
        Vector_( std::initializer_list<ValueT> data )
          : m_data( data )
        {
        }

        /**
         * General Assignment Operator
         */
        Vector_& operator = ( const Vector_& v )
        {
            Vector_ temp( v );
            m_data = temp.m_data;
            return (*this);
        }

        /**
         * Assignment operator for any vector type.
         */
        template <typename OtherVectorT>
        Vector_& operator = ( const Vector_Base<OtherVectorT>& v )
        {
            Vector_ tmp( v );
            m_data = tmp.m_data;
            return *this;
        }

        /**
         * Temporary-free generalized assignment operator, from arbitrary vector expressions.
         * This is a performance-optimizing function to be used with caution!
         */
        template <typename T>
        Vector_& operator=( const Vector_No_Tmp<T>& v )
        {
            return *this = v.impl();
        }

        /**
         * Get the current size of the array
        */
        size_t size() const
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
        const_reference_type operator[]( size_t idx ) const
        {
            return this->m_data[idx];
        }

        /**
         * Index Reference Operator
         */
        reference_type operator[]( size_t idx )
        {
            return this->m_data[idx];
        }

        /**
         * Call Operator
        */
        const_reference_type operator()( size_t idx ) const
        {
            return this->m_data[idx];
        }

        /**
         * Call Reference Operator
         */
        reference_type operator()( size_t idx )
        {
            return this->m_data[idx];
        }

        /**
         * Get copy of internal data at specific index
        */
        const_reference_type at( size_t idx ) const
        {
            return m_data.at(idx);
        }

        /**
         * Get reference to internal data at specific index
        */
        reference_type at( size_t idx )
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

        /**
         * Perform a Dot-Product
         */
        template <typename Vector1T,
                  typename Vector2T>
        static double dot( const Vector_Base<Vector1T>& vec1,
                           const Vector_Base<Vector2T>& vec2 )
        {
            double mag = 0;

            auto it1 = vec1.impl().begin();
            auto it2 = vec2.impl().begin();
            for( ; it1 != vec1.impl().end(); it1++, it2++ )
            {
                mag += (*it1) * (*it2);
            }
            return mag;
        }

    private:

        std::vector<ValueT> m_data;

}; // End of Vector_<ValueT,0> Class

template <typename ValueT>
using VectorN = Vector_<ValueT,0>;

} // End of tmns::math namespace