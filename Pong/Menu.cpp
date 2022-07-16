#include "Menu.h"

namespace Pong {
	Menu::Menu(Screen* screen) : m_screen(screen) {
		SDL_Color YELLOW = { 255, 255, 157, 255 };

		btn_play.init(m_screen->getRenderer(), YELLOW);


		btn_quit.init(m_screen->getRenderer(), YELLOW);

	}

	void Menu::display() {
		

		
	}
}