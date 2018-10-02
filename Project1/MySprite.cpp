#include "stdafx.h"
#include "MySprite.h"

/*
*  Created by Horoyoii on 09.30.18
*/

int MySprite::GetIdentifierNum(){
	return indentifierNum;
}

void MySprite::SetIdentifierNum(int n){
	indentifierNum = n;
}

void MySprite::setLiveOrDead(bool state){
	LiveOrDead = state;
}

bool MySprite::getLiveOrDead(){
	return LiveOrDead;
}
