#pragma once
#include <iostream>
#include <SDL.h>

namespace Pong {

	class UIButton
	{
	private:
		SDL_Rect m_rect;
		SDL_Renderer* m_renderer = nullptr;
		SDL_Color m_color;

	public:
		UIButton();
		~UIButton();
		void init(SDL_Renderer* renderer, SDL_Color color);
		void setRect(int x, int y, int width, int height);
		void setColor(SDL_Color color);
		void update();
		bool checkClicked(SDL_Event* event);
	};
}


