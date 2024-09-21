/*
 * BlinkAgent.h
 *
 * Active agent to run as task and blink and LED on the given GPIO pad
 *
 *  Created on: 15 Aug 2022
 *      Author: jondurrant
 */

#ifndef BLINKAGENT_H_
#define BLINKAGENT_H_

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

#include "Agent.h"


class BlinkAgent: public Agent {
public:
	/***
	 * Constructor
	 * @param gp - GPIO Pad number for LED
	 */
	BlinkAgent(uint8_t gp=0);

	/***
	 * Destructor
	 */
	virtual ~BlinkAgent();


protected:

	/***
	 * Run loop for the agent.
	 */
	virtual void run();


	/***
	 * Get the static depth required in words
	 * @return - words
	 */
	virtual configSTACK_DEPTH_TYPE getMaxStackSize();

	//GPIO PAD for LED
	uint8_t xLedPad = 0;

};


#endif /* BLINKAGENT_H_ */
