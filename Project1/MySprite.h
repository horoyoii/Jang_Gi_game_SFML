#pragma once
#include"stdafx.h"
/*
 * Created by Horoyoii on 09.30.18
*/

// 외부 라이브러리 custumizing
class MySprite : public Sprite{
private:
	int indentifierNum;
public:
	int GetIdentifierNum();
	void SetIdentifierNum(int n);
};