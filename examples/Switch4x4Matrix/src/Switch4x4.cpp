/*
 * Switch4x4.cpp
 *
 *  Created on: 18 Jan 2025
 *      Author: jondurrant
 */

#include "Switch4x4.h"
#include <cstdio>

Switch4x4 *Switch4x4::pSelf  = NULL;

Switch4x4::Switch4x4(
		uint8_t row1GP,
		uint8_t row2GP,
		uint8_t row3GP,
		uint8_t row4GP,
		uint8_t col1GP,
		uint8_t col2GP,
		uint8_t col3GP,
		uint8_t col4GP
		){
	Switch4x4::pSelf = this;
	xRowGPs[0] = row1GP;
	xRowGPs[1] = row2GP;
	xRowGPs[2] = row3GP;
	xRowGPs[3] = row4GP;
	xColGPs[0] = col1GP;
	xColGPs[1] = col2GP;
	xColGPs[2] = col3GP;
	xColGPs[3] = col4GP;

	for (int i=0; i < 4; i++){
		 //ROW as source
		 gpio_init(xRowGPs[i]);
		 gpio_set_dir(xRowGPs[i], GPIO_OUT);
		 gpio_put(xRowGPs[i], false);

		 //COL as sensing
		 gpio_init(xColGPs[i]);
		 gpio_set_dir(xColGPs[i], GPIO_IN);
		 gpio_pull_up(xColGPs[i]);
		 gpio_set_irq_enabled_with_callback(
				 xColGPs[i],
				 GPIO_IRQ_EDGE_FALL,
				 true,
				 Switch4x4::gpioCBStatic
				 );
	}

}

Switch4x4::~Switch4x4() {
	// TODO Auto-generated destructor stub
}


bool Switch4x4::isAvailable(){
	return !xQueue.empty();
}

int8_t Switch4x4::readInt(){
	if (xQueue.empty()){
		return -1;
	}
	int8_t res = xQueue.front();
	xQueue.pop();
	return res;
}

bool  Switch4x4::isBounce(){
	uint32_t now =  to_ms_since_boot(get_absolute_time ());
	uint32_t since = now - xLast;
	if (since < SWITCH_MIN_MS){
		return true;
	}
	xLast = now;
	return false;
}

void Switch4x4::gpioCBStatic(uint gpio, uint32_t events){
	if (pSelf != NULL){
		pSelf->gpioCB(gpio, events);
	}
}

void Switch4x4::gpioCB(uint gpio, uint32_t events){
	int8_t res ;

	for (int8_t c=0; c < 4; c++){
		if (gpio == xColGPs[c]){
			if (isBounce()){
				return;
			}

			//printf("Col is %d (%u)\n", c, gpio);

			//Disable the IRQ
			gpio_set_irq_enabled (
					 xColGPs[c],
					 GPIO_IRQ_EDGE_FALL,
					 false
					);


			for (int8_t r=0; r < 4; r++){
				gpio_put(xRowGPs[r], true);
				if (gpio_get(xColGPs[c])){
					//printf("Row is %d\n", r);
					gpio_put(xRowGPs[r], false);

					res = (r << 2) | c;
					xQueue.push(res);
				} else {
					gpio_put(xRowGPs[r], false);
				}

				//Enable IRQ again
				gpio_set_irq_enabled (
					 xColGPs[c],
					 GPIO_IRQ_EDGE_FALL,
					 true
					);

			} //for row
		} //if
	} //for col
}


