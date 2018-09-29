#pragma once

/*
* Created by horoyoii on 09.25.18
*/


#define X_DISTANCE 105  // 엔티티 간 X축 거리
#define Y_DISTANCE 95 // 엔티티 간 Y축 거리
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
	void LoadImage(); // 이미지 파일들을 로드하는 함수 ( Texture 변수에 전부 load )
	void SetPosition(); // 초기 상태에서 Entity들을 맵에 뿌려주는 함수
	Sprite* getFigures(); // 클래스 외부에서 Sprite F를 참조할 수 있게 제공해주는 함수
	Vector2f DisplayPositionToArrayPosition(int n); // Entity의 현재 위치를 2차원 배열의 index로 변환하여 반환해주는 함수
};

