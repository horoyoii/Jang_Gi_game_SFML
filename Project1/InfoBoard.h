#pragma once


class InfoBoard {
private:
	Text* title;
	Text* time;
	Font* font;
	RenderWindow * subWindow;
public:
	InfoBoard(RenderWindow* window);

	void Rendering();
};