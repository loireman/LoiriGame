#include "AsteroidSmall.h"

void AsteroidSmall::initShape(sf::RenderTarget& target)
{
	this->shape.setRadius(25.f);
	//this->shape.setFillColor(sf::Color::Cyan);
	this->shape.setRotation(rand() % 180);
	this->shape.setOutlineColor(sf::Color(0, 0, 0, 150));
	this->shape.setOutlineThickness(1.f);
	this->shape.setPosition(
		static_cast<float> (rand() % static_cast<int> (target.getSize().x - this->shape.getGlobalBounds().width * 2) + this->shape.getGlobalBounds().width),
		0.f
	);
	this->shape.setTexture(&this->texture);
}

void AsteroidSmall::initVariables()
{
	this->hp = 50;
	this->hpMax = 50;
	this->damage = 10;
	this->points = 1;
	this->movementSpeed = 0.70f;
	this->type = 1;
}

void AsteroidSmall::initTexture()
{
	// Load a texture from file
	if (!this->texture.loadFromFile("Textures/asteroid_1.png"))
	{
		std::cout << "ERROR::AsteroidSmall::initTexture Texture not loaded" << std::endl;
	}
}

AsteroidSmall::AsteroidSmall(sf::RenderTarget& target) : Asteroids(target)
{
	this->initTexture();
	this->initShape(target);
	this->initVariables();
}

AsteroidSmall::~AsteroidSmall()
{
}
