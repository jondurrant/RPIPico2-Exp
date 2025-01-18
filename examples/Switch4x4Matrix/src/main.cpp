/**
 * Jon Durrant.
 *
 *  LED on GPIO 15 is Flashed
 *  4x4 Switch matric on GP6 to GP13.
 */

#include "pico/stdlib.h"
#include <stdio.h>

#include "Switch4x4.h"

#define DELAY 500 // in microseconds


const char lookup[17] = "123A456B789C*0#D";

int main() {
    const uint LED_PIN =  15;
    Switch4x4 sw(
    		9, 8, 6, 7, //ROWS
			10,11,12,13 //COLS
    		);

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    bool b;

    for (;;){
        gpio_put(LED_PIN, b);
        b=!b;

        while (sw.isAvailable()){
        	int8_t swNum = sw.readInt();
        	if (swNum >=0){
        		printf("Key=%c Switch=%d\n",
        				lookup[swNum],
						swNum
        				);
        	}
        }

        sleep_ms(DELAY);
    }

}
