#include "UILabel.h"

namespace Pong {

	UILabel::UILabel(SDL_Renderer* renderer, int font_size) : m_renderer(renderer), m_font_size(font_size) {
		m_font_style = TTF_OpenFont(FONT_PATH.c_str(), m_font_size);
		if (m_font_style == nullptr) {
			std::cout << "Font not loaded!" << std::endl;
			std::cout << TTF_GetError() << std::endl;
		}

	}

	UILabel::~UILabel() {
		SDL_DestroyTexture(m_texture);
		TTF_CloseFont(m_font_style);
	}

	void UILabel::setColor(SDL_Color color) {
		m_color = color;
	}

	void UILabel::setText(std::string str) {
		m_text = str;
	}

	void UILabel::setPos(int x, int y) {
		m_text_rect.x = x;
		m_text_rect.y = y;
	}

	void UILabel::update() {
		//display text at given coord
		SDL_Surface* text_surface = TTF_RenderText_Solid(m_font_style, m_text.c_str(), m_color);
		m_texture = SDL_CreateTextureFromSurface(m_renderer, text_surface);

		m_text_rect.w = text_surface->w;
		m_text_rect.h = text_surface->h;

		SDL_FreeSurface(text_surface);
		SDL_RenderCopy(m_renderer, m_texture, NULL, &m_text_rect);
	}


}
