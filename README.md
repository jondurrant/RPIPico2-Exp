# RPIPico2-Exp
Experiments with Raspberry Pi Pico 2

This is a set of initial experiments and tests with the Raspberry Pi Pico 2 and RP2350 published along with my VLOG on YouTube [DrJonEA](https://youtube.com/@drjonea)

## Build process
Though these should build with the VSCode extention, all my development is done using an external toolchain.

I am using SDK 2.0.0 the location of which is published via the  environment variable: PICO_SDK_PATH

I am using a shared copy of PicoTool using the environment variable: PICOTOOL_FETCH_FROM_GIT_PATH

```
mkdir build
cd build
cmake ..
make
```
Binaries are in the folder: build/src/
+ *.elf: for SWD flashing
+ *.uf2 for bootself flashing

 
## Example

### Blink

 Blink on board LED on a Pico 2 using the SDK
 
### PI1Core
 
 Performance test the Pico 2 for Integer arithmetic calculation the value of PI to 1000 decimal place. How many times can it complete this in 1 minute.
 
 This uses the library [pi_spigot]( https://github.com/imahjoub/pi_spigot) to calculate PI

### PI2Core
 
 Performance test the Pico 2 for Integer arithmetic calculation the value of PI to 1000 decimal place. How many times can it complete this in 1 minute., this time running across both cores of the Pico.
 
### FPUPerf

Test floating point performance of the Pico2 and RP2350 by calculating a Forward Kinematic chain for a  robot arm, to give the end actuators pose. How many times can this be calculated in 10 seconds.

This uses the [Eigen](https://gitlab.com/libeigen/eigen) library for matrix maths.

### FPUPerf2040

A RP2040 and Pico 1 version of FPUPerf for comparison perposes.

### FreeRTOSBlink

A FreeRTOS Blink example to demonstrate FreeRTOS on the RP2350 and Pico 2. Will Blink an LED on GPIO 2.

This uses a shared copy of the Raspberry Pi fork for [FreeRTOS kernel](https://github.com/raspberrypi/FreeRTOS-Kernel) located through the environment variable: PICO_FREERTOS

 
 
 
 
