#include"stdafx.h"
#include"InfoBoard.h"

InfoBoard::InfoBoard(RenderWindow * window)
:subWindow(window){
	font = new Font();
	title = new Text();
	font->loadFromFile("CuteFont.ttf");

	title->setFont(*font);
	title->setPosition(1100, 20);
	title->setString("Jang - gi ");
	title->setCharacterSize(50);
	turn = new Text();
	turn->setFont(*font);
	turn->setPosition(1000, 200);
	turn->setString("<< TURN");
	


}


void InfoBoard::Rendering(bool WhoseTurn) {
	subWindow->draw(*title);
	
	// Draw Turn

	if (WhoseTurn) 
		turn->setPosition(1000, 200);
	else 
		turn->setPosition(1000, 700);
	subWindow->draw(*turn);
}

void InfoBoard::ScoreRendering(bool WhoseTurn) {
	turn->setPosition(1100, 450);
	turn->setCharacterSize(45);
	if (!WhoseTurn) {
		turn->setString("Cho Victory!!");
	}
	else {
		turn->setString("Han Victory!!");
	}
	subWindow->draw(*turn);
}