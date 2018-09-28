#include"stdafx.h"
/*
* Created by horoyoii on 09.25.18
*/

Handler::Handler() 
:F(new Figures()){
	window = new RenderWindow(VideoMode(1000, 900), "Jang-gi gazua");
}

bool Handler::Initailize(){
   // Entity Load
	F->LoadImage();
	F->SetPosition();
	
	// Map Load 
	Texture* t2 = new Texture();
	if (!t2->loadFromFile("image\\board.jpg")) {
		return false;
	}

	sboard = new Sprite();
	sboard->setTexture(*t2);
	return true;
}



bool Handler::Running(){
	// Manage movement ========
	bool isMove = false;
	float dx = 0, dy = 0; // 일종의 조율자 역할?
	int nowClickedEntity;
	// ==============================================


	while (window->isOpen())
	{
		Vector2i pos = Mouse::getPosition(*window); // window 상에서 현재의 mouse의 위치를 반환한다.

		Event event;
		while (window->pollEvent(event))
		{
			// close
			if (event.type == Event::Closed)
				window->close();

			// drag and drop
			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					cout << "Called ButtonPressed" << endl;

					for (int i = 0; i < 32; i++) {
						if (F->getFigures()[i].getGlobalBounds().contains(pos.x, pos.y)) { // 좌클릭 대상이 s인지를 확인
																						  // getGlobalBounds().contains( x, y ) : Entity s의 모든 범위 좌표에 x, y가 속하는지 확인한다.
							cout << "Called 2" << endl;
							isMove = true;
							nowClickedEntity = i;
							dx = pos.x - F->getFigures()[i].getPosition().x; // getPosition 은 좌상단의 좌표를 반환한다.
							dy = pos.y - F->getFigures()[i].getPosition().y;
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
				F->getFigures()[nowClickedEntity].setPosition(pos.x - dx, pos.y - dy);
			}




			ScreenRendering();

		}
	}
	return true;
}

void Handler::ScreenRendering(){
	// 화면 갱신 =============================================
	window->clear();
	window->draw(*sboard);

	for (int i = 0; i <= 15; i++) {
		window->draw(F->getFigures()[i]);
	}
	window->display();

}

