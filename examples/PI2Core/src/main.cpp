/**
 * Calculate value of PI using two cores
 * Jon Durrant - 2024
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include "pico/multicore.h"
#include <pi_spigot/pi_spigot.h>
#include "Counter.h"


int64_t alarmCB (alarm_id_t id, void *user_data){
	Counter::getInstance()->report();
	return 0;
}


bool doWork(){
	using pi_spigot_type = math::constants::pi_spigot<1000, 9>;

	using input_container_type  = std::vector<std::uint32_t>;
	using output_container_type = std::vector<std::uint8_t>;

	input_container_type  pi_in(pi_spigot_type::get_input_static_size());
	output_container_type pi_out(pi_spigot_type::get_output_static_size());


	pi_spigot_type ps;
	ps.calculate(pi_in.begin(), pi_out.begin());

	return true;

}

void core1Main() {
	for (;;){
		if (doWork()){
			multicore_fifo_push_blocking(1);
		}
	}
}



int main() {

	//Initialise IO as we are using printf for debug
	stdio_init_all();

	sleep_ms(2000);
	printf("Go\n");

	multicore_reset_core1();
	multicore_fifo_drain();


	alarm_id_t alarm = add_alarm_in_ms(
			60 * 1000,
			alarmCB, NULL, false);

	Counter::getInstance()->start();
	multicore_launch_core1(core1Main);
	for (;;){
		uint32_t d;
		while (multicore_fifo_rvalid() == true){
			d = multicore_fifo_pop_blocking();
			Counter::getInstance()->incCore(1, 1);
		}

		if (doWork()){
			Counter::getInstance()->inc();
		}
	}

	return 0;
}
