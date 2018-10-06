#pragma once
#include"MySprite.h"
/*
* Created by horoyoii on 09.25.18
*/

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
	MySprite f[32]; // 가지는 값 : 현재의 Display 위치 + 식별번호
	Texture Cho_Entity[8];
	Texture Han_Entity[8];
	Vector2f oldPos; // 움직임 전의 좌표
	Vector2f CurPos;
	int EndGameFlag; // 1 is Cho Win, -1 is Han Win, 0 means game still runs
public:
	Figures();
	void LoadImage(); // 이미지 파일들을 로드하는 함수 ( Texture 변수에 전부 load )
	void SetPosition(); // 초기 상태에서 Entity들을 맵에 뿌려주는 함수
	MySprite* getFigures(); // 클래스 외부에서 Sprite F를 참조할 수 있게 제공해주는 함수
	Vector2f DisplayPositionToArrayPosition(int n); // Entity의 현재 위치를 2차원 배열의 index로 변환하여 반환해주는 함수
	void ArrayPositionToDisplayPosition(int n, Vector2f v);
	void ArrayPositionToDisplayPosition(int n);
	void SetOldPos(int n);
	bool CanMove(int n);

	void UpdateBoard();
	int GameIsEnd();

	bool Cha_Moving();
	bool Ma_Moving();
	void PrintBoard() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", board[i][j]);
			}
			puts(" ");
		}
	}
};

