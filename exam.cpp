/*
Copyright 2014 bahki386
This file is part of iporker.
*/

#include<stdlib.h>
#include<time.h>
#define SET 13
#define CERT_DOWN 7
#define CERT_PLAY 9
bool exam(int);
bool boolrand(double);
bool exam(int player)
{
	double prob = 0.5;
	//  printf("%lf\n",prob);
	if (player < SET) {
		if (player < CERT_DOWN) {
			return true;
		} else if (player > CERT_PLAY) {
			return false;
		} else {
			return (bool(boolrand(prob)));
		}
	} else {
		if (player <= (SET + CERT_DOWN)) {
			return true;
		} else if (player > (SET + CERT_PLAY)) {
			return false;
		} else {
			return (bool(boolrand(prob)));
		}
	}
}

bool boolrand(double probability)
{
	return rand() < probability * ((double)RAND_MAX + 1.0);
}
