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
MainMenu::MainMenu(Game & game, sf::Vector2f windowDimentions, sf::Font font) :
	m_game(&game),
	m_font(font),
	m_playText("Play", m_font, 60),
	m_optionsText("Options", m_font, 60),
	m_exitText("Exit", m_font, 60),
	m_selectedOption(Selected::Play)
{
	#pragma region LoadingAssets

	// Load the texture from the file.
	if (!m_backgroundTexture.loadFromFile(".\\resources\\images\\placeHolder.png"))
	{
		std::cout << "Error loading texture file" << std::endl;
	}

	#pragma endregion

	#pragma region InitializingTextAndTextures
	

	
	// Gets the dimensions of the rectangle that contains the text.
	m_playTextRectangle = m_playText.getLocalBounds();
	// Centres the origin of the text.
	m_playText.setOrigin(m_playTextRectangle.left + m_playTextRectangle.width / 2.0f, m_playTextRectangle.top + m_playTextRectangle.height / 2.0f);
	// Sets the X and Y coordinate respectively for the text.
	m_playText.setPosition(windowDimentions.x * 0.5f, windowDimentions.y * 0.40f);

	m_optionsTextRectangle = m_optionsText.getLocalBounds();
	m_optionsText.setOrigin(m_optionsTextRectangle.left + m_optionsTextRectangle.width / 2.0f, m_optionsTextRectangle.top + m_optionsTextRectangle.height / 2.0f);
	m_optionsText.setPosition(windowDimentions.x * 0.5f, windowDimentions.y * 0.6f);

	m_exitTextRectangle = m_exitText.getLocalBounds();
	m_exitText.setOrigin(m_exitTextRectangle.left + m_exitTextRectangle.width / 2.0f, m_exitTextRectangle.top + m_exitTextRectangle.height / 2.0f);
	m_exitText.setPosition(windowDimentions.x * 0.5f, windowDimentions.y * 0.80f);

	// Sets the sprites texture to the one loaded for use as the background.
	m_backgroundSprite.setTexture(m_backgroundTexture);

	#pragma endregion
}

/// <summary>
/// Destroys the MainMenu object once it is no longer in use.
/// </summary>
MainMenu::~MainMenu()
{
	// Print to a console window that the menu is being deconstructed.
	std::cout << "deconstructing Menu" << std::endl;
}

/// <summary>
/// Checks for button presses to see where the user is on the 
/// menu or if they have selected a option.
/// </summary>
void MainMenu::update()
{
	sf::Keyboard keyboardState;
	
	switch (m_selectedOption)
	{
	case Selected::Play:
		// Entering the currently selected option.
		if ((keyboardState.isKeyPressed(sf::Keyboard::Return) && !previousKeyboardState.isKeyPressed(sf::Keyboard::Return)) || sf::Joystick::isButtonPressed(0,0))
		{
			m_game->setGameState(GameState::Game);
		}
		// The option below this on the menu.
		else if (keyboardState.isKeyPressed(sf::Keyboard::S) || keyboardState.isKeyPressed(sf::Keyboard::Down))
		{
			setSelectedOption(Selected::Options);
		}

	case Selected::Options:
		// Entering the currently selected option.
		if ((keyboardState.isKeyPressed(sf::Keyboard::Return) && !previousKeyboardState.isKeyPressed(sf::Keyboard::Return)) || sf::Joystick::isButtonPressed(0, 0))
		{
			m_game->setGameState(GameState::Options);
		}
		// The option below this on the menu.
		else if (keyboardState.isKeyPressed(sf::Keyboard::S) || keyboardState.isKeyPressed(sf::Keyboard::Down))
		{
			setSelectedOption(Selected::Exit);
		}
		// The option above this on the menu.
		else if (keyboardState.isKeyPressed(sf::Keyboard::W) || keyboardState.isKeyPressed(sf::Keyboard::Up))
		{
			setSelectedOption(Selected::Play);
		}

	case Selected::Exit:
		// Entering the currently selected option.
		if ((keyboardState.isKeyPressed(sf::Keyboard::Return) && !previousKeyboardState.isKeyPressed(sf::Keyboard::Return)) || sf::Joystick::isButtonPressed(0, 0))
		{
			m_game->setGameState(GameState::Exit);
		}
		// The option above this on the menu.
		else if (keyboardState.isKeyPressed(sf::Keyboard::W) || keyboardState.isKeyPressed(sf::Keyboard::Up))
		{
			setSelectedOption(Selected::Options);
		}
	}

	previousKeyboardState = keyboardState;

}

/// <summary>
/// Uses the "window" param to render assets to the screen.
/// </summary>
/// <param name="window"></param>
void MainMenu::render(sf::RenderWindow& window)
{
	// Clears the window.
	window.clear(sf::Color::Black);

	switch (m_selectedOption)
	{
	case Selected::Play:

		m_exitText.setColor(sf::Color::Yellow);
		window.draw(m_playText);
		
		m_exitText.setColor(sf::Color::White);
		window.draw(m_optionsText);

		m_exitText.setColor(sf::Color::White);
		window.draw(m_exitText);

		break;

	case Selected::Options:
		
		m_exitText.setColor(sf::Color::White);
		window.draw(m_playText);
		
		m_exitText.setColor(sf::Color::Yellow);
		window.draw(m_optionsText);
		
		m_exitText.setColor(sf::Color::White);
		window.draw(m_exitText);
		
		break;

	case Selected::Exit:
		
		m_playText.setColor(sf::Color::White);
		window.draw(m_playText);
		
		m_optionsText.setColor(sf::Color::White);
		window.draw(m_optionsText);
		
		m_exitText.setColor(sf::Color::Yellow);
		window.draw(m_exitText);
		
		break;

	default:
		break;
	}

	// Displays everything that has been rendered so far.
	window.display();
}

void MainMenu::setSelectedOption(Selected newlySelected)
{
	m_selectedOption = newlySelected;
}
