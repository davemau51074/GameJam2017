#pragma once

#include "Player.h"
#include "SFML\Graphics.hpp"

class Waves
{
public:
	Waves(sf::Color colour, sf::Vector2f pos);

	void update();
	void render();

private:
	float m_radius;

	sf::CircleShape m_wave;

	sf::Vector2f m_position;

	sf::Color m_colour;
};