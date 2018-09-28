#pragma once
#include <SFML/Graphics.hpp>
#include"stdafx.h"
#include<iostream>
using namespace sf;
using namespace std;
/*
int board[10][9] = {
{-1, -2, -3, -4, 0, -4,-3,-2,-1},
{0, 0, 0, 0, -5, 0, 0, 0, 0},
{ 0, -6, 0, 0, 0, 0, 0, -6, 0},
{ -7, 0, -7, 0, -7, 0, -7, 0, -7},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 7, 0, 7, 0, 7, 0, 7, 0, 7 },
{ 0, 6, 0, 0, 0, 0, 0, 6, 0 },
{ 0, 0, 0, 0, 5, 0, 0, 0, 0 },
{ 1, 2, 3, 4, 0, 4, 3, 2, 1 },
};
*/
#define X_distance 105
#define Y_distance 90
class Figures {
private:
	int (*board)[9];
	Sprite f[32];
	Texture t[8];
public:
	Figures(int (*board)[9]) 
		: board(board){
	}
	void LoadImage() {

		if (!t[1].loadFromFile("image\\Cho_Cha.jpg"))
			return;
		if (!t[2].loadFromFile("image\\Cho_Ma.jpg"))
			return;
		if (!t[3].loadFromFile("image\\Cho_Sang.jpg"))
			return;
		if (!t[4].loadFromFile("image\\Cho_Sa.jpg"))
			return;

		if (!t[5].loadFromFile("image\\Cho_King.jpg"))
			return;
		if (!t[6].loadFromFile("image\\Cho_Pho.jpg"))
			return;
		if (!t[7].loadFromFile("image\\Cho_Jol.jpg"))
			return;
		int n;
		int k = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				n = board[i][j];
				if (!n)
					continue;
				f[k].setTexture(t[abs(n)]);
				f[k].setPosition(X_distance *j+50, Y_distance*i+30);
				k++;
			}
		}
	}

	Sprite* getFigures() {
		return f;
	}

};

