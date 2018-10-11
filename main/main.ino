/*
 Name:		main.ino
 Created:	2018-10-11 오후 8:23:30
 Author:	이원호
*/

#include <L298N.h>
#include <Joystick.h>

void setup() {
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	int xPin = 1; /* analog */
	int yPin = 0; /* analog */
	int bPin = 3; /* digital */

	Joystick joystick(xPin, yPin, bPin); /* joystick pin No. */

	int ena = 5;  /* digital pwm  */
	int in1 = 2;  /* digital      */
	int in2 = 4;  /* digital      */
	int in3 = 7;  /* digital      */
	int in4 = 8;  /* digital      */
	int enb = 9;  /* digital pwm  */

	L298N driver(ena, in1, in2, in3, in4, enb);  /* L298N pin No. */

	int Direction = joystick.getDirection();  /* 0: stop, 1:forward, 2:backward, 3:right, 4:left, 13, 14, 23, 24 */
	int xSpeed = joystick.getX();
	int ySpeed = joystick.getY();

	driver.dualWheelOutput(Direction, xSpeed, ySpeed);

	delay(300);
}
