#pragma once
#include <SDL.h>
#include "Screen.h"
#include "Player.h"

namespace Pong {
	class Ball
	{

	private:
		double m_multiplier;
		const double MAX_VELO = 13.4;
		float m_x, m_y, velocX, velocY;
		int ballColor = 0XFFFF00FF; // yellow
		const int BALLSIZE = 12;
		SDL_Rect m_rect;
		SDL_Renderer* m_renderer = NULL;

	public:
		Ball() : m_x(0), m_y(0), velocX(0), velocY(0), m_multiplier(1.2) { m_rect.x = -100; m_rect.y = -100; }
		void init(SDL_Renderer* renderer);
		void resetPos();
		void checkWall();
		void checkPlayer(Player* player);
		bool checkScoring(Player* player);
		void update();

	};
}


