#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class GameObject
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

	int hp;
	int hpMax;
	int damage;

	virtual void initVariables();
	virtual void initTexture();
	virtual void initSprite();
public:
	GameObject();
	virtual ~GameObject();

	// Accessors
	virtual const sf::Vector2f& getPos() const;

	// Functions
	virtual void move();
	virtual void update();
	virtual void render(sf::RenderTarget& target);
};

