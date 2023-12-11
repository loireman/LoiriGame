#include "Game.h"


void Game::restartGame()
{
	this->health = 5; // TODO: move to Player
	this->points = 0;
	this->enemySpawnTimer = 0.f;
	this->maxEnemies = 20;
	this->mouseHeld = false;
	this->endGame = false;
	this->player->setDefaultPosition(*this->window);
	this->initText();
	this->bg_sound.setPlayingOffset(sf::Time());
	this->bg_sound.play();
}

// Private functions

void Game::initVariables()
{
	this->window = nullptr;
	this->health = 5; // TODO: move to Player
	this->points = 0;
	this->enemySpawnTimer = 0.f;
	this->enemySpawnTimerMax = 30.f;
	this->maxEnemies = 20;
	this->mouseHeld = false;
	this->endGame = false;
	this->startGame = true;
}

void Game::initWindow()
{
	/*this->videomode.height = 720;
	this->videomode.width = 1280;*/
	this->window = new sf::RenderWindow(this->videomode.getFullscreenModes()[0], "Loiri game", sf::Style::Fullscreen);
	// can add sf::Style::Titlebar | sf::Style::Close to RenderWindow
	this->window->setFramerateLimit(60);
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/joystix.otf"))
	{
		std::cout << "ERROR::Game::initFonts::Failed to load font" << std::endl;
	}
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(20);
	this->uiText.setFillColor(sf::Color(255, 255, 255, 200));
	this->uiText.setOutlineColor(sf::Color::Black);
	this->uiText.setString("None");
	this->uiText.setPosition(sf::Vector2f(10.f, 10.f));

	this->introText.setFont(this->font);
	this->introText.setCharacterSize(60);
	this->introText.setString("Loiri Galaxy Cats");
	this->introText.setPosition(sf::Vector2f(
		window->getSize().x / 2 - this->introText.getGlobalBounds().width / 2,
		window->getSize().y / 2 - this->introText.getGlobalBounds().height));
}

void Game::initPlayer()
{
	this->player = new Player(*this->window);
}

void Game::initTexture()
{
	// Load a texture from file
	if (!this->texture.loadFromFile("Textures/background.jpg"))
	{
		std::cout << "ERROR::Game::initTexture Texture not loaded" << std::endl;
	}
}

void Game::initBackground()
{
	this->background = sf::RectangleShape();
	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	this->background.setTexture(&this->texture);
	this->background.setPosition(0.f, 0.f);
}

void Game::initSoundBuffers()
{
	// Load intro sound
	if (!this->intro_sound_buffer.loadFromFile("Sounds/intro.mp3"))
	{
		std::cout << "ERROR::Game::initSoundBuffers Sound Sounds/intro.mp3 not loaded" << std::endl;
	}
	// Load background sound
	if (!this->bg_sound_buffer.loadFromFile("Sounds/bg_music.wav"))
	{
		std::cout << "ERROR::Game::initSoundBuffers Sound Sounds/bg_music.wav not loaded" << std::endl;
	}
	// Load asteroid explotion sound
	if (!this->asteroid_destroy_buffer.loadFromFile("Sounds/boom.mp3"))
	{
		std::cout << "ERROR::Game::initSoundBuffers Sound Sounds/boom.mp3 not loaded" << std::endl;
	}
	// Load asteroid crash sound
	if (!this->asteroid_crash_buffer.loadFromFile("Sounds/metalpipe.wav"))
	{
		std::cout << "ERROR::Game::initSoundBuffers Sound Sounds/metalpipe.mp3 not loaded" << std::endl;
	}
	// Load passenger save sound
	if (!this->passenger_save_buffer.loadFromFile("Sounds/yay.mp3"))
	{
		std::cout << "ERROR::Game::initSoundBuffers Sound Sounds/yay.mp3 not loaded" << std::endl;
	}
	// Load passenger save sound
	if (!this->player_death_buffer.loadFromFile("Sounds/bruh.mp3"))
	{
		std::cout << "ERROR::Game::initSoundBuffers Sound Sounds/bruh.mp3 not loaded" << std::endl;
	}
}

void Game::initSounds()
{
	this->intro_sound.setBuffer(this->intro_sound_buffer);
	this->bg_sound.setBuffer(this->bg_sound_buffer);
	this->asteroid_destroy.setBuffer(this->asteroid_destroy_buffer);
	this->asteroid_crash.setBuffer(this->asteroid_crash_buffer);
	this->passenger_save.setBuffer(this->passenger_save_buffer);
	this->player_death.setBuffer(this->player_death_buffer);

	this->bg_sound.setLoop(true);
	this->bg_sound.setVolume(50.f);
}


// Contructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initTexture();
	this->initBackground();
	this->initFonts();
	this->initText();
	this->initPlayer();
	this->initSoundBuffers();
	this->initSounds();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
}

const bool Game::getEndGame() const
{
	return this->endGame;
}
// Functions
void Game::spawnEnemy()
{
	/**
	* @return void
	* 
	* Spawn enemy, set color and position
	* - Sets a random position
	* - Sets a random color
	* - Adds enemy to the vector
	*/
	
	if (rand() % 10 == 0)
	{
		this->enemies.push_back(std::make_unique<AsteroidMedium>(*this->window));
	}
	else
	{
		this->enemies.push_back(std::make_unique<AsteroidSmall>(*this->window));
	}

	// Remove enemies from screen
}

void Game::pollEvents()
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

void Game::updateMousePositions()
{
	/**
	* @return void
	* Update the mouse positions
	* - Mouse position relative to window (Vector2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
{
	/**
	* @return void
	* 
	* Update enemy spawn timer and spawn enemies.
	* Moves the enemies to the player.
	* Removes the enemies from the edge of screen. // TODO
	*/

	// Update spawn enemy timer
	if (this->enemies.size() < this->maxEnemies)
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			// Spawn enemy and reset timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;

	// Move the enemies
	for (auto it = enemies.begin(); it != enemies.end();)
	{
		(*it)->move(0.f, 3.f + (this->points / 100));

		if ((*it)->getPosition().y > this->window->getSize().y)
		{
			// Reduce health for each enemy out of the window
			this->health -= 1;

			// Erase the enemy and obtain the iterator to the next element
			it = enemies.erase(it);
		}
		else if ((*it)->getGlobalBounds().intersects((this->player->getGlobalBounds())))
		{
			if ((*it)->getType() == 2)
			{
				this->points += (*it)->getPoints();
				this->passenger_save.play();
			}
			else
			{ 
				this->asteroid_crash.play();
				this->health -= 1;
			}

			// Erase the enemy and obtain the iterator to the next element
			it = enemies.erase(it);
		}
		else
		{
			// Move to the next enemy in the vector
			++it;
		}
	}

	// Check if clicked upon
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool enemyDeleted = false;

			for (auto it = enemies.begin(); it != enemies.end();)
			{
				if ((*it)->getGlobalBounds().contains(this->mousePosView) && (*it)->getType() == 1)
				{
					// Reduce health for each enemy out of the window
					this->points += (*it)->getPoints();
					this->asteroid_destroy.play();

					// Erase the enemy and obtain the iterator to the next element
					it = enemies.erase(it);
				}
				else
				{
					// Move to the next enemy in the vector
					++it;
				}
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}
}

void Game::updatePlayer()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);

	// Check and handle collision with window boundaries
	sf::Vector2f playerPosition = this->player->getPosition();
	sf::FloatRect playerSize = this->player->getGlobalBounds();

	// Check collision with the left boundary
	if (playerPosition.x < 0)
	{
		this->player->setPosition(0, playerPosition.y);
	}

	// Check collision with the right boundary
	if (playerPosition.x + playerSize.width > this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - playerSize.width, playerPosition.y);
	}

	// Check collision with the top boundary
	if (playerPosition.y < 0)
	{
		this->player->setPosition(playerPosition.x, 0);
	}

	// Check collision with the bottom boundary
	if (playerPosition.y + playerSize.height > this->window->getSize().y)
	{
		this->player->setPosition(playerPosition.x, this->window->getSize().y - playerSize.height);
	}
}

void Game::updateText()
{
	std::stringstream ss;

	ss << "Score: " << this->points << std::endl
		<< "Health: " << this->health;

	this->uiText.setString(ss.str());
}

// Functions
void Game::run()
{
	this->intro_sound.play();

	while (this->window->isOpen())
	{
		if (this->startGame)
		{
			this->updateIntro();
			this->renderIntro();
		}
		else
		{
			this->update();
			this->render();
		}
	}
}

void Game::update()
{
	this->pollEvents();

	if (!this->endGame)
	{
		this->updateMousePositions();

		this->updateText();

		this->updateEnemies();

		this->updatePlayer();

		// End game condition
		if (this->health <= 0)
		{
			this->endGame = true;

			this->player_death.play();
		}
	}
	else
	{
		if (this->enemies.size() > 0) {
			this->enemies.clear();
		}

		std::stringstream ss;

		ss << "Game over" << std::endl
			<< "Your score: " << this->points << std::endl
			<< std::endl
			<< "Press enter to restart";

		this->uiText.setString(ss.str());
		this->uiText.setCharacterSize(60);
		this->uiText.setPosition(sf::Vector2f(
			this->window->getSize().x / 2 - this->uiText.getGlobalBounds().width / 2, 
			this->window->getSize().y / 2 - this->uiText.getGlobalBounds().height));
		this->bg_sound.pause();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			this->restartGame();
	}
}

void Game::updateIntro()
{
	sf::Time introTime = this->introClock.getElapsedTime();

	if (introTime.asSeconds() < 5.0f)
	{

		// Calculate alpha for fade in
		int alpha = static_cast<int>(255 * (introTime.asSeconds() / 5.0f));
		this->introText.setFillColor(sf::Color(255, 255, 255, alpha));
	}
	else if (introTime.asSeconds() < 10.0f)
	{
		// Calculate alpha for fade out
		int alpha = static_cast<int>(255 * (1.0f - (introTime.asSeconds() - 5.0f) / 5.0f));
		this->introText.setFillColor(sf::Color(255, 255, 255, alpha));
	}
	else
	{
		introText.setFillColor(sf::Color(255, 255, 255, 0));
		this->startGame = false;
		this->bg_sound.play();
	}
}

void Game::renderEnemies(sf::RenderTarget& target)
{
	// Render the enemies
	for (const auto& enemy : enemies)
	{
		enemy->render(target);
	}
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}

void Game::renderIntro()
{
	this->window->clear();

	// Render introText
	this->window->draw(introText);

	this->window->display();
}

void Game::render()
{
	/**
	* @return void
	*   - clear old frame
	*   - render new objects
	*   - display frame in window
	*   Renders the game objects
	*/
	this->window->clear();

	this->window->draw(this->background);

	// Draw game objects
	this->renderEnemies(*this->window);

	// Render player
	this->player->render(*this->window);

	this->renderText(*this->window);
	this->window->display();
}
