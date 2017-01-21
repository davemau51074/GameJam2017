#pragma once
/// <summary>
/// @author D.J. O'Leary
/// @version 1.0
/// 
/// Date / time started -> time ended / length of time:
/// 21/01/17 / 9:30am -> 11:14am / 
/// </summary>

#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include <iostream>
#include "MainMenu.h"

class MainMenu;

// Enum to control the state of the game.
enum class GameState
{
	None,
	PreGameSetup,
	Game,
	MainMenu,
	Options,
	Exit,
};

class Game
{
public:
	Game();
	~Game();

	// Runs all methods inside of the game source file.
	void run();
	// Handles the current state of the game.
	GameState m_currentGameState;
	// Sets the gameState when called to the argument passed.
	void setGameState(GameState gameState);

private:
	// Method that handles all events.
	void processEvents();
	// Method to handle all other update methods.
	void update(sf::Time);
	// Method to handle all other render methods.
	void render();

	// Sets up the window that contains the program.
	sf::RenderWindow m_window;
	// Creates a object of type MainMenu.
	MainMenu *m_mainMenu;
	// Stores the font. This font wiil be used for all the menus.
	sf::Font m_font;
	// Stores the dimensions of the window.
	sf::Vector2f windowDimension;
};

#endif // !GAME
