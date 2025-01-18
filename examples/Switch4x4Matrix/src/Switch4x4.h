/*
 * Switch4x4.h
 *
 *  Created on: 18 Jan 2025
 *      Author: jondurrant
 */

#ifndef EXAMPLES_SWITCH4X4MATRIX_SRC_SWITCH4X4_H_
#define EXAMPLES_SWITCH4X4MATRIX_SRC_SWITCH4X4_H_

#include "pico/stdlib.h"
#include <queue>

#define SWITCH_MIN_MS 200

class Switch4x4 {
public:
	Switch4x4(
			uint8_t row1GP,
			uint8_t row2GP,
			uint8_t row3GP,
			uint8_t row4GP,
			uint8_t col1GP,
			uint8_t col2GP,
			uint8_t col3GP,
			uint8_t col4GP
			);
	virtual ~Switch4x4();

	bool isAvailable();

	int8_t readInt();

private:
	bool isBounce();
	static void gpioCBStatic(uint gpio, uint32_t events);
	static Switch4x4 *pSelf;
	void gpioCB(uint gpio, uint32_t events);

	uint8_t xRowGPs[4];
	uint8_t xColGPs[4];

	std::queue<int8_t> xQueue;
	uint32_t xLast = 0;
};

#endif /* EXAMPLES_SWITCH4X4MATRIX_SRC_SWITCH4X4_H_ */
