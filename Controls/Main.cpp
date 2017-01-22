
#include  "Game.h"

#ifdef _DEBUG
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-audio-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-network-d.lib")

//#pragma comment(lib, "thor-d.lib")
#else
#pragma comment(lib, "sfml-graphics.lib)
#pragma comment(lib, "sfml-audio-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-network-d.lib")

#pragma comment(lib, "thor.lib"
#endif
int main()
{
	Game game;
	game.run();
	//return 0;

}