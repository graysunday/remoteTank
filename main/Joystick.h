#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "Arduino.h"
#include "Joystick.h"

class Joystick
{
private:
	int _x = 0;
	int _y = 0;
	int _b = 0;
	int _xDirection = 0;
	int _yDirection = 0;

public:
	Joystick(int& xAxle, int& yAxle, int& bButton);

	void setX(int value);
	void setY(int value);
	void setB(int value);

	int getX();
	int getY();
	int getB();
	int getDirection();
};

#endif