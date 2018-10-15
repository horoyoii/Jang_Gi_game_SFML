#include"stdafx.h"
#include"Handler.h"

/*
* Created by horoyoii on 09.25.18
*/

Handler::Handler() 
:F(new Figures()){
	window = new RenderWindow(VideoMode(1400, 1000), "Jang-gi gazua");
}

bool Handler::Initailize(){
	// Load InfoBoard
	iBoard = new InfoBoard(window);
	Stage = RUNNING;
	RunningTime = new myTime();

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
	float dx = 0, dy = 0; // ������ ������ ����?!
	int nowClickedEntity;
	WhoseTurn = true; // true : �ʳ��� ���� || false : �ѳ��� ����
	// ==============================================


	while (window->isOpen())
	{
		Vector2i pos = Mouse::getPosition(*window); // window �󿡼� ������ mouse�� ��ġ�� ��ȯ�Ѵ�.

		Event event;
		while (window->pollEvent(event) && Stage == RUNNING)
		{
			// close
			if (event.type == Event::Closed)
				window->close();

			// drag and drop============================================
			// Mouse Pressed
			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					PrintForDebugging("Called ButtonPressed");

					for (int i = 0; i < 32; i++) {
						if (F->getFigures()[i].getLiveOrDead()) {
							if (F->getFigures()[i].getGlobalBounds().contains(pos.x, pos.y)) { // ��Ŭ�� ����� s������ Ȯ��
								// ��getGlobalBounds().contains( x, y ) : Entity�� ��� ���� ��ǥ�� x, y�� ���ϴ��� Ȯ���Ѵ�.
								isMove = true;
								nowClickedEntity = i;
								dx = pos.x - F->getFigures()[i].getPosition().x; // getPosition �� �»���� ��ǥ�� ��ȯ�Ѵ�.
								dy = pos.y - F->getFigures()[i].getPosition().y;

								F->SetOldPos(i);
								break;
							}
						}	
					}
				}
			}

			// Now Dragging
			if (isMove) { // drag �Ǵ� ����
				F->getFigures()[nowClickedEntity].setPosition(pos.x - dx, pos.y - dy);
			}

			// Mouse Released
			if (event.type == Event::MouseButtonReleased) {
				if (event.key.code == Mouse::Left && isMove) {
					isMove = false;
					PrintForDebugging(to_string(F->WhoseEntity(nowClickedEntity)));
					PrintForDebugging(to_string(WhoseTurn));
					// Entity�� ��ġ�� ���� �Ǵ� ( ���Ƶ� �Ǵ� ��ġ���� �ƴ��� ) ===================================
					if (F->CanMove(nowClickedEntity) && F->WhoseEntity(nowClickedEntity) == WhoseTurn) {
						TuningPosition(nowClickedEntity);
						WhoseTurn = !WhoseTurn;
					}
					else { // to the old position
						cout << '\a'; // Beep Sound
						F->ArrayPositionToDisplayPosition(nowClickedEntity);
					}

					PrintForCoord(F->getFigures()[nowClickedEntity].getPosition());
					F->PrintBoard();
				}
			}
			//ScreenRendering();
			
			// End Game ============================================
			switch (F->GameIsEnd()) {
			case -1:
				Stage = END;
				PrintForDebugging("�ʳ��� �¸�");
				break;
			case 1:
				Stage = END;
				PrintForDebugging("�ѳ��� �¸�");
				break;
			case 0:
				break;
			}

		}

		ScreenRendering(RunningTime->Update());
		
	
	}

	return true;
}

void Handler::TuningPosition(int nowClickedEntity){
	
	Vector2f p = F->getFigures()[nowClickedEntity].getPosition();
	
	Vector2f newPos = Vector2f(X_DISTANCE*int(p.x / X_DISTANCE)+X_DEFAULT, Y_DISTANCE*int(p.y/Y_DISTANCE) + Y_DEFAULT);
	
	F->getFigures()[nowClickedEntity].setPosition(newPos);
}

void Handler::ScreenRendering(int CurTime){
	// Board Update ================================================
	window->clear();
	window->draw(*sboard);
	for (int i = 0; i <= 31; i++) {
		if (F->getFigures()[i].getLiveOrDead())	 // ����ִ� �� ���...!!
			window->draw(F->getFigures()[i]);
	}

	// infoBoard Update =============================================
	switch (Stage){
	case RUNNING:
		iBoard->Rendering(WhoseTurn, CurTime);
		break;
	case END:
		iBoard->ScoreRendering(WhoseTurn);

		break;
	default:
		break;
	}

	// Display =========================================================
	window->display();
	
		
}

