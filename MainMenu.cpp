#include "MainMenu.h"

void MainMenu::initWindow()
{
	this->videomode.height = 720;
	this->videomode.width = 1280;
	this->window = new sf::RenderWindow(this->videomode, "Loiri game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

MainMenu::MainMenu()
{
	this->initWindow();

	if (this->font.loadFromFile("Fonts/joystix.otf"))
	{
		std::cout << "ERROR::MainMenu::initFonts::Failed to load font" << std::endl;
	}

	// Play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(this->window->getSize().x / 2 - mainMenu[0].getGlobalBounds().width, 200);
	// Credits
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Created by Andy Loiri");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(this->window->getSize().x / 2 - mainMenu[1].getGlobalBounds().width, 300);
	// Quit
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("Quit");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(this->window->getSize().x / 2 - mainMenu[2].getGlobalBounds().width, 400);
}

void MainMenu::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; ++i)
	{
		window.draw(mainMenu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0) 
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);

		MainMenuSelected++;
		if (MainMenuSelected == Max_main_menu)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

void MainMenu::PollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void MainMenu::update()
{

}

void MainMenu::render()
{
}

MainMenu::~MainMenu()
{
}
