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
	float dx = 0, dy = 0; // 일종의 조율자 역할?!
	int nowClickedEntity;
	WhoseTurn = true; // true : 초나라 차례 || false : 한나라 차례
	// ==============================================


	while (window->isOpen())
	{
		Vector2i pos = Mouse::getPosition(*window); // window 상에서 현재의 mouse의 위치를 반환한다.

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
							if (F->getFigures()[i].getGlobalBounds().contains(pos.x, pos.y)) { // 좌클릭 대상이 s인지를 확인
								// ㄴgetGlobalBounds().contains( x, y ) : Entity의 모든 범위 좌표에 x, y가 속하는지 확인한다.
								isMove = true;
								nowClickedEntity = i;
								dx = pos.x - F->getFigures()[i].getPosition().x; // getPosition 은 좌상단의 좌표를 반환한다.
								dy = pos.y - F->getFigures()[i].getPosition().y;

								F->SetOldPos(i);
								break;
							}
						}	
					}
				}
			}

			// Now Dragging
			if (isMove) { // drag 되는 과정
				F->getFigures()[nowClickedEntity].setPosition(pos.x - dx, pos.y - dy);
			}

			// Mouse Released
			if (event.type == Event::MouseButtonReleased) {
				if (event.key.code == Mouse::Left && isMove) {
					isMove = false;
					PrintForDebugging(to_string(F->WhoseEntity(nowClickedEntity)));
					PrintForDebugging(to_string(WhoseTurn));
					// Entity의 위치에 대한 판단 ( 놓아도 되는 위치인지 아닌지 ) ===================================
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
				PrintForDebugging("초나라 승리");
				break;
			case 1:
				Stage = END;
				PrintForDebugging("한나라 승리");
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
		if (F->getFigures()[i].getLiveOrDead())	 // 살아있는 놈만 출력...!!
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

