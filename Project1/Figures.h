#pragma once

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
	Sprite f[32];
	Texture Cho_Entity[8];
	Texture Han_Entity[8];

public:
	Figures();
	void LoadImage(); // �̹��� ���ϵ��� �ε��ϴ� �Լ� ( Texture ������ ���� load )
	void SetPosition(); // �ʱ� ���¿��� Entity���� �ʿ� �ѷ��ִ� �Լ�
	Sprite* getFigures(); // Ŭ���� �ܺο��� Sprite F�� ������ �� �ְ� �������ִ� �Լ�
	Vector2f DisplayPositionToArrayPosition(int n); // Entity�� ���� ��ġ�� 2���� �迭�� index�� ��ȯ�Ͽ� ��ȯ���ִ� �Լ�
};

