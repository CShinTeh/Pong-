#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "Screen.h"
#include "Ball.h"
#include "Player.h"
#include "UILabel.h"
#include "UIButton.h"

namespace Pong {

	class Game
	{
	public:
		bool running;

	private:
		Player* m_player1, *m_player2;
		Ball m_ball;
		Screen* m_screen;
		UILabel* m_scoreP1, * m_scoreP2;

	public:
		Game(Screen* screen) : m_screen(screen) { running = 0; };
		~Game();

		void init();
		void handleEvent();
		void setScoreboard();
		void process();
		void update();
		void run();
	};

}


