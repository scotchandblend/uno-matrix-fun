#include <Arduino.h>
#include <LedControl.h>

#include "render.h"

LedControl lc(12, 11, 10, 2);


void initMatrix (int addr) {
	lc.shutdown(addr, false);
	lc.setIntensity(addr,  2);
	lc.clearDisplay(addr);
}

void setup() {
	Serial.begin(115200);

	initMatrix(0);
	initMatrix(1);

}


void loop() {
	lc.clearDisplay(1);

	for (int y=0; y < 8; ++y) {
		for (int x=0; x < 8; ++x) {
			lc.setLed(0, y, 7-x, true);
        	lc.setLed(1, y, x, true);
        	delay(10);
        	lc.setLed(0, y, 7-x, false);
        	lc.setLed(1, y, x, false);
		}
	}
}

void loopa() {
	for (unsigned  char charCode = 32; charCode < 128; ++charCode) {
		for (int addr = 0; addr < 2; ++addr) {
			render(lc, addr, charCode);
			delay(1000);
		}
	}
}

void loop1() {
	lc.setRow(0, 3, 0xff);
	lc.setRow(0,6,0xff);

	for (int intensity = 0; intensity < 15; ++intensity) {
		lc.setIntensity(0,  intensity);
		delay(250);
	}

	for (int intensity = 14; intensity >=0; --intensity) {
		lc.setIntensity(0,  intensity);
		delay(250);
	}



}

void loop2() {

	for (int row = 0; row < 8; ++row) {
		lc.setRow(0,  row, 0xff);
		delay(125);
	}
	for (int row = 0; row < 8; ++row) {
		lc.setRow(0,  row, 0x00);
		delay(125);
	}

}

//void loopj() {
//
//	unsigned char msg[] = "I love you Jess!";
//	int msgLen = strlen(msg);
//
//	for (unsigned  char charCode = 32; charCode < 128; ++charCode) {
//		render(lc, charCode);
//		delay(2000);
//	}
//}
