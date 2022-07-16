#include <iostream>
#include "Screen.h"

namespace Pong {
	Screen::Screen():m_window(NULL), m_renderer(NULL) {}

	SDL_Renderer* Screen::getRenderer() {
		return m_renderer;
	}

	void Screen::init() {

		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::cout << "SDL initializatioj failed.\n" << SDL_GetError();
		}

		m_window = SDL_CreateWindow(
			"Pong by ME",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
		);

		if (m_window == NULL) {
			std::cout << "Window cant be created.\n" << SDL_GetError();
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);

		if (m_renderer == NULL) {
			std::cout << "Renderer cant be created.\n" << SDL_GetError();
		}

	}

	void Screen::fillBackground() {
		//Seperate Uint32 to RGBA values
		Uint32 rgba = 0x003D6BFF; //blue
		Uint8 red = rgba >> 24;
		Uint8 green = rgba >> 16;
		Uint8 blue = rgba >> 8;
		Uint8 alpha = rgba;	
		SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
		SDL_RenderClear(m_renderer);
	}

	void Screen::render() {
		SDL_RenderPresent(m_renderer);
	}

	void Screen::quit() {
		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_Quit();
	}
}