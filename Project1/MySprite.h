#pragma once
#include"stdafx.h"
/*
 * Created by Horoyoii on 09.30.18
*/

// �ܺ� ���̺귯�� custumizing
class MySprite : public Sprite{
private:
	int identifierNum;
	bool LiveOrDead;
public:
	int GetIdentifierNum();
	void SetIdentifierNum(int n);
	bool getLiveOrDead();
	int setLiveOrDead(bool state);
};