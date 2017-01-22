#include "Game.h"
#include "Xbox360Controller.h"
#include "KeyHandler.h"
#include "Waves.h"

Game::Game()


:m_window(sf::VideoMode(800, 800), "BANTER")
{

	//return 0;
}


void Game::run()
{
	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.f);
	Xbox360Controller xbox;
	//What happens while the window is open
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			processEvents();
			timeSinceLastUpdate -= timePerFrame;
			update();
			xbox.update();
		
		}
		render();
		
	}

}


void Game::render()
{
	
		m_window.clear(sf::Color(0, 0, 0, 0));
		//	m_window.draw(sf::Texture(m_backGround));
		m_window.display();
		//m_window.draw(shape);

		//shape.setPosition(position);
	//	m_window.draw(shape);
		//	m_window.close();
		
		/*break;
	}*/

}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
		else
			processGameEvents(event);
	}
		
}

void Game::processGameEvents(sf::Event& event)
{


	switch (event.type)
	{
	case sf::Event::KeyPressed:
		m_keyHandler.updateKey(event.key.code, true);
		if (m_keyHandler.isPressed(sf::Keyboard::Space) || xbox.m_currentState.A == true)
		{
			std::cout << "BOOM" << std::endl;     
		}
		
		if(m_keyHandler.isPressed(sf::Keyboard::Left) || sf::Joystick::isButtonPressed(0, 3))
		{
			std::cout << "A" << std::endl;
		
		}

		if (m_keyHandler.isPressed(sf::Keyboard::Up) || sf::Joystick::isButtonPressed(0, 4))
		{
			std::cout << "B" << std::endl;

		}
		if (m_keyHandler.isPressed(sf::Keyboard::Right )  || sf::Joystick::isButtonPressed(0, 2))
		{
			std::cout << "C" << std::endl;

		}
		if (m_keyHandler.isPressed(sf::Keyboard::A) || sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) < (xbox.dpadThreshold * -1))
		{
			std::cout << "Left" << std::endl;

		}
		if (m_keyHandler.isPressed(sf::Keyboard::D) || sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > xbox.dpadThreshold)
		{
			std::cout << "Right" << std::endl;

		}
																		
		

		break;
	case sf::Event::KeyReleased:
		m_keyHandler.updateKey(event.key.code, false);
		break;
	default:
		break;
	}

	

}

void Game::update()
{
	xbox.update();
	//shape.setPosition(position);
	//m_window.draw(shape);
	//std::cout << "Work" << std::endl;
	//update(window);
}


