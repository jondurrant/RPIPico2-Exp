/*
 * LatchedSwitch.h
 *
 *  Created on: 17 Jan 2025
 *      Author: jondurrant
 */

#ifndef EXAMPLES_SWITCHLATCHPOLL_SRC_LATCHEDSWITCH_H_
#define EXAMPLES_SWITCHLATCHPOLL_SRC_LATCHEDSWITCH_H_

#include "pico/stdlib.h"
#include "LatchAction.h"

#define SWITCH_MIN_MS 200

class LatchedSwitch {
public:
	LatchedSwitch(uint8_t gpioPad);
	virtual ~LatchedSwitch();

	/***
	 * True if the switch is in the latched on state
	 * @return
	 */
	bool isLatchOn();


	/***
	 * Set action to control
	 * @param act
	 */
	void setAction(LatchAction *act);

private:
	/***
	 * Remove any bouncing of the switch
	 * @return
	 */
	bool isBounce();

	static void gpioCBStatic(uint gpio, uint32_t events);
	static LatchedSwitch *pSelf;
	void gpioCB(uint gpio, uint32_t events);

	uint32_t xLast = 0;
	uint8_t xGP;
	bool xOn = false;
	LatchAction *pAction = NULL;
};

#endif /* EXAMPLES_SWITCHLATCHPOLL_SRC_LATCHEDSWITCH_H_ */
