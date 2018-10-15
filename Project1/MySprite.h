#pragma once
#include"stdafx.h"
/*
 * Created by Horoyoii on 09.30.18
*/

// 외부 라이브러리 custumizing
class MySprite : public Sprite{
private:
	int identifierNum; // 종류에 따라 부여되는 번호
	bool LiveOrDead;
	int CountingNum; // 기물마다의 번호 
public:
	int getCountingNum();
	void setCountingNum(int n);
	int GetIdentifierNum();
	void SetIdentifierNum(int n);
	bool getLiveOrDead();
	int setLiveOrDead(bool state);
};