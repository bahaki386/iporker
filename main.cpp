/*
Copyright 2014 bahki386
This file is part of iporker.
*/

#include "DxLib.h"
#include "exam.cpp"
#include "GetCard.cpp"

int com_p = 0, player_p = 0;
int p = 1, t = 0, com_c, player_c;
int c_isplay, p_isplay;
int pic[29];
char file[64];
int i;
char KeyBuf[256];

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(800, 600, 32);
	SetMainWindowText("インディアンポーカー");
	if (DxLib_Init() == -1) {
		return -1;
	}
	SRand(GetRand(255));
	for (i = 0; i < 29; i++) {
		sprintf(file, "pic/%d.png", i);
		pic[i] = LoadGraph(file);
	}
	i = 0;
	SetFontSize(30);
	DrawBox(0, 0, 800, 600, GetColor(0, 110, 0), TRUE);
	DrawGraph(100, 100, pic[28], TRUE);
	DrawString(300, 400, "Press Any Key.", GetColor(255, 255, 255));
	WaitKey();
	for (i = 0; i < 13; i++) {
		DrawBox(0, 0, 800, 600, GetColor(0, 110, 0), TRUE);
		DrawBox(0, 0, 180, 30, GetColor(180, 180, 180), TRUE);
		DrawBox(700, 520, 800, 550, GetColor(180, 180, 180), TRUE);
		DrawFormatString(0, 0, GetColor(0, 0, 0), "Player %d",
				 player_p);
		DrawFormatString(700, 520, GetColor(0, 0, 0), "COM %d", com_p);
		DrawGraph(100, 150, pic[26], TRUE);
		DrawGraph(500, 150, pic[27], TRUE);
		WaitTimer(2000);
		com_c = GetCard();
		player_c = GetCard();
		if (ProcessMessage() == -1) {
			break;
		}
		DrawString(100, 100, "インディアンポーカ!!",
			   GetColor(255, 255, 255));
		DrawGraph(100, 150, pic[26], TRUE);
		DrawGraph(500, 150, pic[com_c], TRUE);
		while (1) {
			GetHitKeyStateAll(KeyBuf);
			if (KeyBuf[KEY_INPUT_Y] == 1) {
				p_isplay = 1;
				break;
			} else if (KeyBuf[KEY_INPUT_N] == 1) {
				p_isplay = 0;
				break;
			}
			if (ProcessMessage() == -1)
				break;
		}
		c_isplay = exam(player_c);
		if ((player_c % 13) == (com_c % 13)) {
			player_p += 0;
			com_p += 0;
		} else if ((c_isplay + p_isplay) == 2) {
			if (player_c > com_c) {
				player_p +=
				    (player_c % 13) + 1 + (com_c % 13) + 1;
			} else {
				com_p += (player_c % 13) + 1 + (com_c % 13) + 1;
			}
		} else if ((c_isplay + p_isplay) == 1) {
			if (c_isplay) {
				com_p += (player_c % 13) + 1;
			} else {
				player_p += (com_c % 13) + 1;
			}
		}
		DrawGraph(100, 150, pic[player_c], TRUE);
		DrawGraph(500, 150, pic[com_c], TRUE);
		if (p_isplay) {
			DrawString(200, 520, "Player:勝負",
				   GetColor(255, 255, 255));
		} else {
			DrawString(200, 520, "Player:降りる",
				   GetColor(255, 255, 255));
		}
		if (c_isplay) {
			DrawString(200, 550, "CPU:勝負",
				   GetColor(255, 255, 255));
		} else {
			DrawString(200, 550, "CPU:降りる",
				   GetColor(255, 255, 255));
		}
		WaitTimer(5000);
		player_c = 0;
		com_c = 0;
		if (ProcessMessage() == -1) {
			break;
		}
	}
	DrawBox(0, 0, 800, 600, GetColor(0, 110, 0), TRUE);
	SetFontSize(50);
	DrawFormatString(350, 350, GetColor(255, 255, 255), "Player %d",
			 player_p);
	DrawFormatString(350, 400, GetColor(255, 255, 255), "COM %d", com_p);
	if (player_p > com_p) {
		DrawString(350, 500, "Player Wins.", GetColor(255, 255, 255));
	} else {
		DrawString(350, 500, "CPU Wins.", GetColor(255, 0, 0));
	}
	WaitKey();
	DxLib_End();		// DXライブラリ終了処理
	return 0;
}
