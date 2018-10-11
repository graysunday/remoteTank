#include "Arduino.h"
#include "L298N.h"

L298N::L298N(int& initialEna, int& initialIn1, int& initialIn2, int& initialIn3, int& initialIn4, int& initialEnb)
{
	pinMode(initialEna, OUTPUT);
	pinMode(initialIn1, OUTPUT);
	pinMode(initialIn2, OUTPUT);
	pinMode(initialIn3, OUTPUT);
	pinMode(initialIn4, OUTPUT);
	pinMode(initialEnb, OUTPUT);
	_enaPin = initialEna;
	_in1Pin = initialIn1;
	_in2Pin = initialIn2;
	_in3Pin = initialIn3;
	_in4Pin = initialIn4;
	_enbPin = initialEnb;
}

void L298N::dualWheelOutput(int& initialDirection, int& initialXSpeed, int& initialYSpeed)
{
	switch (initialDirection) {
	case 0:                   //stop
		_enaValue = 0;
		_in1Value = 0;
		_in2Value = 0;
		_in3Value = 0;
		_in4Value = 0;
		_enbValue = 0;
		break;
	case 1:                   //forward
		_enaValue = initialXSpeed;
		_in1Value = 1;
		_in2Value = 0;
		_in3Value = 1;
		_in4Value = 0;
		_enbValue = initialXSpeed;
		break;
	case 2:                   //backward
		_enaValue = initialXSpeed;
		_in1Value = 0;
		_in2Value = 1;
		_in3Value = 0;
		_in4Value = 1;
		_enbValue = initialXSpeed;
		break;
	case 3:                   //right
		_enaValue = initialYSpeed;
		_in1Value = 1;
		_in2Value = 0;
		_in3Value = 0;
		_in4Value = 1;
		_enbValue = initialYSpeed;
		break;
	case 4:                   //left
		_enaValue = initialYSpeed;
		_in1Value = 0;
		_in2Value = 1;
		_in3Value = 1;
		_in4Value = 0;
		_enbValue = initialYSpeed;
		break;
	case 13:                   //going right

		if (initialXSpeed == initialYSpeed)
		{
			initialYSpeed = initialYSpeed / 2;
		}
		else if (initialXSpeed > initialYSpeed)
		{
			initialYSpeed = (initialXSpeed - initialYSpeed / 2);
		}
		else if (initialXSpeed < initialYSpeed)
		{
			int rev = initialXSpeed;
			initialXSpeed = initialYSpeed;
			initialYSpeed = rev / 2;
		}

		_enaValue = initialXSpeed;
		_in1Value = 1;
		_in2Value = 0;
		_in3Value = 1;
		_in4Value = 0;
		_enbValue = initialYSpeed;
		break;
	case 14:                   //goint left

		if (initialXSpeed == initialYSpeed)
		{
			initialYSpeed = initialYSpeed / 2;
		}
		else if (initialXSpeed > initialYSpeed)
		{
			initialYSpeed = (initialXSpeed - initialYSpeed / 2);
		}
		else if (initialXSpeed < initialYSpeed)
		{
			int rev = initialXSpeed;
			initialXSpeed = initialYSpeed;
			initialYSpeed = rev / 2;
		}

		_enaValue = initialYSpeed;
		_in1Value = 1;
		_in2Value = 0;
		_in3Value = 1;
		_in4Value = 0;
		_enbValue = initialXSpeed;
		break;
	case 23:                   //back right

		if (initialXSpeed == initialYSpeed)
		{
			initialYSpeed = initialYSpeed / 2;
		}
		else if (initialXSpeed > initialYSpeed)
		{
			initialYSpeed = (initialXSpeed - initialYSpeed / 2);
		}
		else if (initialXSpeed < initialYSpeed)
		{
			int rev = initialXSpeed;
			initialXSpeed = initialYSpeed;
			initialYSpeed = rev / 2;
		}

		_enaValue = initialXSpeed;
		_in1Value = 0;
		_in2Value = 1;
		_in3Value = 0;
		_in4Value = 1;
		_enbValue = initialYSpeed;
		break;
	case 24:                   //back left

		if (initialXSpeed == initialYSpeed)
		{
			initialYSpeed = initialYSpeed / 2;
		}
		else if (initialXSpeed > initialYSpeed)
		{
			initialYSpeed = (initialXSpeed - initialYSpeed / 2);
		}
		else if (initialXSpeed < initialYSpeed)
		{
			int rev = initialXSpeed;
			initialXSpeed = initialYSpeed;
			initialYSpeed = rev / 2;
		}

		_enaValue = initialYSpeed;
		_in1Value = 0;
		_in2Value = 1;
		_in3Value = 0;
		_in4Value = 1;
		_enbValue = initialXSpeed;
		break;

	}
	analogWrite(_enaPin, _enaValue);
	digitalWrite(_in1Pin, _in1Value);
	digitalWrite(_in2Pin, _in2Value);
	digitalWrite(_in3Pin, _in3Value);
	digitalWrite(_in4Pin, _in4Value);
	analogWrite(_enbPin, _enbValue);

	Serial.print("  ");
	Serial.print(" ena Value= ");
	Serial.print(_enaValue);
	Serial.print(" In1 value = ");
	Serial.print(_in1Value);
	Serial.print(" In2 value = ");
	Serial.print(_in2Value);
	Serial.print(" In3 value = ");
	Serial.print(_in3Value);
	Serial.print(" In4 value = ");
	Serial.print(_in4Value);
	Serial.print(" enb value = ");
	Serial.print(_enbValue);
	Serial.println("  ");
}
