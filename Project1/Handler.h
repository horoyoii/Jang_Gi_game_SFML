#pragma once
#include"Figures.h"
#include"Debug.h"
#include"InfoBoard.h"
#include"myTime.h"
/*
* Created by horoyoii on 09.28.18
*/





class Handler {
private:
	Figures *F;
	RenderWindow *window;
	Sprite *sboard;
	InfoBoard *iBoard;
	bool WhoseTurn;
	STAGE Stage;
	myTime *RunningTime; // �� ���� ���� �ð�
public:
	Handler();

	bool Initailize(); // �ʱ� ���� �� ȣ��Ǵ� �Լ� 

	bool Running(); // ���� ���� �� ���ư��� �Ǵ� �Լ� ( ���������� While Loop )

	void TuningPosition(int nowClicked); // ��Ȯ�� ��ġ�� ���̰� x,y �·Ḧ �����ϴ� ����
	// ������ ���콺�� ��ġ�� ���Ͽ� DISTANCE �� ������ ���� ���� ���� �ٽ� DISTANCE�� ���ϸ� ������ ��ġ(������ ������)�� ��Ȯ�� ���̰� �ȴ�.
	// �� ���� 

	void ScreenRendering(pair<int, int> Times); // while Loop���� ȭ���� �������ִ� �Լ�
};