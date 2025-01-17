/**
 * Jon Durrant.
 *
 *  LED on GPIO 15 is latched by a switch on GPIO 14
 */

#include "pico/stdlib.h"
#include <stdio.h>

#include "LatchedSwitch.h"
#include "LatchLED.h"

#define DELAY 500 // in microseconds

int main() {
    const uint LED_PIN =  15;
    const uint SW_PIN = 14;
    LatchedSwitch sw(SW_PIN);
    LatchLED led(LED_PIN);
    sw.setAction(&led);

    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    for (;;){
    	sleep_ms(5000);
    	printf("Just sleeping\n");
    }

}
