#include"stdafx.h"
/*
* Created by horoyoii on 09.28.18
*/


Figures::Figures(){
	
}


void Figures::LoadImage() {

	if (!t[1].loadFromFile("image\\Cho_Cha.jpg"))
		return;
	if (!t[2].loadFromFile("image\\Cho_Ma.jpg"))
		return;
	if (!t[3].loadFromFile("image\\Cho_Sang.jpg"))
		return;
	if (!t[4].loadFromFile("image\\Cho_Sa.jpg"))
		return;
	if (!t[5].loadFromFile("image\\Cho_King.jpg"))
		return;
	if (!t[6].loadFromFile("image\\Cho_Pho.jpg"))
		return;
	if (!t[7].loadFromFile("image\\Cho_Jol.jpg"))
		return;
}

void Figures::SetPosition(){
	int n;
	int k = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			n = board[i][j];
			if (!n)
				continue;
			f[k].setTexture(t[abs(n)]);
			f[k].setPosition(X_distance *j + 50, Y_distance*i + 30);
			k++;
		}
	}
}


Sprite* Figures::getFigures() {
	return f;
}