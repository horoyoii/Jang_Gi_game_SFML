// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <stdio.h>
#include <tchar.h>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include <SFML/Graphics.hpp>
#include<time.h>
#include<fmod.h>
#include<windows.h>
#include<mmsystem.h>

#pragma comment(lib, "winmm.lib")

#define X_DISTANCE 105  // 엔티티 간 X축 거리
#define Y_DISTANCE 95 // 엔티티 간 Y축 거리
#define X_DEFAULT 55 // 여백 거리 계산
#define Y_DEFAULT 30 // 여백 거리 계산

using namespace std;
using namespace sf;

typedef enum _STAGE {
	READY, RUNNING, END
}STAGE;
