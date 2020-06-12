/*On my honor, I pledge that I have neither received nor provided
improper assistance in the completion of this programming assignment.
Signed: 김민혁*/

#include <iostream>
#include <iomanip>
#include <unistd.h>

struct Clock{
	int hr, min, sec;
};

using pClock = Clock*;

void tick(pClock clk);
void show(pClock clk, char end = '\n');
void runs(pClock clk, char end = '\n');
