/*
 * cppMemory.cpp
 *
 *  Created on: 30 Jun 2023
 *      Author: jondurrant
 */

#include "pico/stdlib.h"

#include "FreeRTOS.h"


void * operator new( size_t size ){
    return pvPortMalloc( size );
}

void * operator new[]( size_t size ){
    return pvPortMalloc(size);
}

void operator delete( void * ptr ){
    vPortFree ( ptr );
}

void operator delete[]( void * ptr ){
    vPortFree ( ptr );
}

