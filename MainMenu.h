#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define Max_main_menu 3

class MainMenu
{
private:
	int MainMenuSelected;
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	sf::Event ev;

	sf::Font font;
	sf::Text mainMenu[Max_main_menu];

	void initWindow();
public:
	MainMenu();

	void run();
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void PollEvents();
	void update();
	void render();

	int MainMenuPressed() {
		return MainMenuSelected;
	}
	~MainMenu();
};

