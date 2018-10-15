#pragma once
#include"stdafx.h"

class myTime {
private:
	clock_t OldTime;
	clock_t CurTime;
public:
	myTime();
	int Update();

};