#pragma once
#include "KeyHandler.h"
#include "Waves.h"
#include "SFML/Graphics.hpp" 

enum MoveState
{
	Rise,
	Fall,
	Bounce,
	Stand
};

class Player
{
public:
	Player(sf::Texture const & texture, sf::Vector2f pos, KeyHandler &keyHandler);

	void update(double dt);
	void render(sf::RenderWindow & window);
	void handleKeyInput(double dt);
	
	void moveRight();
	void moveLeft();

	void jump();
	 
private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

	float m_gravity;

	sf::Sprite m_playerSprite;
	sf::Texture const & m_texture;

	Waves m_wave;

	float m_jumpHeight;
	MoveState m_moveState;

	sf::Color m_colourA;
	sf::Color m_colourB;
	sf::Color m_colourC;

	KeyHandler &m_keyHandler;
};