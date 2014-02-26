/*
Copyright 2014 bahki386

This file is part of iporker.

iporker is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

iporker is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with iporker. If not, see <http://www.gnu.org/licenses/>.
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
