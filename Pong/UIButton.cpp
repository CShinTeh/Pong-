#include "UIButton.h"

namespace Pong {

	UIButton::UIButton() {

	}

	UIButton::~UIButton() {

	}

	void UIButton::init(SDL_Renderer* renderer, SDL_Color color) {
		m_renderer = renderer;
		m_color = color;
	}

	void UIButton::setRect(int x, int y, int width, int height) {
		m_rect.x = x;
		m_rect.y = y;
		m_rect.w = width;
		m_rect.h = height;
	}

	void UIButton::setColor(SDL_Color color) {
		m_color = color;
	}

	void UIButton::update() {
		if (m_renderer != nullptr) {
			SDL_SetRenderDrawColor(m_renderer, m_color.r, m_color.g, m_color.b, m_color.a);
			SDL_RenderFillRect(m_renderer, &m_rect);
		}
		else {
			std::cout << "Button not yet initialized! ";
		}

	}

	bool UIButton::checkClicked(SDL_Event* event) {
		SDL_Point point;
		SDL_GetMouseState(&point.x, &point.y);

		if (SDL_PointInRect(&point, &m_rect) && event->type == SDL_MOUSEBUTTONDOWN) {
			return true;
		}
		else {
			return false;
		}
	}

}