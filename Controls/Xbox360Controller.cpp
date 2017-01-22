#include "Xbox360Controller.h"
#include "Game.h"




//David O Gorman
//Xbox 360 controlller programme. Reads inputs
//this project took me.. longer than anticipated..
//Due to SFML issues 


 Xbox360Controller::Xbox360Controller ()
{


}


 Xbox360Controller::~Xbox360Controller()
 {
 
 }

 void Xbox360Controller::loadFont()
 {
 
	 if (!poo.loadFromFile("C:/Windows/Fonts/arial.ttf"))
	 {
	 
		 cout << ("not found") << endl;
	 }
 
 }


 //The update. Updates the Joysick functions and also the state of the Triggers and joysticks
 void Xbox360Controller::update()
 {
 
	 sf::Joystick::update();


	 m_currentState.LTrigger = float(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z));
	 m_currentState.RTrigger = float(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V));

	 m_currentState.RightThumbStick = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U), sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R));
	 m_currentState.LeftThumbStick = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y));



	 ///This is for A
	 if (sf::Joystick::isButtonPressed(0, 0))
	 {

		 m_currentState.A = true;
		 std::cout << "BOOM" << std::endl;

	 }
	 else
	 {
		 textforA.setString("");
		 m_currentState.A = false;
	 }
	 
	 ///THis is for B 
	 if (sf::Joystick::isButtonPressed(0,1))
	 {
		 m_currentState.B = true;
		 std::cout << "C" << std::endl;

	 }
	 else
	 {
		 textforB.setString("");
		 m_currentState.B = false;
		

	 }
	 ///THis is for X
	 if (sf::Joystick::isButtonPressed(0, 2))
	 {
		 m_currentState.X = true;
		 std::cout << "A" << std::endl;

	 }
	 else
	 {
		 textforX.setString("");
		 m_currentState.X = false;

	 }

	 ///THis is for Y 
	 if (sf::Joystick::isButtonPressed(0, 3))
	 {
		 m_currentState.Y = true;
		 std::cout << "B" << std::endl;

	 }
	 else
	 {
		 textforY.setString("");
		 m_currentState.Y = false;

	 }
	 //THIS IS FOR THE LEFT BUMPER 
	 if (sf::Joystick::isButtonPressed(0, 4))
	 {
		 m_currentState.LB = true;

	 }
	 else
	 {
		 textforLB.setString("");
		 m_currentState.LB = false;

	 }
	 
	 //THIS IS FOR THE RIGHT BUMPER
	 if (sf::Joystick::isButtonPressed(0, 5))
	 {
		 m_currentState.RB = true;

	 }
	 else
	 {
		 textforRB.setString("");
		 m_currentState.RB = false;

	 }
	 //THIS IS FOR THE LEFT THUMB STICK
	 if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) < (dpadThreshold * -1))
	 {
		 m_currentState.DpadL = true;
		 std::cout << "Left" << std::endl;
	 }
	 else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > dpadThreshold)
	 {
		 m_currentState.DpadR = true;
		 std::cout << "Right" << std::endl;
	 }
	 else
	 {
		 m_currentState.DpadL = false;
		 m_currentState.DpadR = false;
	 }
	 if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) < (dpadThreshold * -1))
	 {
		 m_currentState.DpadU = true;
	 }
	 else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) > dpadThreshold)
	 {
		 m_currentState.DpadD = true;
	 }
	 else
	 {
		 m_currentState.DpadU = false;
		 m_currentState.DpadD = false;
	 }
	
	 //THIS IS FOR THE START BUTTON*****************************
	 if (sf::Joystick::isButtonPressed(0 ,7))
	 {
		 m_currentState.Start = true;
	

	 }
	 else
	 {
		 textforStart.setString("");
		 m_currentState.Start = false;

	 }
	 //THIS IS FOR THE BACK BUTTON ******************************
	 //This also closes the programme
	 if (sf::Joystick::isButtonPressed(0, 6))
	 {
		 m_currentState.Back = true;
		 //window.close();
		 
	 }
	 else
	 {
		 textforBack.setString("");
		 m_currentState.Back = false;

	 }
	 /// <summary>
	 /// //////////////////////////////////////////////////////
	 /// </summary>

	 if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) < -5)
	 {
		 m_currentState.RTrigger = -(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z));
	 }
	 else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) > 5)
	 {
		 m_currentState.LTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
	 }
	 else
	 {
		 m_currentState.LTrigger = 0;
		 m_currentState.RTrigger = 0;
	 }


 }



 sf::Text Xbox360Controller::forA()
 {

	 if (m_currentState.A == true)
	 {
		 textforA.setString("pressed");

		 textforA.setColor(sf::Color::Black);
		 textforA.setPosition(750, 410);
		 textforA.setFont(poo);
	 }
	 return textforA;


 }



 sf::Text Xbox360Controller::forB()
 {
	 if (m_currentState.B == true)
	 {
		 textforB.setString("pressed");

		 textforB.setColor(sf::Color::Black);
		 textforB.setPosition(755, 346);
		 textforB.setFont(poo);
	 }
	 return textforB;



 }

 sf::Text Xbox360Controller::forX()
 {

	 if (m_currentState.X == true)
	 {
		 textforX.setString("pressed");

		 textforX.setColor(sf::Color::Black);
		 textforX.setPosition(750, 300);
		 textforX.setFont(poo);
	 }
	 return textforX;
 
 }


 sf::Text Xbox360Controller::forY()
 {

	 if (m_currentState.Y == true)
	 {
		 textforY.setString("pressed");

		 textforY.setColor(sf::Color::Black);
		 textforY.setPosition(750, 220);
		 textforY.setFont(poo);
	 }
	 return textforY;


 }
 ///This is the left bumper   draw 
 sf::Text Xbox360Controller::forLB()
 {

	 if (m_currentState.LB == true)
	 {
		 textforLB.setString("pressed");

		 textforLB.setColor(sf::Color::Black);
		 textforLB.setPosition(80, 110);
		 textforLB.setFont(poo);
	 }
	 return textforLB;


 }
 ///This is the right bumper   draw 
 sf::Text Xbox360Controller::forRB()
 {

	 if (m_currentState.RB == true)
	 {
		 textforRB.setString("pressed");
				
		 textforRB.setColor(sf::Color::Black);
		 textforRB.setPosition(750, 110);
		 textforRB.setFont(poo);
	 }			
	 return textforRB;


 }

 ///This is the left trigger  draw 
 sf::Text Xbox360Controller::LeftThumbStickClick()
 {

	 if (m_currentState.LeftThumbStickClick == true)
	 {
		 textforLeftThumbStickClick.setString("pressed");

		 textforLeftThumbStickClick.setColor(sf::Color::Black);
		 textforLeftThumbStickClick.setPosition(177, 552);
		 textforLeftThumbStickClick.setFont(poo);
	 }
	 return textforRB;


 }

 ///This is the left trigger  draw 
 sf::Text Xbox360Controller::LTrigger()
 {
	 textforLTrigger.setColor(sf::Color::Black);
	 textforLTrigger.setPosition(200, 30);
	 textforLTrigger.setCharacterSize(20);
	 textforLTrigger.setFont(poo);
	 textforLTrigger.setString(std::to_string(m_currentState.LTrigger));
	 return textforLTrigger;
 }


 //THis is the right trigger 
 sf::Text Xbox360Controller::RTrigger()
 {
	 textforRTrigger.setColor(sf::Color::Black);
	 textforRTrigger.setPosition(575, 30);
	 textforRTrigger.setCharacterSize(20);
	 textforRTrigger.setFont(poo);
	 textforRTrigger.setString(std::to_string(m_currentState.RTrigger));
	 return textforRTrigger;
 }


 // this i the  left Analog stick 
sf::Text Xbox360Controller::leftAnalog()
 {
	textforLeftAnalogStick.setColor(sf::Color::Black);
	textforLeftAnalogStick.setPosition(20, 265);
	textforLeftAnalogStick.setCharacterSize(20);
	textforLeftAnalogStick.setFont(poo);
	 textforLeftAnalogStick.setString(std::to_string(m_currentState.LeftThumbStick.x) + "\n" + (std::to_string(m_currentState.LeftThumbStick.y)));
	 return textforLeftAnalogStick;
}


// this i the	Right  Analog stick 
sf::Text Xbox360Controller::RightAnalog()
{
	textforRightAnalogStick.setColor(sf::Color::Black);
	textforRightAnalogStick.setPosition(520, 520);
	textforLeftAnalogStick.setCharacterSize(20);
	textforRightAnalogStick.setFont(poo);
	textforRightAnalogStick.setString(std::to_string(m_currentState.RightThumbStick.x) + "\n" + (std::to_string(m_currentState.RightThumbStick.y)));
	return textforRightAnalogStick;
}




 sf::Text Xbox360Controller::forStart()
 {

	 if (m_currentState.Start == true)
	 {
		 textforStart.setString("pressed");

		 textforStart.setColor(sf::Color::Black);
		 textforStart.setPosition(727, 517);
		 textforStart.setFont(poo);
		
	 }
	 return textforStart;

	
 }




 sf::Text Xbox360Controller::forBack()
 {

	 if (m_currentState.Back == true)
	 {
		 textforBack.setString("pressed");

		 textforBack.setColor(sf::Color::Black);
		 textforBack.setPosition(72, 442);
		 textforBack.setFont(poo);
		 m_window.close();
	 }
	 return textforBack;


 }
 /// <summary>
 /// ////////////////////
 /// </summary>
 /// <returns></returns>
 sf::Text Xbox360Controller::DpadX()
 {
	 textforDpadX.setColor(sf::Color::Black);
	 textforDpadX.setPosition(250, 505);
	 textforDpadX.setFont(poo);
	 textforDpadX.setCharacterSize(16);
	 if (m_currentState.DpadL)
	 {
		 textforDpadX.setString("Left");
	 }
	 else if (m_currentState.DpadR)
	 {
		 textforDpadX.setString("Right");
	 }
	 else
	 {
		 textforDpadX.setString("D-Pad X");
	 }
	 return textforDpadX;
 }

 sf::Text Xbox360Controller::DpadY()
 {
	 textforDpadY.setColor(sf::Color::Black);
	 textforDpadY.setPosition(250, 530);
	 textforDpadY.setFont(poo);
	 textforDpadY.setCharacterSize(16);
	 if (m_currentState.DpadD)
	 {
		 textforDpadY.setString("Down");
	 }
	 else if (m_currentState.DpadU)
	 {
		 textforDpadY.setString("Up");
	 }
	 else
	 {
		 textforDpadY.setString("D-Pad Y");
	 }
	 return textforDpadY;

 }




