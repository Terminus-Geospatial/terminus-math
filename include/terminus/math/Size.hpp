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
class Size
{
    public:


    private:

        /// Underlying Data Structure
        Vector_<ValueT,Dims> m_data;

}; // End of Size Class

} // End of tmns::math namespace