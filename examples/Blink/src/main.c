/**
 * Jon Durrant.
 *
 * Blink LED on GPIO 02
 */

#include "pico/stdlib.h"
#include <stdio.h>

#define DELAY 500 // in microseconds

int main() {
    const uint LED_PIN =  PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT);

    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    while (true) { // Loop forever
        gpio_put(LED_PIN, 1);
        printf("Blink ON\n");
        sleep_ms(DELAY);
        gpio_put(LED_PIN, 0);
        printf("Blink OFF\n");
        sleep_ms(DELAY);
    }

}
