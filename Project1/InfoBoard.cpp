#include"stdafx.h"
#include"InfoBoard.h"

InfoBoard::InfoBoard(RenderWindow * window)
:subWindow(window){
	font = new Font();
	title = new Text();
	font->loadFromFile("CuteFont.ttf");
	title->setFont(*font);
	title->setPosition(1100, 20);
	title->setString("Hello world");
}


void InfoBoard::Rendering() {


	subWindow->draw(*title);

}
