#include "Ball.h"
#include "Player.h"
#include <iostream>

namespace Pong {

	void Ball::init(SDL_Renderer* renderer) {
		resetPos();

		m_rect.w = BALLSIZE;
		m_rect.h = BALLSIZE;
		m_renderer = renderer;
	}

	void Ball::resetPos() {
		m_x = (Screen::SCREEN_WIDTH / 2) - (BALLSIZE / 2);
		m_y = (Screen::SCREEN_HEIGHT / 2) - (BALLSIZE / 2);

		velocX = pow(-1, rand()) * 3.10;
		velocY = pow(-1, rand()) * (rand() / RAND_MAX + 2.0);

	}

	void Ball::checkWall() {
		//top and bottom edge
		if ((m_y <= 0 && velocY < 0) || (m_y >= Screen::SCREEN_HEIGHT - (velocY * 5) && velocY > 0)) {
			if (velocY * m_multiplier <= MAX_VELO)
				velocY *= m_multiplier * -1;
		}
	}

	void Ball::checkPlayer(Player* player) {
		//check player collision
		SDL_Rect* playerRect = player->getRect();

		if (m_rect.x < playerRect->x + playerRect->w &&
			m_rect.x + m_rect.w > playerRect->x &&
			m_rect.y < playerRect->y + playerRect->h &&
			m_rect.h + m_rect.y > playerRect->y)
		{
			switch (player->getSide()) {
			case Left:
				if (abs(velocX * m_multiplier) <= MAX_VELO && velocX <= 0)
					velocX *= m_multiplier * -1;
				break;

			case Right:
				if (abs(velocX * m_multiplier) <= MAX_VELO && velocX > 0)
					velocX *= m_multiplier * -1;
				break;
			}

		}
	}

	bool Ball::checkScoring(Player* player) {
		switch (player->getSide())
		{
		case Left:
			if (m_x <= 0 && velocX < 0)
				return true;
			break;

		case Right:
			if (m_x >= Screen::SCREEN_WIDTH && velocX > 0)
				return true;
			break;
		}

		return false;
	}

	void Ball::update() {
		//set ball coordinates
		m_x += velocX;
		m_y += velocY;
		m_rect.x = (int)m_x;
		m_rect.y = (int)m_y;

		//fill ball color
		Uint8 red = ballColor >> 24;
		Uint8 green = ballColor >> 16;
		Uint8 blue = ballColor >> 8;
		Uint8 alpha = ballColor;
		SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);

		SDL_RenderFillRect(m_renderer, &m_rect);
	}

}
