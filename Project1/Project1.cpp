#include"stdafx.h"
#include"Figures.h"
#include<iostream>
#include <SFML/Graphics.hpp>


/*
 * Created by horoyoii on 09.25.18
*/


using namespace sf;
using namespace std;


//Sprite f[32]; // figures

int board[10][9] = {
{-1, -2, -3, -4, 0, -4,-3,-2,-1},
{0, 0, 0, 0, -5, 0, 0, 0, 0},
{ 0, -6, 0, 0, 0, 0, 0, -6, 0},
{ -7, 0, -7, 0, -7, 0, -7, 0, -7},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 7, 0, 7, 0, 7, 0, 7, 0, 7 },
{ 0, 6, 0, 0, 0, 0, 0, 6, 0 },
{ 0, 0, 0, 0, 5, 0, 0, 0, 0 },
{ 1, 2, 3, 4, 0, 4, 3, 2, 1 },
};

int main(){
	RenderWindow window(VideoMode(1000, 900), "Jang-gi gazua");
	Figures F(board); // 기물 관리 class
	F.LoadImage();
	
	// load Map
	Texture t2;
	t2.loadFromFile("image\\board.jpg");
	Sprite sboard;
	sboard.setTexture(t2);


	
	// move ========
	bool isMove = false;
	float dx = 0, dy = 0; // 일종의 조율자 역할?
	int nowClickedEntity;
	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window); // window 상에서 현재의 mouse의 위치를 반환한다.

		Event event;
		while (window.pollEvent(event))
		{
			// close
			if (event.type == Event::Closed)
				window.close();

			// drag and drop
			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					cout << "Called 1" << endl;

					for (int i = 0; i < 32; i++) {
						if (F.getFigures()[i].getGlobalBounds().contains(pos.x, pos.y)) { // 좌클릭 대상이 s인지를 확인
						 // getGlobalBounds().contains( x, y ) : Entity s의 모든 범위 좌표에 x, y가 속하는지 확인한다.
							cout << "Called 2" << endl;
							isMove = true;
							nowClickedEntity = i;
							dx = pos.x - F.getFigures()[i].getPosition().x; // getPosition 은 좌상단의 좌표를 반환한다.
							dy = pos.y - F.getFigures()[i].getPosition().y;
							break;
						}
					}
				}
			}

			if (event.type == Event::MouseButtonReleased) {
				if (event.key.code == Mouse::Left) {
					isMove = false;
				}
			}
				

			

			if (isMove) { // drag 되는 과정
				printf("%0.1f %0.1f\n", pos.x - dx, pos.y - dy);
				F.getFigures()[nowClickedEntity].setPosition(pos.x - dx, pos.y - dy);
			}




			// 화면 갱신 =============================================
			window.clear();
			window.draw(sboard);

			for (int i = 0; i <= 15; i++) {
				window.draw(F.getFigures()[i]);
			}
			window.display();

		}
	}
	return 0;
}
