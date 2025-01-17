/**
 * Jon Durrant.
 *
 *  LED on GPIO 15 is latched by a switch on GPIO 14
 */

#include "pico/stdlib.h"
#include <stdio.h>

#include "LatchedSwitch.h"

#define DELAY 500 // in microseconds

int main() {
    const uint LED_PIN =  15;
    const uint SW_PIN = 14;
    LatchedSwitch sw(SW_PIN);

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    for (;;){
    	bool p = sw.isLatchOn();

        gpio_put(LED_PIN, p);
    }

}
