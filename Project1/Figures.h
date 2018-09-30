#pragma once
#include"MySprite.h"
/*
* Created by horoyoii on 09.25.18
*/


#define X_DISTANCE 105  // ��ƼƼ �� X�� �Ÿ�
#define Y_DISTANCE 95 // ��ƼƼ �� Y�� �Ÿ�
#define X_DEFAULT 55 // ���� �Ÿ� ���
#define Y_DEFAULT 30 // ���� �Ÿ� ���

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
	MySprite f[32]; // ������ �� : ������ Display ��ġ + �ĺ���ȣ
	Texture Cho_Entity[8];
	Texture Han_Entity[8];
	Vector2f oldPos; // ������ ���� ��ǥ
	Vector2f CurPos;
public:
	Figures();
	void LoadImage(); // �̹��� ���ϵ��� �ε��ϴ� �Լ� ( Texture ������ ���� load )
	void SetPosition(); // �ʱ� ���¿��� Entity���� �ʿ� �ѷ��ִ� �Լ�
	MySprite* getFigures(); // Ŭ���� �ܺο��� Sprite F�� ������ �� �ְ� �������ִ� �Լ�
	Vector2f DisplayPositionToArrayPosition(int n); // Entity�� ���� ��ġ�� 2���� �迭�� index�� ��ȯ�Ͽ� ��ȯ���ִ� �Լ�
	void ArrayPositionToDisplayPosition(int n, Vector2f v);
	void ArrayPositionToDisplayPosition(int n);
	void SetOldPos(int n);
	bool CanMove(int n);

	void UpdateBoard();


	void PrintBoard() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", board[i][j]);
			}
			puts(" ");
		}
	}
};

