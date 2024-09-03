if (DEFINED EIGEN_PATH)
	message("Using Given EIGEN_PATH '${EIGEN_PATH}')")
else ()
	set(EIGEN_PATH "${CMAKE_CURRENT_LIST_DIR}lib/eigen/")
    message("Using local EIGEN_PATH '${EIGEN_PATH}')")
endif ()

add_library(eigen INTERFACE)


# Add include directory
target_include_directories(eigen INTERFACE 
    ${EIGEN_PATH}
)
