#pragma once
#include <SDL.h>
#include "Screen.h"

namespace Pong {

	enum ScoringSide {
		Left = 0, Right
	};

	class Player
	{
	public:
		const static int PLAYER_WIDTH = 25;
		const static int PLAYER_HEIGHT = 100;

	private:
		ScoringSide side;

		int m_player_score = 0;
		double m_x, m_y, velocY;
		const int PLAYERCOLOR = 0xFFFFFFFF; //white
		SDL_Renderer* m_renderer = NULL;
		SDL_Rect m_rect;
		bool m_up = 0, m_down = 0;

	public:
		Player(int x, ScoringSide side) : m_x(x), m_y(0), velocY(10.2), side(side){ m_rect.x = x; };

		void init(SDL_Renderer* renderer);
		SDL_Rect* getRect();
		ScoringSide getSide();

		void moveUp();
		void moveDown();
		void update();
		void handleKeyDown(SDL_Event* event);
		void handleKeyUp(SDL_Event* event);

		int getScore();
		void resetScore();
		void addScore(int value);
	};

}


