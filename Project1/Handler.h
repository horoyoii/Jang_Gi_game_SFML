#pragma once

/*
* Created by horoyoii on 09.28.18
*/

class Handler {
private:
	Figures *F;
	RenderWindow *window;
	Sprite *sboard;
public:
	Handler();

	bool Initailize();

	bool Running();
	
	void ScreenRendering();
};