#include"stdafx.h"


Test::Test(int n, int m)
	:a(n), b(m) {

}

void Test::Add() {
	cout << a << ", " << b << endl;
}