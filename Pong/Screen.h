#pragma once
#include <SDL.h>

namespace Pong {
	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 900;
		const static int SCREEN_HEIGHT = 600;

	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

	public:
		Screen();

		SDL_Renderer* getRenderer();

		void init();
		void fillBackground();
		void render();
		void quit();
	};
}