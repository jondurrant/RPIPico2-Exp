/*
 * LatchedSwitch.cpp
 *
 *  Created on: 17 Jan 2025
 *      Author: jondurrant
 */

#include "LatchedSwitch.h"

LatchedSwitch::LatchedSwitch(uint8_t gpioPad) {
	xGP = gpioPad;
	LatchedSwitch::pSelf = this;

	 gpio_init(xGP);
	 gpio_set_dir(xGP, GPIO_IN);
	 gpio_pull_up(xGP);
	 gpio_set_irq_enabled_with_callback(
			 gpioPad,
			 GPIO_IRQ_EDGE_FALL,
			 true,
			 LatchedSwitch::gpioCBStatic
			 );
}

LatchedSwitch::~LatchedSwitch() {
	// TODO Auto-generated destructor stub
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

void LatchedSwitch::gpioCBStatic(uint gpio, uint32_t events){
	if (pSelf != NULL){
		pSelf->gpioCB(gpio, events);
	}
}
LatchedSwitch *LatchedSwitch::pSelf = NULL;
void LatchedSwitch::gpioCB(uint gpio, uint32_t events){
	if (gpio == xGP){
		if (!isBounce()){
			xOn = ! xOn;
		}
	}
}
