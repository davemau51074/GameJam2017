#include "Game.h"

Game::Game()
	: m_window(sf::VideoMode(1440, 900, 32), "Movement Test", sf::Style::Default)
{
	loadResources();

	m_player.reset(new Player(m_texture, sf::Vector2f(500, 800), m_keyHandler));
}

void Game::run()
{
	sf::Clock clock;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		processEvents();

		update(dt.asMilliseconds());
		render();
	}
}

void Game::loadResources()
{
	if (!m_texture.loadFromFile("./resources/images/PlayerMoveSheet.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());
	}
}

void Game::update(double dt)
{
	m_player->update(dt);
}

void Game::render()
{
	//m_window.clear(sf::Color(220,220,220,255));

	m_window.clear(m_colorA);
	m_player->render(m_window);
	m_window.display();
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}

void Game::processGameEvents(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		m_keyHandler.updateKey(event.key.code, true);
		break;
	case sf::Event::KeyReleased:
		m_keyHandler.updateKey(event.key.code, false);
		break;
	default:
		break;
	}
}