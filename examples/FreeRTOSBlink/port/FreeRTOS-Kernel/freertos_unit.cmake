cmake_minimum_required(VERSION 3.15)

add_library(freertos_unit STATIC)

target_sources(freertos_unit PUBLIC   
        ${CMAKE_CURRENT_LIST_DIR}/idleMemory.c
    )
target_include_directories(freertos_unit PUBLIC
	${CMAKE_CURRENT_LIST_DIR}
	) 
target_compile_definitions(freertos_unit PUBLIC  
    projCOVERAGE_TEST=0
    PICO_CXX_DISABLE_ALLOCATION_OVERRIDES
	)
target_link_libraries(freertos_unit
	FreeRTOS-Kernel
	pico_stdlib
	)