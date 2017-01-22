#pragma once
//#include <SFML/Graphics.hpp>

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Waves.h"
#include "KeyHandler.h"
#include "Xbox360Controller.h"

class Game {

public:
	Game();
	void run();





	//void update(sf::Time);

private:
		void processEvents();
		void processGameEvents(sf::Event& event);
		void update();
		void render();
		void handleKeyInput(sf::Event& keyBoard);

		sf::RenderWindow m_window;

		sf::Keyboard keypressed;

		sf::Event keyBoard;
		KeyHandler m_keyHandler;
		Xbox360Controller xbox;

		

		sf::Vector2f dimensions();
		sf::Vector2f coords();
		sf::Vector2f m_position;
	//	sf::Window window;
	//	KeyHandler &m_keyFinder;

	//Game XboxController;

};