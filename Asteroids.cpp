#include "Asteroids.h"

void Asteroids::initShape(sf::RenderTarget& target)
{
}

void Asteroids::initVariables()
{
	this->points = 0;
	this->type = 0;
}

Asteroids::Asteroids(sf::RenderTarget& target)
{
	this->initShape(target);
	this->initVariables();
}

sf::FloatRect Asteroids::getGlobalBounds() const
{
	return sf::FloatRect(this->shape.getGlobalBounds());
}

sf::Vector2f Asteroids::getPosition() const
{
	return sf::Vector2f(this->shape.getPosition());
}

void Asteroids::move(const float dirX, const float dirY)
{
	this->shape.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

int Asteroids::getPoints()
{
	return this->points;
}

int Asteroids::getType()
{
	return this->type;
}

void Asteroids::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
