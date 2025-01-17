/*
 * LatchedSwitch.cpp
 *
 *  Created on: 17 Jan 2025
 *      Author: jondurrant
 */

#include "LatchedSwitch.h"

LatchedSwitch::LatchedSwitch(uint8_t gpioPad) {
	xGP = gpioPad;

	 gpio_init(xGP);
	 gpio_set_dir(xGP, GPIO_IN);
	 gpio_pull_up(xGP);

}

LatchedSwitch::~LatchedSwitch() {
	// TODO Auto-generated destructor stub
}

void LatchedSwitch::poll(){
	bool pressed = !(bool)gpio_get(xGP);
	if (pressed ){
		if ( !xPressed){
			if (!isBounce()){
				xPressed = true;
				xOn = !xOn;
			}
		}
	} else {
		if (xPressed){
			if (!isBounce()){
				xPressed = false;
			}
		}
	}
}

bool LatchedSwitch::isPressed(){
	return xPressed;
}

bool LatchedSwitch::isLatchOn(){
	return xOn;
}

bool  LatchedSwitch::isBounce(){
	uint32_t now =  to_ms_since_boot(get_absolute_time ());
	uint32_t since = now - xLast;
	if (since < SWITCH_MIN_MS){
		return true;
	}
	xLast = now;
	return false;
}
