/**
 * Jon Durrant.
 *
 * Floating point workload test
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "Counter.h"
#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

#define DELAY 500 // in microseconds


typedef Matrix<double, 6, 1> Vector6d;
typedef Matrix<double, 6, 6> Matrix6d;


int64_t alarmCB (alarm_id_t id, void *user_data){
	Counter::getInstance()->stop();
	return 0;
}


double test(){

	Matrix4d T0_1 = (AngleAxisd(M_PI, Vector3d(0, 0, 1)) * Translation3d(0, 0, 0.01)).matrix();
	//cout << "T0_1 = " << endl << T0_1 << endl;
	Matrix4d T1_2 = (AngleAxisd(M_PI/4, Vector3d(1, 0, 0)) * Translation3d(0, 0, 0.01)).matrix();
	//cout << "T1_2 = " << endl << T1_2 << endl;
	Matrix4d T2_3 = (AngleAxisd(M_PI/6, Vector3d(1, 0, 0)) * Translation3d(0, 0, 0.01)).matrix();
	Matrix4d T3_4 = (AngleAxisd(M_PI/6, Vector3d(1, 0, 0)) * Translation3d(0, 0, 0.01)).matrix();
	Matrix4d T4_5 = (AngleAxisd(0.0, Vector3d(0, 0, 1)) * Translation3d(0, 0, 0.01)).matrix();
	Matrix4d T5_6 = (AngleAxisd(0.0, Vector3d(0, 1, 0)) * Translation3d(0.005, 0, 0.01)).matrix();
	Matrix4d end = T0_1 * T1_2 * T2_3 * T3_4 * T4_5 * T5_6;
	//cout << "end = " << endl << end << endl;
	return end(0,3) + end(1,3) + end(2,3);
}





int main() {
    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    test();

    alarm_id_t alarm = add_alarm_in_ms(
    			10 * 1000,
    			alarmCB, NULL, false);

	Counter::getInstance()->start();
	double t;
	for (;;){
		t += test();
		Counter::getInstance()->inc();
		if (!Counter::getInstance()->isRunning()){
			break;
		}
	}


	Counter::getInstance()->report();

	for (;;){
		sleep_ms(3000);
	}



}
