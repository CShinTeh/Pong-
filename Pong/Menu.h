#pragma once
#include "UIButton.h"
#include "UILabel.h"
#include "Screen.h"

namespace Pong {
	class Menu
	{
	private:
		Menu(Screen* screen);
		~Menu();

		UIButton btn_play, btn_quit;
		Screen* m_screen;

	public:
		void display();
		void handleEvent();

	};
}


