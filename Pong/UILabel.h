#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#pragma once

namespace Pong {

	class UILabel
	{

	private:
		const std::string FONT_PATH = "f_8bit.ttf";
		std::string m_text;
		int m_font_size;
		SDL_Color m_color = { 0, 0, 0, 255 };
		SDL_Rect m_text_rect;
		SDL_Texture* m_texture = NULL;
		TTF_Font* m_font_style = NULL;
		SDL_Renderer* m_renderer = NULL;

	public:
		UILabel(SDL_Renderer* renderer, int font_size);
		~UILabel();

		void setColor(SDL_Color color);
		void setText(std::string text);
		void setPos(int x, int y);
		void update();

	};
}

