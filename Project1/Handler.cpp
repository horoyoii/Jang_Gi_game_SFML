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


	//=========================================================
	// �������� �ְ� �ޱ� ���� time-out�� ���� ���� ( �� ���� 10�� )
	clock_t oldTime = clock();
	clock_t LimitedTime;

	//=========================================================


	PlaySound(TEXT("BGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
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
						LimitedTime = 0;
						oldTime = clock();
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

		//------------------------------
		/*
		printf("%d \n", Limited_Time);
		Limited_Time++;
		*/

		//  ===========================================
		// Checking Time-out
		
		LimitedTime = clock() - oldTime; // curTime�� 0 to 30 �ʸ� �� �� �ְ� �ȴ�.
		//printf("%d\n", LimitedTime/1000);


		if (LimitedTime  > 10000) {
			LimitedTime = 0;
			oldTime = clock();
			WhoseTurn = !WhoseTurn;
		}
		
		// TODO: Showing Limited_Time 
		ScreenRendering(RunningTime->Update(LimitedTime));
		
	
	}

	return true;
}

void Handler::TuningPosition(int nowClickedEntity){
	
	Vector2f p = F->getFigures()[nowClickedEntity].getPosition();
	
	Vector2f newPos = Vector2f(X_DISTANCE*int(p.x / X_DISTANCE)+X_DEFAULT, Y_DISTANCE*int(p.y/Y_DISTANCE) + Y_DEFAULT);
	
	F->getFigures()[nowClickedEntity].setPosition(newPos);
}

void Handler::ScreenRendering(pair<int, int> Times){
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
		iBoard->Rendering(WhoseTurn, Times);
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

