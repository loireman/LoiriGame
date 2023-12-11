#pragma once

#include "GameObject.h"

class Player : protected GameObject
{
private:
	

	void initTexture();
	void initSprite();
public:
	Player(sf::RenderTarget& target);

	sf::FloatRect getGlobalBounds() const;
	sf::Vector2f getPosition() const;

	void setPosition(float x, float y);
	void setDefaultPosition(sf::RenderTarget& target);

	void move(const float dirX, const float dirY);
	void render(sf::RenderTarget& target);
};

