#include"stdafx.h"
#include"InfoBoard.h"

InfoBoard::InfoBoard(RenderWindow * window)
:subWindow(window){
	font = new Font();
	title = new Text();
	font->loadFromFile("CuteFont.ttf");

	title->setFont(*font);
	title->setPosition(1100, 10);
	title->setString("Jang - gi ");
	title->setCharacterSize(50);
	turn = new Text();
	turn->setFont(*font);
	turn->setPosition(1000, 200);
	turn->setString("<< TURN");
	
	time = new Text();
	time->setFont(*font);
	time->setPosition(1170, 90);

}


void InfoBoard::Rendering(bool WhoseTurn, int CurTime) {
	subWindow->draw(*title);
	
	// Draw Time
	time->setString("Total Time : "+to_string(CurTime / 1000) + "."+to_string(CurTime % 1000));
	subWindow->draw(*time);
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