#pragma once

#include "Asteroids.h"

class AsteroidMedium : public Asteroids
{
private:
	void initShape(sf::RenderTarget & target);
	void initVariables();
	void initTexture();
public:
	AsteroidMedium(sf::RenderTarget & target);
	virtual ~AsteroidMedium();
};

