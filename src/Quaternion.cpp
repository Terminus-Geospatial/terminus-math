/**
 * @file    Quaternion.cpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#include "Quaternion.hpp"

// Terminus Libraries
#include "vector/Vector_Utilities.hpp"

// C++ Libraries
#include <cmath>

namespace tmns::math {

/********************************************/
/*          Parameterized Constructor       */
/********************************************/
Quaternion::Quaternion( double real,
                        double x,
                        double y,
                        double z )
 : m_real( real ),
   m_imag( ToVector3<double>( x, y, z ) )
{
}

/********************************************/
/*          Parameterized Constructor       */
/********************************************/
Quaternion::Quaternion( double          real,
                        const Vector3d& imag )
 : m_real( real ),
   m_imag( imag )
{
}

/**********************************/
/*      Get the Real Component    */
/**********************************/
double Quaternion::real() const
{
    return m_real;
}

/****************************************/
/*      Get the Imaginary Component     */
/****************************************/
Vector3d Quaternion::imag() const
{
    return m_imag;
}

/************************************/
/*      Quaternion magnitude        */
/************************************/
double Quaternion::magnitude() const
{
    return std::sqrt( magnitude_sq() );
}

/********************************/
/*      Squared Magnitude       */
/********************************/
double Quaternion::magnitude_sq() const
{
    return ( m_real * m_real ) + m_imag.magnitude_sq();
}

/****************************************/
/*      Normalize the Quaternion        */
/****************************************/
Quaternion Quaternion::normalize() const
{
    auto mag = magnitude();
    return Quaternion( m_real / mag, m_imag / mag );
}

/****************************************/
/*          Quaternion Conjugate        */
/****************************************/
Quaternion Quaternion::conj() const
{
    return Quaternion( m_real, m_imag * -1 );
}

/****************************************/
/*          Quaternion Inverse          */
/****************************************/
Quaternion Quaternion::inverse() const
{
    return conj() / normalize();
}

/****************************************/
/*          Quaternion Division         */
/****************************************/
Quaternion Quaternion::operator / ( const Quaternion& rhs ) const
{
    // Reference:  https://www.boost.org/doc/libs/1_83_0/boost/math/quaternion.hpp
    //      Operator /=
    auto denom = magnitude();

    auto real = ( m_real * rhs.m_real + Vector3d::dot( m_imag, rhs.m_imag ) ) / denom;
    Vector3d imag;
    imag.x() = ( -m_real * rhs.m_imag.x() ) + ( m_imag.x() * rhs.m_real     ) + ( m_imag.y() * rhs.m_imag.z() ) + ( m_imag.z() * rhs.m_imag.y() );
    imag.y() = ( -m_real * rhs.m_imag.y() ) + ( m_imag.x() * rhs.m_imag.z() ) + ( m_imag.y() * rhs.m_real     ) - ( m_imag.z() * rhs.m_imag.x() );
    imag.z() = ( -m_real * rhs.m_imag.z() ) - ( m_imag.x() * rhs.m_imag.y() ) + ( m_imag.y() * rhs.m_imag.x() ) + ( m_imag.z() * rhs.m_real     );
    
    return Quaternion( real, imag / denom );
}

} // end of tmns::math API