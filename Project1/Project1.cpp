#include"stdafx.h"
#include <SFML/Graphics.hpp>

/*
 * Created by horoyoii on 09.25.18
*/

int main(){
	Handler handler;

	// Tranjection =============================
	if (handler.Initailize()) {
		if (handler.Running()) 
			PrintForDebugging("System Exit ( 정상적 종료 ) ");

		else 
			PrintForDebugging("System Exit ( 비정상적 종료 ) ");

	}else
		PrintForDebugging("System Exit ( Load Failed )");

	return 0;
}
