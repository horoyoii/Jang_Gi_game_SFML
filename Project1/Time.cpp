#include "stdafx.h"
#include "myTime.h"

myTime::myTime(){
	OldTime = clock();
}

int myTime::Update(){
	CurTime = clock() - OldTime;
	return CurTime;
}
