#pragma once
#include"stdafx.h"

class myTime {
private:
	clock_t OldTime;
	clock_t CurTime;
	clock_t LimitedTime;
public:
	myTime();
	pair<int, int> Update(clock_t LimTime);

};