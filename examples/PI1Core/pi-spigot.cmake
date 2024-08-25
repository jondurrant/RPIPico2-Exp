# Add library cpp files

if (NOT DEFINED PI_SPIGOT_DIR)
    set(PI_SPIGOT_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/pi_spigot")
endif()

add_library(pi_spigot INTERFACE)

# Add include directory
target_include_directories(pi_spigot INTERFACE 
    ${PI_SPIGOT_DIR}/
)

