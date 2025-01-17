/*
 * LatchAction.h
 *
 *  Created on: 17 Jan 2025
 *      Author: jondurrant
 */

#ifndef EXAMPLES_SWITCHLATCHACTION_SRC_LATCHACTION_H_
#define EXAMPLES_SWITCHLATCHACTION_SRC_LATCHACTION_H_

class LatchAction {
public:
	LatchAction();
	virtual ~LatchAction();

	virtual void action(bool latchOn) = 0;
};

#endif /* EXAMPLES_SWITCHLATCHACTION_SRC_LATCHACTION_H_ */
