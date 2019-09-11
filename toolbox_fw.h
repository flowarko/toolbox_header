/*
*		Dev: 	Florian Warko
*		Toolbox
*		Using: 	delay_sec(seconds);
*				delay_min(minutes);
*				prim_check(number);
*/

#ifndef TOOLBOX_FW_H
#define TOOLBOX_FW_H

#include <stdint.h>
#include <time.h>

int delay_sec(int t);
int delay_min(int t);
int prim_check(int nr);

int delay_sec(int t) {
	time_t tm;
	time(&tm);
	int x, y;

	y = tm + t;

	while(x < y) {
		time(&tm);
		x = tm;
	}
	return 0;
}

int delay_min(int t) {
	time_t tm;
	time(&tm);
	int x, y;

	y = tm + (t * 60);

	while(x < y) {
		time(&tm);
		x = tm;
	}
	return 0;
}

int prim_check(int nr) {
	int y = 0;
	int i = 2;
	int prim = 0;
	
	while(i < nr) {
		y = nr % i;
		if(y == 0) {
			prim++;
		}
		i++;
	}
	
	return prim;
}

#endif /* TOOLBOX_FW_H */
