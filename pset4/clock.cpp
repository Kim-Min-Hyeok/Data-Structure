/*On my honor, I pledge that I have neither received nor provided
improper assistance in the completion of this programming assignment.
Signed: 김민혁*/

#include "clock.h"

void tick(pClock clk){
	clk->sec++;
	if(clk->sec == 60){
		clk->min++;
		clk->sec=0;
	}
	if(clk->min == 60){
		clk->hr++;
		clk->min=0;
	}
}

void show(pClock clk, char end){
	std::cout.fill('0');
	std::cout << std::setw(2) << clk->hr << ":"
						<< std::setw(2) << clk->min << ":"
						<< std::setw(2) << clk->sec << end;
}

void runs(pClock clk, char end){
	while(true) {
		sleep(1);
		tick(clk);
		show(clk, end);
	}
}
