#pragma once
#include <SFML/Graphics.hpp>
#include"stdafx.h"
#include<iostream>

/*
* Created by horoyoii on 09.25.18
*/


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
	int board[10][9] = {
		{ -1, -2, -3, -4, 0, -4,-3,-2,-1 },
	{ 0, 0, 0, 0, -5, 0, 0, 0, 0 },
	{ 0, -6, 0, 0, 0, 0, 0, -6, 0 },
	{ -7, 0, -7, 0, -7, 0, -7, 0, -7 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 7, 0, 7, 0, 7, 0, 7, 0, 7 },
	{ 0, 6, 0, 0, 0, 0, 0, 6, 0 },
	{ 0, 0, 0, 0, 5, 0, 0, 0, 0 },
	{ 1, 2, 3, 4, 0, 4, 3, 2, 1 }
	};
	Sprite f[32];
	Texture t[8];

public:
	Figures();
	void LoadImage();
	void SetPosition();
	Sprite* getFigures();

};

