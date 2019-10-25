/*
*		Dev: 	Florian Warko
*		Toolbox
*		Using: 	delay_sec(seconds);
*				delay_min(minutes);
*				prim_check(number);
*				fsize(file);
*/

#ifndef TOOLBOX_FW_H
#define TOOLBOX_FW_H

#include <stdint.h>
#include <stdbool.h>
#include <time.h>

int delay_sec(int t);
int delay_min(int t);
int prim_check(int i);
int fsize(FILE* input);

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

int prim_check(int i) {
	int y = 0;
	int t = 2;
	bool out = true;
	
	while(t < i) {
		y = i % t;
		if(y == 0) {
			out = false;
		}
		t++;
	}
	
	return out;
}

int fsize(FILE* input) {
	int size = 0;
	fseek (input , 0 , SEEK_END);
	size = ftell(input);
	rewind(input);
	
	return size;
}

#endif /* TOOLBOX_FW_H */
