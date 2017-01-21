#pragma once

#include <memory>
#include "KeyHandler.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();
	void loadResources();

	void update(double dt);
	void render();

	void processEvents();
	void processGameEvents(sf::Event&);


protected:
	std::unique_ptr<Player> m_player;

	sf::RenderWindow m_window;

	sf::Texture m_texture;

	

	KeyHandler m_keyHandler;
};