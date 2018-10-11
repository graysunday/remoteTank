#pragma once#ifndef L298N_H
#define L298N_H

#include "Arduino.h"
#include "L298N.h"

class L298N
{
public:

	L298N(int& ena, int& in1, int& in2, int& in3, int& in4, int& enb);

	void dualWheelOutput(int& Direction, int& xSpeed, int& ySpeed);

private:
	int _enaPin = 0;
	int _in1Pin = 0;
	int _in2Pin = 0;
	int _in3Pin = 0;
	int _in4Pin = 0;
	int _enbPin = 0;

	int _enaValue = 0;
	int _in1Value = 0;
	int _in2Value = 0;
	int _in3Value = 0;
	int _in4Value = 0;
	int _enbValue = 0;

};

#endif