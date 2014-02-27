/*
Copyright 2014 bahki386
This file is part of iporker.
*/

#include"DxLib.h"
int GetCard()
{
	static bool uCard[26] =
	    { FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
FALSE, FALSE, FALSE, FALSE, FALSE };
	int card;
	while (1) {
		if (ProcessMessage() == -1) {
			break;
		}
		card = GetRand(25);
		if (uCard[card] == FALSE) {
			uCard[card] = TRUE;
			return (card);
		}
	}
	return -1;
}
