/*
 * Counter.cpp
 *
 *  Created on: 17 Jan 2024
 *      Author: jondurrant
 */

#include "Counter.h"
#include <cstdio>

Counter *Counter::pSingleton = NULL;

Counter::Counter() {
	// TODO Auto-generated constructor stub

}

Counter::~Counter() {
	// TODO Auto-generated destructor stub
}


Counter * Counter::getInstance(){
	if (Counter::pSingleton == NULL){
		Counter::pSingleton = new Counter;
	}
	return Counter::pSingleton;
}

void Counter::start(){
	xStartTime =  to_ms_since_boot(get_absolute_time());
	for (int i = 0; i < MAX_ID; i++){
		xCounts[i] = 0;
	}
	for (int i = 0; i < MAX_CORES; i++){
		xCoreCounts[i] = 0;
	}
}

void Counter::inc(uint8_t id){
	if (id < MAX_ID){
		if (xStopTime == 0){
			xCounts[id]++;
		}
	}
	xCoreCounts[get_core_num()]++;
}

void Counter::incCore(uint8_t id, uint8_t  core){
	if (id < MAX_ID){
		if (xStopTime == 0){
			xCounts[id]++;
		}
	}
	if (core < MAX_CORES){
		xCoreCounts[core]++;
	}
}

void Counter::report(){
	 xStopTime =  to_ms_since_boot(get_absolute_time());

	 uint32_t sampleTime = xStopTime - xStartTime;

	 printf("Sampled over %d sec and %d ms\n", sampleTime/1000, sampleTime%1000);

	 printf("#\t+Id\t+Core\n");
	 uint32_t total = 0;
	 for (int i = 0; i < MAX_ID; i++){
		 printf("%d:\t%u", i, xCounts[i]);
		 if (i < MAX_CORES){
			 printf("\t%u\n", xCoreCounts[i]);
		 } else {
			 printf("\n");
		 }
		total += xCounts[i] ;
	 }

	 double perSec = (double)total /  ((double) sampleTime / 1000.0);

	 printf("Total: %u \t%f per sec\n", total, perSec);

}
