#pragma once

#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER


#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;



struct GamePadState
{


public:


	bool A ;
	bool B = false;
	bool X;
	bool Y;
	bool LB;
	bool RB;
	bool LeftThumbStickClick;
	bool RightThumbStickClick;
	bool DpadD;
	bool DpadU;
	bool DpadL;
	bool DpadR;
	bool Start;
	bool Back;
	bool Xbox;
	float RTrigger;
	float LTrigger;
	//float z = 360;
	sf::Vector2f RightThumbStick;
	sf::Vector2f LeftThumbStick;






};



class Xbox360Controller
{
public:


	sf::Text textforA;
	sf::Text textforB;
	sf::Text textforX;
	sf::Text textforY;
	sf::Text textforLB;
	sf::Text textforRB;
	sf::Text textforLeftThumbStickClick;
	sf::Text textforRightThumbStickClick;
	sf::Text textforLeftAnalogStick;
	sf::Text textforRightAnalogStick;
	sf::Text textforDpadX;
	sf::Text textforDpadY;
	sf::Text textforStart;
	sf::Text textforBack;
	sf::Text textforXbox;
	sf::Text textforRTrigger;
	sf::Text textforLTrigger;

	
	sf::Font poo;

public :
	const int dpadThreshold = 50;
	int sf_Joystick_index;

	GamePadState m_currentState;

	GamePadState m_previousState;

	void loadFont();
	Xbox360Controller();
	~Xbox360Controller();
	void Xbox360Controller::update(/*sf::Window &window*/);
	bool isConnected();
	bool connect();
	sf::Window m_window;
	sf::Text leftAnalog();
	sf::Text RightAnalog();
	sf::Text forA();
	sf::Text forB();
	sf::Text forX();
	sf::Text forY();
	sf::Text forLB();
	sf::Text forRB();
	sf::Text forLT();
	sf::Text forRT();
	sf::Text LeftThumbStickClick();
	sf::Text RightThumbStickClick();
	sf::Text DpadX();
	sf::Text DpadY();
	sf::Text forStart();
	sf::Text forBack();
	sf::Text Xbox();
	sf::Text RTrigger();
	sf::Text LTrigger();
	sf::Text z();
	

};


#endif 