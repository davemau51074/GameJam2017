/// <summary>
/// @author D.J. O'Leary
/// @version 1.0
/// 
/// Date / time started -> time ended / length of time:
/// 21/01/17 / 11:14am -> 00:00xm / 
/// </summary>

#include "..\include\Game.h"

Game::Game() :
	windowDimension(1920, 1080),
	m_window(sf::VideoMode(1920, 1080), "Colour Wave"),
	m_currentGameState(GameState::MainMenu),
	m_font()
{
	// If the file has not been loaded, throwes up a error.
	if (!m_font.loadFromFile(".\\resources\\fonts\\trebuc.ttf"))
	{
		// Prints to the console that a problem has occurred.
		std::cout << "problem loading font file" << std::endl;
	}

	//Creates a MainMenu object.
	m_mainMenu = new MainMenu(*this, windowDimension, m_font);
}

Game::~Game()
{
	switch (m_currentGameState)
	{
	case GameState::MainMenu:
		// Deletes the m_mainMenu object
		m_mainMenu->~MainMenu();
		delete m_mainMenu;
		break;

	default:
		break;
	}
}

void Game::run()
{
	//Sets up a clock to measure the elapsed time.
	sf::Clock clock;
	// Sets how long it has been since the last update to 0.
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	// Sets the framerate to 60fps.
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();

		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}

		render();

	}
}

void Game::setGameState(GameState gameState)
{
	m_currentGameState = gameState;
}

void Game::processEvents()
{
	
}

void Game::update(sf::Time time)
{

	switch (m_currentGameState)
	{
	case GameState::MainMenu:
		m_mainMenu->update();
		std::cout << "GameState = MainMenu" << std::endl;
		break;

	case GameState::Exit:
		exit(0);

	default:
		break;
	}
}

void Game::render()
{
	switch (m_currentGameState)
	{
	case GameState::MainMenu:
		m_mainMenu->render(m_window);
		break;
		
	default:
		// Clears the window then sets the colour of the window to white.
		m_window.clear(sf::Color::Black);
		// Displays the new window.
		m_window.display();
		break;
	}
}
