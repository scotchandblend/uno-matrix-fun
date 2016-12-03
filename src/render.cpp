/*
 * render.cpp
 *
 *  Created on: Oct 12, 2016
 *      Author: gdoane
 */

#include <LedControl.h>

#include "font8x8_basic.h"

void render(LedControl &lc, int addr, unsigned char charCode) {

    unsigned char *bitmap = font8x8_basic[charCode];

    unsigned char x,y;
    unsigned char set;
    for (y=0; y < 8; y++) {
    	for (x=0; x < 8; x++) {
    		set = bitmap[y] & (unsigned char)((unsigned char)1 << x);
    		if (set) {
            	lc.setLed(0, y, x, true);
            } else {
            	lc.setLed(0, y, x, false);
            }
        }
    }
}
