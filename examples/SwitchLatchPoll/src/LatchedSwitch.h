/*
 * LatchedSwitch.h
 *
 *  Created on: 17 Jan 2025
 *      Author: jondurrant
 */

#ifndef EXAMPLES_SWITCHLATCHPOLL_SRC_LATCHEDSWITCH_H_
#define EXAMPLES_SWITCHLATCHPOLL_SRC_LATCHEDSWITCH_H_

#include "pico/stdlib.h"

#define SWITCH_MIN_MS 200

class LatchedSwitch {
public:
	LatchedSwitch(uint8_t gpioPad);
	virtual ~LatchedSwitch();

	/***
	 * Check switch and update state.
	 */
	void poll();

	/***
	 * True if the switch is currently pressed
	 * @return
	 */
	bool isPressed();

	/***
	 * True if the switch is in the latched on state
	 * @return
	 */
	bool isLatchOn();

private:
	/***
	 * Remove any bouncing of the switch
	 * @return
	 */
	bool isBounce();

	uint32_t xLast = 0;
	uint8_t xGP;
	bool xOn = false;
	bool xPressed = false;

};

#endif /* EXAMPLES_SWITCHLATCHPOLL_SRC_LATCHEDSWITCH_H_ */
