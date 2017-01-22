#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h> 
#include <gl/GLU.h> 
#include <SFML/Graphics.hpp>
#include <string>


using namespace std;
using namespace sf;

class Main
{
public:

	void run();
private:

	Window window;
	sf::RenderWindow m_window;
	sf::Keyboard keypressed;
	bool isRunning = false;
	/*void initialize();
	void update();
	void draw();
	void unload();*/
};