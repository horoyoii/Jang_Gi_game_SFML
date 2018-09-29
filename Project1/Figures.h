#pragma once

/*
* Created by horoyoii on 09.25.18
*/


using namespace sf;
using namespace std;

#define X_DISTANCE 105  // 엔티티 간 거리 계산
#define Y_DISTANCE 95
#define X_DEFAULT 55 // 여백 거리 계산
#define Y_DEFAULT 30 // 여백 거리 계산

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
	Texture Cho_Entity[8];
	Texture Han_Entity[8];

public:
	Figures();
	void LoadImage();
	void SetPosition();
	Sprite* getFigures();

};

