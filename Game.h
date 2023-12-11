#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"
#include "Asteroids.h"
#include "AsteroidSmall.h"
#include "AsteroidMedium.h"

/*
	Main class for game engine
*/

class Game
{
private:
	// Variables
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	sf::Event ev;
	sf::Texture texture;
	sf::RectangleShape background;

	// Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	
	// Resources
	sf::Font font;
	
	// Player
	Player* player;

	// Text
	sf::Text uiText;
	sf::Text introText;
	sf::Clock introClock;

	// Sound effects
	sf::SoundBuffer asteroid_destroy_buffer;
	sf::SoundBuffer asteroid_crash_buffer;
	sf::SoundBuffer passenger_save_buffer;
	sf::SoundBuffer player_death_buffer;
	sf::SoundBuffer intro_sound_buffer;
	sf::SoundBuffer bg_sound_buffer;
	sf::Sound asteroid_destroy;
	sf::Sound asteroid_crash;
	sf::Sound passenger_save;
	sf::Sound player_death;
	sf::Sound intro_sound;
	sf::Sound bg_sound;

	// Game logic
	unsigned int points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;
	bool endGame;
	bool startGame;

	// Game objects
	//std::vector<sf::CircleShape> enemies;
	std::vector<std::unique_ptr<Asteroids>> enemies;

	// Private functions
	void restartGame();
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initPlayer();
	void initTexture();
	void initBackground();
	void initSoundBuffers();
	void initSounds();
public:
	// Constructors / Destructors
	Game();
	virtual ~Game();

	// Accessors
	const bool getEndGame() const;
	
	// Functions
	void run();
	void spawnEnemy();
	void pollEvents();
	void updateMousePositions();
	void updateEnemies();
	void updatePlayer();
	void updateText();
	void update();
	void updateIntro();
	void renderEnemies(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void renderIntro();
	void render();
};

