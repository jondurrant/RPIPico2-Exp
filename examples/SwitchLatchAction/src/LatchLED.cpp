/*
 * LatchLED.cpp
 *
 *  Created on: 17 Jan 2025
 *      Author: jondurrant
 */

#include "LatchLED.h"

LatchLED::LatchLED(uint8_t gp){
	xGP = gp;

	 gpio_init(xGP);
	 gpio_set_dir(xGP, GPIO_OUT);
	 gpio_put(xGP, false);

}

LatchLED::~LatchLED() {
	// TODO Auto-generated destructor stub
}


void LatchLED::action(bool latchOn) {
	 gpio_put(xGP, latchOn);

}
