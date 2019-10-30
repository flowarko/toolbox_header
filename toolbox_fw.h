/*
*		Developer: 	flowarko
*		Toolbox
*		Using: 		delay_sec(seconds);
*					delay_min(minutes);
*					prim_check(number);
*					fsize(file);
*					dectohex(number);
*		Version:	V0.0.1
*/

#ifndef TOOLBOX_FW_H
#define TOOLBOX_FW_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

int delay_sec(int t);
int delay_min(int t);
bool prim_check(int i);
int fsize(FILE* input);
char dectohex(int dec);

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

bool prim_check(int i) {
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
	
	fseek (input, 0,SEEK_END);
	size = ftell(input);
	rewind(input);
	
	return size;
}

char dectohex(int dec) {
	char tblock[1];
	
	if(dec < 10) {
			tblock[0] = dec + 48;
		}
		else if(dec == 10) {
			tblock[0] = 'a';
		}
		else if(dec == 11) {
			tblock[0] = 'b';
		}
		else if(dec == 12) {
			tblock[0] = 'c';
		}
		else if(dec == 13) {
			tblock[0] = 'd';
		}
		else if(dec == 14) {
			tblock[0] = 'e';
		}
		else if(dec == 15) {
			tblock[0] = 'f';
		}
		
	return tblock[0];
}

#endif /* TOOLBOX_FW_H */
