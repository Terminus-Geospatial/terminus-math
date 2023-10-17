/**
 * @file    Vector_Functors.hpp
 * @author  Marvin Smith
 * @date    10/15/2023
 */
#pragma once

// Terminus Libraries
#include <terminus/math/vector/Vector_Base.hpp>

// C++ Libraries
#include <type_traits>

// Boost Libraries
#include <boost/iterator/iterator_facade.hpp>

namespace tmns::math {

/**
 * A binary elementwise vector function class.
 */
template <typename Vector1T,
          typename Vector2T,
          typename FunctorT>
class Vector_Binary_Functor : public Vector_Base<Vector_Binary_Functor<Vector1T,Vector2T,FunctorT>>
{
    public:
        
        // Underlying Data Type
        using value_type = std::invoke_result_t<FunctorT,
                                                typename Vector1T::value_type,
                                                typename Vector2T::value_type>;

        // Reference Type
        using reference_type = value_type;

        // Const Reference Type
        using const_reference_type = value_type;

        /**
         * Overloaded iterator
         */
        class Iterator : public boost::iterator_facade<Iterator,
                                                       value_type,
                                                       boost::random_access_traversal_tag,
                                                       reference_type>
        {
            public:
                
                Iterator( const typename Vector1T::const_iter_t& i1,
                          const typename Vector2T::const_iter_t& i2,
                          const FunctorT&                        func )
                    : m_i1( i1 ),
                      m_i2( i2 ),
                      m_func( func ) {}

            private:

                // Give boost access
                friend class boost::iterator_core_access;

                bool equal( const Iterator& iter ) const 
                {
                    return ( m_i1 == iter.m_i1 ) && ( m_i2 == iter.m_i2 );
                }

                typename Iterator::difference_type distance_to( const Iterator& iter ) const
                {
                    return iter.m_i1 - m_i1;
                }
                
                void increment()
                {
                    ++m_i1;
                    ++m_i2;
                }
                
                void decrement()
                {
                    --m_i1;
                    --m_i2;
                }
                
                void advance( typename Iterator::difference_type n )
                {
                    m_i1 += n;
                    m_i2 += n;
                }
                
                typename Iterator::reference dereference() const
                {
                    return m_func( *m_i1, *m_i2 );
                }

                typename Vector1T::const_iter_t m_i1;
                typename Vector2T::const_iter_t m_i2;
                FunctorT m_func;
        };

        /**
         * Constructor
        */
        Vector_Binary_Functor( const Vector1T& v1,
                               const Vector2T& v2 )
            : m_vec1( v1 ),
              m_vec2( v2 ),
              m_func()
        {
            if( v1.size() != v2.size() )
            {
                std::stringstream sout;
                sout << "Vectors are not the same size. Actual: " << v1.size() << " vs " << v2.size();
                throw std::runtime_error( sout.str() );
            }
        }

        template <typename Argument1>
        Vector_Binary_Functor( const Vector1T& v1,
                               const Vector2T& v2,
                               Argument1       a1 )
            : m_vec1( v1 ),
              m_vec2( v2 ),
              m_func( a1 )
        {
            if( v1.size() != v2.size() )
            {
                std::stringstream sout;
                sout << "Vectors are not the same size. Actual: " << v1.size() << " vs " << v2.size();
                throw std::runtime_error( sout.str() );
            }
        }

        Vector1T const& child1() const
        {
            return m_vec1;
        }

        Vector2T const& child2() const
        { 
            return m_vec2;
        }

        size_t size() const
        {
            return child1().size();
        }

        const_reference_type operator()( size_t i ) const
        {
            return m_func( child1()(i),
                           child2()(i) );
        }

        const_reference_type operator[]( size_t i ) const
        {
            return m_func( child1()[i],
                           child2()[i] );
        }

        using iter_t = Iterator;
        using const_iter_t = Iterator;
        
        /**
         * Get the beginning iterator position
         */
        Iterator begin() const
        {
            return Iterator( child1().begin(),
                             child2().begin(),
                             m_func );
        }

        /**
         * Get the end iterator position
         */
        Iterator end() const
        {
            return Iterator( child1().end(),
                             child2().end(),
                             m_func );
        }

    private:

        const Vector1T& m_vec1;
        const Vector2T& m_vec2;
        FunctorT m_func;

}; // End of Vector_Binary_Functor class

template <typename Vector1T,
          typename Vector2T,
          typename FunctorT>
struct Vector_Size<Vector_Binary_Functor<Vector1T,Vector2T,FunctorT>>
{
    static const size_t value = (Vector_Size<Vector1T>::value!=0)?(Vector_Size<Vector1T>::value):(Vector_Size<Vector2T>::value);
};

} // End of tmns::math namespace