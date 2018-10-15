#pragma once


class InfoBoard {
private:
	Text* title;
	Text* time;
	Font* font;
	RenderWindow * subWindow;
	Text* turn;
public:
	InfoBoard(RenderWindow* window);

	void Rendering(bool WhoseTurn, int CurTime);
	void ScoreRendering(bool WhoseTurn);
};