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

	bool Initailize(); // �ʱ� ���� �� ȣ��Ǵ� �Լ� 

	bool Running(); // ���� ���� �� ���ư��� �Ǵ� �Լ� ( ���������� While Loop )

	void TuningPosition(int nowClicked); // ��Ȯ�� ��ġ�� ���̰� x,y �·Ḧ �����ϴ� ����
	// ������ ���콺�� ��ġ�� ���Ͽ� DISTANCE �� ������ ���� ���� ���� �ٽ� DISTANCE�� ���ϸ� ������ ��ġ(������ ������)�� ��Ȯ�� ���̰� �ȴ�.
	// �� ���� 

	void ScreenRendering(); // while Loop���� ȭ���� �������ִ� �Լ�
};