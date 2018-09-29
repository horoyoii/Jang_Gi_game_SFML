#include"stdafx.h"
#include"InfoBoard.h"

InfoBoard::InfoBoard(RenderWindow * window)
:subWindow(window){

}

void InfoBoard::Rendering(){
	Text text;
	text.setPosition(1100, 100);
	text.setString("Hello world");

	subWindow->draw(text);
}
