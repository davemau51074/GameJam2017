#include "Game.h"
#include "Xbox360Controller.h"
#include "KeyHandler.h"
#include "Ring.h"

Ring::Ring() 
{
	//Ring ring;

	sf::Vector2f dimensions(1000, 2);
	sf::Vector2f coords(0, 410);

//	shape.setRadius(50);
	//shape.setFillColor(sf::Color(0, 0, 0, 0));
	//shape.setOutlineColor(sf::Color::Red);
//	shape.setOutlineThickness(10);
	//return 0;
}

void Ring::render(sf::RenderWindow m_window)
{

	m_window.clear(sf::Color(0, 0, 0, 0));
	//	m_window.draw(sf::Texture(m_backGround));
	m_window.display();
	//shape.setPosition(position);
	//	m_window.draw(shape);
	//	m_window.close();

	/*break;
	}*/

}


void Ring::update(sf::RenderWindow m_window)
{
	//xbox.update();
	//shape.setPosition(position);
//	m_window.draw(shape);
	//std::cout << "Work" << std::endl;
	//update(window);
}