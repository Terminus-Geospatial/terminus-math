#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    7/12/2023

include_directories( ../include )

add_library( ${PROJECT_NAME} SHARED
                coordinate/Datum.cpp
                math/linalg/Solvers.cpp
                math/Quaternion.cpp
                math/Quaternion_Utilities.cpp )

target_link_libraries( ${PROJECT_NAME} PUBLIC
    Boost::headers
    Boost::stacktrace
    terminus_core::terminus_core
    terminus_log::terminus_log
    terminus_outcome::terminus_outcome
    GDAL::GDAL
)

terminus_lib_configure( ${PROJECT_NAME} )
