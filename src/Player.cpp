#include "Player.h"
#include "..\include\Player.h"

Player::Player(sf::Texture const & texture, sf::Vector2f pos, float force, float jumpHeight, KeyHandler &keyHandler) :
	m_texture(texture),
	m_position(pos),
	m_moveForce(force),
	m_jumpHeight(jumpHeight),
	m_keyHandler(keyHandler)
{
	m_playerSprite.setTexture(m_texture);

	sf::IntRect baseRect(0, 0, 128, 128);
	m_playerSprite.setTextureRect(baseRect);
	m_playerSprite.setOrigin(baseRect.width / 2.0, baseRect.height / 2.0);
	m_playerSprite.setPosition(pos);
}

void Player::update(double dt)
{
	handleKeyInput();



	m_playerSprite.setPosition(m_position);
}

void Player::render(sf::RenderWindow & window)
{
	window.draw(m_playerSprite);
}

void Player::handleKeyInput()
{
	sf::Keyboard input;


	if (m_keyHandler.isPressed(input.Right) ||
		m_keyHandler.isPressed(input.D))
	{
		m_position.x += m_moveForce;
	}
	if (m_keyHandler.isPressed(input.Left) ||
		m_keyHandler.isPressed(input.A))
	{
		m_position.x -= m_moveForce;
	}
}
