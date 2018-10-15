#include "stdafx.h"
#include "MySprite.h"

/*
*  Created by Horoyoii on 09.30.18
*/

int MySprite::getCountingNum() {
	return CountingNum;
}

void MySprite::setCountingNum(int n) {
	CountingNum = n;
}
 
int MySprite::GetIdentifierNum(){
	return identifierNum;
}

void MySprite::SetIdentifierNum(int n){
	identifierNum = n;
}

int MySprite::setLiveOrDead(bool state){
	LiveOrDead = state;
	if (identifierNum == 5) // if Han King is dead....
		return 1;
	else if (identifierNum == -5) // ÃÊ³ª¶ó ¿ÕÀÌ Áê±×¸é...
		return -1;
	return 0;
}

bool MySprite::getLiveOrDead(){
	return LiveOrDead;
}
