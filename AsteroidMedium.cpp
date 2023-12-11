#include "AsteroidMedium.h"

void AsteroidMedium::initShape(sf::RenderTarget& target)
{
	this->shape.setRadius(30.f);
	//this->shape.setFillColor(sf::Color::Green);
	//this->shape.setOutlineColor(sf::Color(0, 0, 0, 150));
	//this->shape.setOutlineThickness(1.f);
	this->shape.setPosition(
		static_cast<float> (rand() % static_cast<int> (target.getSize().x - this->shape.getGlobalBounds().width * 2) + this->shape.getGlobalBounds().width),
		0.f
	);
	this->shape.setTexture(&this->texture);
}

void AsteroidMedium::initVariables()
{
	this->hp = 100;
	this->hpMax = 100;
	this->damage = 10;
	this->points = 3;
	this->movementSpeed = 0.5f;
	this->type = 2;
}

void AsteroidMedium::initTexture()
{
	// Load a texture from file
	if (!this->texture.loadFromFile("Textures/cat_falling.png"))
	{
		std::cout << "ERROR::AsteroidMedium::initTexture Texture not loaded" << std::endl;
	}
}

AsteroidMedium::AsteroidMedium(sf::RenderTarget& target) : Asteroids(target)
{
	this->initTexture();
	this->initShape(target);
	this->initVariables();
}

AsteroidMedium::~AsteroidMedium()
{
}