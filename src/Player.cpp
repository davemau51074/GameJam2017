#include "Player.h"
#include "..\include\Player.h"

Player::Player(sf::Texture const & texture, sf::Vector2f pos, KeyHandler &keyHandler) :
	m_texture(texture),
	m_position(pos),
	m_keyHandler(keyHandler),
	m_jumpHeight(0.1),
	m_gravity(3),
	m_moveState(MoveState::Stand)
{
	m_playerSprite.setTexture(m_texture);

	sf::IntRect baseRect(0, 0, 128, 128);
	m_playerSprite.setTextureRect(baseRect);
	m_playerSprite.setOrigin(baseRect.width / 2.0, baseRect.height / 2.0);
	m_playerSprite.setPosition(pos);
}

void Player::update(double dt)
{
	handleKeyInput(dt);

	m_playerSprite.setPosition(m_position);


}

void Player::render(sf::RenderWindow & window)
{
	window.draw(m_playerSprite);
}

void Player::handleKeyInput(double dt)
{
	sf::Keyboard input;

	if (m_keyHandler.isPressed(input.D))
	{
		moveRight();
	}
	if (m_keyHandler.isPressed(input.A))
	{
		moveLeft();
	}

	if (m_keyHandler.isPressed(input.Up))
	{
		m_wave = Waves(m_colourA, m_position);
	}
	if (m_keyHandler.isPressed(input.Left))
	{
		m_wave = Waves(m_colourB, m_position);
	}
	if (m_keyHandler.isPressed(input.Right))
	{
		m_wave = Waves(m_colourC, m_position);
	}
}

void Player::moveRight()
{
	m_position.x += 0.2;
}

void Player::moveLeft()
{
	m_position.x -= 0.2;
}

void Player::jump()
{
	
}
