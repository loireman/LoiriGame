#include "Player.h"

void Player::initTexture()
{
	// Load a texture from file
	if (!this->texture.loadFromFile("Textures/spacecraft.png"))
	{
		std::cout << "ERROR::Player::initTexture Texture not loaded" << std::endl;
	}
}

void Player::initSprite()
{
	// Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	// Resize the sprite
	this->sprite.setScale(sf::Vector2f(0.25f, 0.25f));
}

Player::Player(sf::RenderTarget& target)
{
	this->movementSpeed = 10.f;

	this->initTexture();
	this->initSprite();

	this->setDefaultPosition(target);
}

sf::FloatRect Player::getGlobalBounds() const
{
	return sf::FloatRect(this->sprite.getGlobalBounds());
}

sf::Vector2f Player::getPosition() const
{
	return sf::Vector2f(this->sprite.getPosition());
}

void Player::setPosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setDefaultPosition(sf::RenderTarget& target)
{
	this->sprite.setPosition(sf::Vector2f(target.getSize().x / 2 - this->sprite.getGlobalBounds().width / 2, target.getSize().y - this->sprite.getGlobalBounds().height));
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}