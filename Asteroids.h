#pragma once

#include "GameObject.h"

class Asteroids : public GameObject
{
protected:
	int points;
	unsigned int type;

	sf::CircleShape shape;

	virtual void initShape(sf::RenderTarget& target);
	void initVariables();
public:
	Asteroids(sf::RenderTarget& target);
	virtual ~Asteroids() = default;

	sf::FloatRect getGlobalBounds() const;
	sf::Vector2f getPosition() const;

	void move(const float dirX, const float dirY);
	int getPoints();
	int getType();
	void render(sf::RenderTarget& target);
};

