#pragma once
/// <summary>
/// @author D.J. O'Leary
/// @version 1.0
/// 
/// Date / time started -> time ended / length of time:
/// 21/01/17 / 2:53am -> 3:10am / 
/// </summary>

#ifndef MAIN_MENU
#define MAIN_MENU
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Game.h"
class Game;

enum class Selected
{
	Play,
	Options,
	Exit
};

class MainMenu
{
public:
	// Default constructor.
	MainMenu(Game & game, sf::Vector2f windowDimentions, sf::Font font);
	// Deconstructor
	~MainMenu();

	// Updates the main menu.
	void update();
	// Prints to the screen any images and text
	void render(sf::RenderWindow& window);
	// Selected option on the menu.
	Selected m_selectedOption;
	// Sets the option when a key is pressed.
	void setSelectedOption(Selected newlySelected);

private:
	// A copy of the game object.
	Game *m_game;

	// Stores the font that will be used to write all menu text to the screen.
	sf::Font m_font;
	// Stores the text that is displayed on the play button.
	sf::Text m_playText;
	// Stores the text that is displayed on the options button.
	sf::Text m_optionsText;
	// Stores the text that is displayed on the exit button.
	sf::Text m_exitText;
	
	// The rectangle that stores the bounding rectangle for the text.
	sf::FloatRect m_playTextRectangle;
	sf::FloatRect m_optionsTextRectangle;
	sf::FloatRect m_exitTextRectangle;

	sf::Keyboard previousKeyboardState;

	// Stores the texture that will be used as the background.
	sf::Texture m_backgroundTexture;
	// The object that the texture will be assigned to.
	sf::Sprite m_backgroundSprite;
};
#endif // !MAIN_MENU