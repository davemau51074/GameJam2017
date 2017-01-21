/// <summary>
/// @author D.J. O'Leary
/// @version 1.0
/// 
/// Date / time started -> time ended / length of time:
/// 21/01/17 / 3:14am -> 3:37am /
/// 21/01/17 / 4:09am -> 4:33am /
/// </summary>

#include "MainMenu.h"

/// <summary>
/// Initialization of any MainMenu object.
/// 
/// The "windowDimentions" param is the resolution of the window stored.
/// </summary>
/// <param name="windowDimentions"></param>
MainMenu::MainMenu(sf::Vector2f windowDimentions) :
	m_font(),
	m_playText("Play", m_font, 10),
	m_optionsText("Options", m_font, 10),
	m_exitText("Exit", m_font, 10)
{
	#pragma region LoadingAssets

	// If the file has not been loaded, throwes up a error.
	if (!m_font.loadFromFile(".\\resources\\fonts\\trebuc.ttf"))
	{
		// Prints to the console that a problem has occurred.
		std::cout << "problem loading font file" << std::endl;
	}

	// Load the texture from the file.
	if (!m_backgroundTexture.loadFromFile(".\\resources\\images\\placeHolder.png"))
	{
		std::cout << "Error loading texture file" << std::endl;
	}

	#pragma endregion

	#pragma region InitializingTextAndTextures
	
	// Sets the X and Y coordinate respectively for the text.
	m_playText.setPosition(windowDimentions.x * 0.5f, windowDimentions.y * 0.25f);
	// Sets the colour of the text to the colour white.
	m_playText.setColor(sf::Color::White);

	m_optionsText.setPosition(windowDimentions.x * 0.5f, windowDimentions.y * 0.5f);
	m_optionsText.setColor(sf::Color::White);

	m_exitText.setPosition(windowDimentions.x * 0.5f, windowDimentions.y * 0.75f);
	m_exitText.setColor(sf::Color::White);

	// Sets the sprites texture to the one loaded for use as the background.
	m_backgroundSprite.setTexture(m_backgroundTexture);

	#pragma endregion
}

/// <summary>
/// Destroys the MainMenu object once it is no longer in use.
/// </summary>
MainMenu::~MainMenu()
{
	std::cout << "deconstructing Menu" << std::endl;
}

/// <summary>
/// Checks for button presses to see where the user is on the 
/// menu or if they have selected a option.
/// </summary>
void MainMenu::update()
{

}

/// <summary>
/// Uses the "window" param to render assets to the screen.
/// </summary>
/// <param name="window"></param>
void MainMenu::render(sf::RenderWindow& window)
{
	// Clears the window.
	window.clear;
	// Renders the background texture.
	window.draw(m_backgroundSprite);
	window.draw(m_playText);
	window.draw(m_optionsText);
	window.draw(m_exitText);
	
	// Displays everything that has been rendered so far.
	window.display();
}
