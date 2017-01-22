#include "Waves.h"

Waves::Waves(sf::Color colour, sf::Vector2f pos) :
	m_colour(colour),
	m_position(pos),
	m_radius(0)
{
	m_wave.setFillColor(sf::Color(0, 0, 0, 0));
	m_wave.setOutlineColor(m_colour);
	m_wave.setOutlineThickness(5);
	m_wave.setRadius(m_radius);
}

void Waves::update()
{
	m_radius += 0.5;
	m_wave.setRadius(m_radius);

	m_colour.a--;
	m_wave.setOutlineColor(m_colour);
}


