cmake_minimum_required(VERSION 3.15)

add_library(freertos_config STATIC)

target_sources(freertos_config PUBLIC   
        ${CMAKE_CURRENT_LIST_DIR}/idleMemory.c
        ${CMAKE_CURRENT_LIST_DIR}/cppMemory.cpp
    )
target_include_directories(freertos_config PUBLIC
	${CMAKE_CURRENT_LIST_DIR}
	) # The config file directory\n"
target_compile_definitions(freertos_config
	PUBLIC  projCOVERAGE_TEST=0
	)
target_link_libraries(freertos_config
	FreeRTOS-Kernel
	pico_stdlib
	)