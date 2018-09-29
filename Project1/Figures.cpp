#include"stdafx.h"
#include"Figures.h"
/*
* Created by horoyoii on 09.28.18
*/


Figures::Figures(){
	
}


void Figures::LoadImage() {

	if (!Cho_Entity[1].loadFromFile("image\\Cho_Cha.jpg"))
		return;
	if (!Cho_Entity[2].loadFromFile("image\\Cho_Ma.jpg"))
		return;
	if (!Cho_Entity[3].loadFromFile("image\\Cho_Sang.jpg"))
		return;
	if (!Cho_Entity[4].loadFromFile("image\\Cho_Sa.jpg"))
		return;
	if (!Cho_Entity[5].loadFromFile("image\\Cho_King.jpg"))
		return;
	if (!Cho_Entity[6].loadFromFile("image\\Cho_Pho.jpg"))
		return;
	if (!Cho_Entity[7].loadFromFile("image\\Cho_Jol.jpg"))
		return;

	if (!Han_Entity[1].loadFromFile("image\\Han_Cha.jpg"))
		return;
	if (!Han_Entity[2].loadFromFile("image\\Han_Ma.jpg"))
		return;
	if (!Han_Entity[3].loadFromFile("image\\Han_Sang.jpg"))
		return;
	if (!Han_Entity[4].loadFromFile("image\\Han_Sa.jpg"))
		return;
	if (!Han_Entity[5].loadFromFile("image\\Han_King.jpg"))
		return;
	if (!Han_Entity[6].loadFromFile("image\\Han_Pho.jpg"))
		return;
	if (!Han_Entity[7].loadFromFile("image\\Han_Jol.jpg"))
		return;
}

void Figures::SetPosition(){
	int n;
	int k = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (i <= 5) {
				n = board[i][j];
				if (!n)
					continue;
				f[k].setTexture(Cho_Entity[abs(n)]);
				f[k].setPosition(X_DISTANCE *j + X_DEFAULT, Y_DISTANCE*i + Y_DEFAULT);
				k++;
			}
			else {
				n = board[i][j];
				if (!n)
					continue;
				f[k].setTexture(Han_Entity[abs(n)]);
				f[k].setPosition(X_DISTANCE *j + X_DEFAULT, Y_DISTANCE*i + Y_DEFAULT);
				k++;

			}
		}
	}


}


Sprite* Figures::getFigures() {
	return f;
}

Vector2f Figures::DisplayPositionToArrayPosition(int n){
	Vector2f p = Vector2f(f[n].getPosition().x, f[n].getPosition().y);
	Vector2f newPos = Vector2f(X_DISTANCE*int(p.x / X_DISTANCE) + X_DEFAULT, Y_DISTANCE*int(p.y / Y_DISTANCE) + Y_DEFAULT);
	Vector2f ArrayPos = Vector2f((newPos.x - X_DEFAULT) / X_DISTANCE, (newPos.y - Y_DEFAULT) / Y_DISTANCE);
	return ArrayPos;
}
