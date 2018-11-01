#pragma once


class InfoBoard {
private:
	Text* title;
	Text* time;
	Font* font;
	RenderWindow * subWindow;
	Text* turn;
	Text* Limited_Time;
public:
	InfoBoard(RenderWindow* window);

	void Rendering(bool WhoseTurn, pair<int, int> Times);
	void ScoreRendering(bool WhoseTurn);
};