#include "Arduino.h"
#include "Joystick.h"

Joystick::Joystick(int& initialX, int& initialY, int& initialB)
{
	pinMode(initialB, INPUT_PULLUP);
	setX(initialX);
	setY(initialY);
	setB(initialB);
}

void Joystick::setX(int value)
{
	int xValue = analogRead(value);

	if (0 <= xValue && xValue <= 510)                //backward
	{
		_xDirection = 2;
		_x = map(xValue, 0, 510, 255, 0);
	}
	else if (520 <= xValue && xValue <= 1025)        //forward
	{
		_xDirection = 1;
		_x = map(xValue, 520, 1023, 0, 255);
	}
	else                              //stop
	{
		_xDirection = 0;
		_x = 0;
	}
}

void Joystick::setY(int value)
{
	int yValue = analogRead(value);

	if (0 <= yValue && yValue <= 497)                //left
	{
		_yDirection = 4;
		_y = map(yValue, 0, 497, 255, 0);
	}
	else if (510 <= yValue && yValue <= 1025)        //right
	{
		_yDirection = 3;
		_y = map(yValue, 510, 1023, 0, 255);
	}
	else                              //stop
	{
		_yDirection = 0;
		_y = 0;
	}
}

void Joystick::setB(int value)
{
	_b = digitalRead(value);
}

int Joystick::getX()
{
	return _x;
}

int Joystick::getY()
{
	return _y;
}

int Joystick::getB()
{
	return _b;
}

int Joystick::getDirection()
{
	if (_xDirection == 0 && _yDirection == 0) { return 0; }      //stop
	else if (_xDirection == 1 && _yDirection == 0) { return 1; } //forward
	else if (_xDirection == 2 && _yDirection == 0) { return 2; } //backward
	else if (_xDirection == 0 && _yDirection == 3) { return 3; } //turn right
	else if (_xDirection == 0 && _yDirection == 4) { return 4; } //turn left
	else if (_xDirection == 1 && _yDirection == 3) { return 13; } //going right
	else if (_xDirection == 1 && _yDirection == 4) { return 14; } //goint left
	else if (_xDirection == 2 && _yDirection == 3) { return 23; } //back right
	else if (_xDirection == 2 && _yDirection == 4) { return 24; } //back left
	else { return 99; }  //error
}
