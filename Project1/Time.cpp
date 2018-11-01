#include "stdafx.h"
#include "myTime.h"

myTime::myTime(){
	OldTime = clock();
}

pair<int, int > myTime::Update(clock_t LimTime){
	CurTime = clock() - OldTime;

	return make_pair(CurTime, LimTime);
}
