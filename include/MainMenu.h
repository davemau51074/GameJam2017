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

class MainMenu
{
public:
	// Default constructor.
	MainMenu(sf::Vector2f windowDimentions);
	// Deconstructor
	~MainMenu();

	// Updates the main menu.
	void update();
	// Prints to the screen any images and text
	void render(sf::RenderWindow& window);

private:
	// Stores the font that will be used to write all menu text to the screen.
	sf::Font m_font;
	// Stores the text that is displayed on the play button.
	sf::Text m_playText;
	// Stores the text that is displayed on the options button.
	sf::Text m_optionsText;
	// Stores the text that is displayed on the exit button.
	sf::Text m_exitText;
	// Stores the texture that will be used as the background.
	sf::Texture m_backgroundTexture;
	// The object that the texture will be assigned to.
	sf::Sprite m_backgroundSprite;
};
#endif // !MAIN_MENU