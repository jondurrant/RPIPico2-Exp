/**
 * Jon Durrant.
 *
 *  LED on GPIO 15 will follow Switch on GPIO 14
 */

#include "pico/stdlib.h"
#include <stdio.h>

#define DELAY 500 // in microseconds

int main() {
    const uint LED_PIN =  15;
    const uint SW_PIN = 14;
    gpio_init(LED_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(SW_PIN);
    gpio_set_dir(SW_PIN, GPIO_IN);
    gpio_pull_up(SW_PIN);


    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    for (;;){
    	uint d = gpio_get(SW_PIN);
        gpio_put(LED_PIN, d);
        //printf("d=%d\n", d);
    }

}
