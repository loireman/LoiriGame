#pragma once

#include "Asteroids.h"

class AsteroidSmall : public Asteroids
{
private:

	void initShape(sf::RenderTarget& target);
	void initVariables();
	void initTexture();
public:
	AsteroidSmall(sf::RenderTarget& target);
	virtual ~AsteroidSmall();
};

