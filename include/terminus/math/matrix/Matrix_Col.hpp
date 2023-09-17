/**
 * @file    Matrix_Col.hpp
 * @author  Marvin Smith
 * @date    9/16/2023
 */
#pragma once

// Terminus Libraries
#include "../vector/Vector_Base.hpp"

namespace tmns::math::matrix {

/**
 * Structure for representing column semantics
 */
template <typename MatrixT>
class Matrix_Col : public vector::Vector_Base<Matrix_Col<MatrixT> >
{
    public:




    private:

        /// @brief  Underlying Matrix
        MatrixT& m_matrix;

        /// @brief  Column ID
        size_t m_col;

    

  public:
    typedef typename MatrixT::value_type value_type;

    typedef typename boost::mpl::if_<boost::is_const<MatrixT>,
                                     typename MatrixT::const_reference_type,
                                     typename MatrixT::reference_type>::type reference_type;
    typedef typename MatrixT::const_reference_type const_reference_type;

    typedef typename boost::mpl::if_<boost::is_const<MatrixT>,
                                     Iterator<typename MatrixT::const_iterator>,
                                     Iterator<typename MatrixT::iterator> >::type iterator;
    typedef Iterator<typename MatrixT::const_iterator> const_iterator;

    MatrixCol( MatrixT& m, size_t col ) : m(m), col(col) {}

    /// Standard copy assignment operator.
    MatrixCol& operator=( MatrixCol const& v ) {
      VW_ASSERT( v.size()==size(), ArgumentErr() << "Vectors must have same size in matrix column assignment." );
      Vector<value_type> tmp( v );
      std::copy( tmp.begin(), tmp.end(), begin() );
      return *this;
    }

    /// Generalized assignment operator, from arbitrary VW matrix expressions.
    template <class OtherT>
    MatrixCol& operator=( VectorBase<OtherT> const& v ) {
      VW_ASSERT( v.impl().size()==size(), ArgumentErr() << "Vectors must have same size in matrix column assignment." );
      Vector<value_type> tmp( v );
      std::copy( tmp.begin(), tmp.end(), begin() );
      return *this;
    }

    /// Temporary-free generalized assignment operator, from arbitrary VW vector expressions.
    /// This is a performance-optimizing function to be used with caution!
    template <class OtherT>
    MatrixCol& operator=( VectorNoTmp<OtherT> const& v ) {
      VW_ASSERT( v.impl().size()==size(), ArgumentErr() << "Vectors must have same size in matrix column assignment." );
      std::copy( v.impl().begin(), v.impl().end(), begin() );
      return *this;
    }

    MatrixT      & child()       { return m; }
    MatrixT const& child() const { return m; }

    size_t size() const { return child().rows(); }

          reference_type operator()( size_t i )       { return child()(i,col); }
    const_reference_type operator()( size_t i ) const { return child()(i,col); }
          reference_type operator[]( size_t i )       { return child()(i,col); }
    const_reference_type operator[]( size_t i ) const { return child()(i,col); }

          iterator begin()       { return       iterator( child().begin() + col, child().cols() ); }
    const_iterator begin() const { return const_iterator( child().begin() + col, child().cols() ); }
          iterator end  ()       { return begin() + size(); }
    const_iterator end  () const { return begin() + size(); }

  };


} // End of tmns::math::matrix namespace