#pragma once
#include "KeyHandler.h"
#include "SFML/Graphics.hpp" 


class Player
{
public:
	Player(sf::Texture const & texture, sf::Vector2f pos, float speed, float jumpHeight, KeyHandler &keyHandler);

	void update(double dt);
	void render(sf::RenderWindow & window);
	void handleKeyInput();
	 
private:
	sf::Vector2f m_position;

	sf::Vector2f m_gravity;

	sf::Sprite m_playerSprite;
	sf::Texture const & m_texture;

	float m_moveForce;
	float m_jumpHeight;

	KeyHandler &m_keyHandler;
};