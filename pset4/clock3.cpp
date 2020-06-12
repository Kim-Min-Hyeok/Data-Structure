/*On my honor, I pledge that I have neither received nor provided
improper assistance in the completion of this programming assignment.
Signed: 김민혁*/

#include <iostream>
#include <iomanip>

struct Clock{
	int hr, min, sec;
};

using pClock = Clock*;

void tick(pClock ptr);
void show(pClock ptr);

int main (void) {
	pClock ptr = new Clock{ 14, 38, 56};

	for(int i= 0; i<6; ++i){
		tick(ptr);
		show(ptr);
	}
	delete ptr;
	return 0;
}

void tick(pClock ptr) {
	ptr->sec++;
	if(ptr->sec == 60){
		ptr->min++;
		ptr->sec=0;
	}
	if(ptr->min == 60){
		ptr->hr++;
		ptr->min=0;
	}
}

void show(pClock ptr){
	std::cout.fill('0');
	std::cout << std::setw(2) << ptr->hr << ":"
						<< std::setw(2) << ptr->min << ":"
						<< std::setw(2) << ptr->sec << std::endl;
}
