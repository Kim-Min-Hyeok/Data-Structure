/*On my honor, I pledge that I have neither received nor provided
improper assistance in the completion of this programming assignment.
Signed: 김민혁*/

#include "clock.h"

int main (void) {
	pClock clk = new Clock{ 11, 58, 56};
	for(int i=0; i<6; ++i){
		tick(clk);
		show(clk);
	}
	runs(clk, '\r');
	delete clk;
	return 0;
}
