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

	Limited_Time = new Text();
	Limited_Time->setFont(*font);
	Limited_Time->setPosition(1100, 500);
	Limited_Time->setString("Limited_Time");
}


void InfoBoard::Rendering(bool WhoseTurn, pair<int, int> Times) {
	subWindow->draw(*title);
	
	// Draw Time
	time->setString("Total Time : "+to_string(Times.first / 1000) + "."+to_string(Times.first % 1000));
	subWindow->draw(*time);

	Limited_Time->setString("Limited_Time : " + to_string(10 - Times.second / 1000));
	// Draw Turn
	if (WhoseTurn) 
		turn->setPosition(1000, 200);
	else 
		turn->setPosition(1000, 700);
	subWindow->draw(*turn);
	// Draw Limited_time
	subWindow->draw(*Limited_Time);

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