#include"stdafx.h"
#include"Debug.h"
#include"Figures.h"
/*
* Created by horoyoii on 09.25.18
*/

void PrintForDebugging(string str) {
	cout <<"Debug : " << str << "\n";
}

void PrintForCoord(Vector2f p) {
	Vector2f newPos = Vector2f(X_DISTANCE*int(p.x / X_DISTANCE) + X_DEFAULT, Y_DISTANCE*int(p.y / Y_DISTANCE) + Y_DEFAULT);
	string s;
	s += "[ ";
	s += to_string(int((newPos.x - X_DEFAULT))/X_DISTANCE);
	s += ", ";
	s += to_string(int((newPos.y - Y_DEFAULT))/Y_DISTANCE);
	s += " ]";
	cout << s << endl;
}