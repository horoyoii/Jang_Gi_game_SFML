#include"stdafx.h"
#include"Figures.h"
/*
* Created by horoyoii on 09.28.18
*/


Figures::Figures(){
	for (int i = 0; i < 32; i++) {
		f[i].setLiveOrDead(true);
	}
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
				f[k].SetIdentifierNum(n);
				k++;
			}
			else {
				n = board[i][j];
				if (!n)
					continue;
				f[k].setTexture(Han_Entity[abs(n)]);
				f[k].setPosition(X_DISTANCE *j + X_DEFAULT, Y_DISTANCE*i + Y_DEFAULT);
				f[k].SetIdentifierNum(n);
				k++;

			}
		}
	}
}


MySprite* Figures::getFigures() {
	return f;
}

Vector2f Figures::DisplayPositionToArrayPosition(int n){
	Vector2f p = Vector2f(f[n].getPosition().x, f[n].getPosition().y);
	Vector2f newPos = Vector2f(X_DISTANCE*int(p.x / X_DISTANCE) + X_DEFAULT, Y_DISTANCE*int(p.y / Y_DISTANCE) + Y_DEFAULT);
	Vector2f ArrayPos = Vector2f((newPos.x - X_DEFAULT) / X_DISTANCE, (newPos.y - Y_DEFAULT) / Y_DISTANCE);
	return ArrayPos;
}

void Figures::ArrayPositionToDisplayPosition(int n, Vector2f v){
	

}

void Figures::ArrayPositionToDisplayPosition(int n){
	f[n].setPosition(oldPos.x*X_DISTANCE+X_DEFAULT, oldPos.y*Y_DISTANCE+Y_DEFAULT);
}

void Figures::SetOldPos(int n){
	oldPos = DisplayPositionToArrayPosition(n);

}

bool Figures::CanMove(int n){
	int idNum = f[n].GetIdentifierNum();
	CurPos = DisplayPositionToArrayPosition(n);
	cout <<n <<", "<<idNum << ", " << CurPos.x << ", " << CurPos.y << endl;
	
	if (idNum * board[int(CurPos.y)][int(CurPos.x)] > 1)  // �������ϴ� ��ġ�� �Ʊ� ���� �ִٸ�...
		return false;

	switch (idNum) {
	case 1: // �ѳ��� ��
		if (!Cha_Moving())
			return false;
		break;
	case -1:
		if (!Cha_Moving())
			return false;
		break;
	case 7: // �ѳ��� ��
		if (oldPos.y < CurPos.y) {// �ڷΰ��� �ȵ�...
			return false;
		}
		break;
	case -7: // �ʳ��� ��
		if (oldPos.y > CurPos.y) {
			return false;
		}
		break;
	case 5: // �ѳ��� ��
		if (CurPos.x >= 3 && CurPos.x <= 5 && CurPos.y <= 9 && CurPos.y >= 7) {

		}
		else
			return false;
		break;
	case -5:  // �ѳ��� ��
		if (CurPos.x >= 3 && CurPos.x <= 5 && CurPos.y <= 3 && CurPos.y >= 0) {

		}
		else
			return false;
		break;
	}

	// update board
	 //TODO : ��븻�� ��� ��� Board Update�� �ٸ��� �ؾ��Ѵ�.


	UpdateBoard();


	return true;
}


void Figures::UpdateBoard() {
	Vector2f EnemyPos;
	Vector2f n = { CurPos.x, CurPos.y };

	// Delete Enemy Entity =====================================================
	if (board[int(CurPos.y)][int(CurPos.x)]) { // ��븻�� �����ߴ� ���
		for (int i = 0; i < 32; i++) { // �� ���� � Sprite���� Ž��
			EnemyPos = DisplayPositionToArrayPosition(i);
			if (n == EnemyPos) {
				f[i].setLiveOrDead(false);
				break;
			}
		}
	}
	// ========================================================================


	swap(board[int(oldPos.y)][int(oldPos.x)], board[int(CurPos.y)][int(CurPos.x)]);
	board[int(oldPos.y)][int(oldPos.x)] = 0;
}



bool Figures::Cha_Moving() {
	if (CurPos.x != oldPos.x && CurPos.y != oldPos.y)  // ������ �ƴ� ���
		return false;
	// ���̿� Entity�� �����ϴ� ���
	if (CurPos.x == oldPos.x) {
		if (CurPos.y > oldPos.y) {
			for (int i = oldPos.y + 1; i < CurPos.y; i++) {
				if (board[i][int(CurPos.x)]) // ���δ� 0�� �ƴ϶�� .... -> ���̿� ���� �����Ѵ� -> �� �� ����.
					return false;
			}
		}
		else {
			for (int i = CurPos.y + 1; i < oldPos.y; i++) {
				if (board[i][int(CurPos.x)]) // ���δ� 0�� �ƴ϶�� .... -> ���̿� ���� �����Ѵ� -> �� �� ����.
					return false;
			}
		}
	
	}
	else if (CurPos.y == oldPos.y) {
		if (CurPos.x > oldPos.x) {
			for (int i = oldPos.x + 1; i < CurPos.x; i++) {
				if (board[int(CurPos.y)][i]) // ���δ� 0�� �ƴ϶�� .... -> ���̿� ���� �����Ѵ� -> �� �� ����.
					return false;
			}
		}
		else {
			for (int i = CurPos.x + 1; i < oldPos.x; i++) {
				if (board[int(CurPos.y)][i]) // ���δ� 0�� �ƴ϶�� .... -> ���̿� ���� �����Ѵ� -> �� �� ����.
					return false;
			}
		}
	
	}
	
	return true;
}