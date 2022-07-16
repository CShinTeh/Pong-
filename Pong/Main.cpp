#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_ttf.h>
#include "Game.h"
using namespace Pong;

int main() {
	SDL_Color WHITE = { 255, 255, 255, 255 };
	SDL_Color YELLOW = { 255, 255, 159, 255 };

	Screen screen;
	screen.init();
	TTF_Init();

	Game game(&screen);


	const int FPS = 60;
	const int MILISECOND_PER_FRAME = 1000 / FPS;
	Uint64 frameStart;
	int frameDuration;

	game.running = true;

	game.init();

	while (game.running) {
		frameStart = SDL_GetTicks64();

		game.run();

		//cap frame rate
		frameDuration = SDL_GetTicks64() - frameStart;

		if (MILISECOND_PER_FRAME > frameDuration) {
			SDL_Delay(MILISECOND_PER_FRAME - frameDuration);
		}
	}

	screen.quit();
	TTF_Quit();

	return 0;
}