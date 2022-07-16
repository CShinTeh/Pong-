#include "Game.h"

namespace Pong {

	Game::~Game() {
		free(m_player1);
		free(m_player2);
		free(m_scoreP1);
		free(m_scoreP2);
	}

	void Game::init() {
		//init game objects
		m_player1 = new Player(20, Left);
		m_player1->init(m_screen->getRenderer());

		m_player2 = new Player(Screen::SCREEN_WIDTH - Player::PLAYER_WIDTH - 20, Right);
		m_player2->init(m_screen->getRenderer());

		m_ball.init(m_screen->getRenderer());
	}

	void Game::handleEvent() {
		SDL_Event event;

		while (SDL_PollEvent(&event) != 0) {

			switch (event.type) {

			case SDL_QUIT:
				m_screen->quit();
				break;

			case SDL_KEYDOWN:
				m_player1->handleKeyDown(&event);
				m_player2->handleKeyDown(&event);
				break;

			case SDL_KEYUP:
				m_player1->handleKeyUp(&event);
				m_player2->handleKeyUp(&event);
				break;

			case SDL_MOUSEBUTTONDOWN:
				break;
			}

		}
	}

	void Game::process() {
		m_ball.checkWall();
		m_ball.checkPlayer(m_player1);
		m_ball.checkPlayer(m_player2);

		if (m_ball.checkScoring(m_player1)) {
			m_ball.resetPos();
			m_player2->addScore(1);
		}

		if (m_ball.checkScoring(m_player2)) {
			m_ball.resetPos();
			m_player1->addScore(1);
		}
	}

	void Game::setScoreboard() {
		SDL_Color WHITE = { 255, 255, 255, 255 };

		m_scoreP1 = new UILabel(m_screen->getRenderer(), 26);
		m_scoreP1->setText(std::to_string(m_player1->getScore()));
		m_scoreP1->setColor(WHITE);
		m_scoreP1->setPos((Screen::SCREEN_WIDTH / 2) - 100, 20);

		m_scoreP2 = new UILabel(m_screen->getRenderer(), 26);
		m_scoreP2->setText(std::to_string(m_player2->getScore()));
		m_scoreP2->setColor(WHITE);
		m_scoreP2->setPos((Screen::SCREEN_WIDTH / 2) + 100, 20);
	}

	void Game::update() {
		m_screen->fillBackground();

		m_ball.update();

		m_player1->update();
		m_player2->update();

		m_scoreP1->update();
		m_scoreP2->update();

		m_screen->render();
	}

	void Game::run() {
		//check event
		handleEvent();

		//check ball position
		process();

		//set up scoreboard
		setScoreboard();

		//draw object
		update();
	}
}
