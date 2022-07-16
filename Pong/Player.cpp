#include "Player.h"

namespace Pong {

	void Player::init(SDL_Renderer* renderer) {
		m_renderer = renderer;
		m_rect.w = PLAYER_WIDTH;
		m_rect.h = PLAYER_HEIGHT;

	}

	ScoringSide Player::getSide() {
		return side;
	}

	SDL_Rect* Player::getRect() {
		return &m_rect;
	}

	void Player::moveUp() {
		if (m_y >= 0) {
			m_y -= velocY;
		}
	}

	void Player::moveDown() {
		if (m_y + m_rect.h <= Screen::SCREEN_HEIGHT) {
			m_y += velocY;
		}
	}

	void Player::update() {
		if (m_up)
			moveUp();
		if (m_down)
			moveDown();

		m_rect.x = (int)m_x;
		m_rect.y = (int)m_y;

		//fill player color
		Uint8 red = PLAYERCOLOR >> 24;
		Uint8 green = PLAYERCOLOR >> 16;
		Uint8 blue = PLAYERCOLOR >> 8;
		Uint8 alpha = PLAYERCOLOR;
		SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);

		SDL_RenderFillRect(m_renderer, &m_rect);
	}

	void Player::handleKeyDown(SDL_Event* event) {
		switch (event->key.keysym.sym) {

		case SDLK_UP:
			m_up = true;
			break;

		case SDLK_DOWN:
			m_down = true;
			break;
		}
	}

	void Player::handleKeyUp(SDL_Event* event) {
		switch (event->key.keysym.sym) {

		case SDLK_UP:
			m_up = false;
			break;

		case SDLK_DOWN:
			m_down = false;
			break;
		}
	}

	int Player::getScore() {
		return m_player_score;
	}

	void Player::resetScore() {
		m_player_score = 0;
	}

	void Player::addScore(int value) {
		m_player_score += value;
	}
}
