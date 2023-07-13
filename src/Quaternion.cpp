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

} // end of tmns::math API