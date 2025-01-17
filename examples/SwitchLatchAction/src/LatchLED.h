/*
 * LatchLED.h
 *
 *  Created on: 17 Jan 2025
 *      Author: jondurrant
 */

#ifndef EXAMPLES_SWITCHLATCHACTION_SRC_LATCHLED_H_
#define EXAMPLES_SWITCHLATCHACTION_SRC_LATCHLED_H_
#include "pico/stdlib.h"
#include "LatchAction.h"

class LatchLED : public LatchAction{
public:
	LatchLED(uint8_t gp);
	virtual ~LatchLED();


	virtual void action(bool latchOn) ;

private:
	uint8_t xGP;
};

#endif /* EXAMPLES_SWITCHLATCHACTION_SRC_LATCHLED_H_ */
