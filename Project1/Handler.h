#pragma once
#include"Figures.h"
#include"Debug.h"
/*
* Created by horoyoii on 09.28.18
*/

class Handler {
private:
	Figures *F;
	RenderWindow *window;
	Sprite *sboard;
	//InfoBoard *iBoard;

public:
	Handler();

	bool Initailize(); // 초기 세팅 시 호출되는 함수 

	bool Running(); // 게임 시작 시 돌아가게 되는 함수 ( 내부적으로 While Loop )

	void TuningPosition(int nowClicked); // 정확한 위치에 놓이게 x,y 좌료를 조율하는 역할
	// 현재의 마우스의 위치에 대하여 DISTANCE 로 나누어 몫을 구한 다음 다시 DISTANCE를 곱하면 지정된 위치(선분의 교차점)에 정확히 놓이게 된다.
	// 몫 연산 

	void ScreenRendering(); // while Loop마다 화면을 갱신해주는 함수
};