/**
 * @file    Quaternion.cpp
 * @author  Marvin Smith
 * @date    7/12/2023
*/
#include "Quaternion.hpp"

// Terminus Libraries
#include "Vector_Utilities.hpp"

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

} // end of tmns::math API