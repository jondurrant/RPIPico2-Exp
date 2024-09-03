add_executable(${NAME}
    main.cpp
    Counter.cpp
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME} 
	pico_stdlib
	pico_multicore
	eigen
	pico_float
	pico_double
)


#pico_set_float_implementation(${NAME} pico)
#pico_set_double_implementation(${NAME} pico)
#pico_set_float_implementation(${NAME} none)
#pico_set_double_implementation(${NAME} none)
#pico_set_float_implementation(${NAME} compiler)
#pico_set_double_implementation(${NAME} compiler)


# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

pico_enable_stdio_usb(${NAME} 0)
pico_enable_stdio_uart(${NAME} 1)
target_compile_definitions(${NAME} PRIVATE
    PICO_DEFAULT_UART_RX_PIN=17
    PICO_DEFAULT_UART_TX_PIN=16
)

