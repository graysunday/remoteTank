#include <RF24_config.h>
#include <printf.h>
#include <Joystick.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte addresses[6] = "77777";


void setup() {

	Serial.begin(9600);
	radio.begin();
	radio.openWritingPipe(addresses);
	radio.setPALevel(RF24_PA_MIN);
	radio.stopListening();
}

void loop() {

	int xPin = 1; /* analog */
	int yPin = 0; /* analog */
	int bPin = 3; /* digital */

	Joystick joystick(xPin, yPin, bPin); /* joystick pin No. */

	int Direction = joystick.getDirection();  /* 0: stop, 1:forward, 2:backward, 3:right, 4:left, 13, 14, 23, 24 */
	int xSpeed = joystick.getX();
	int ySpeed = joystick.getY();
	int button = joystick.getB();

	Serial.print("  ");
	Serial.print(" Direction= ");
	Serial.print(Direction);
	Serial.print(" xSpeed = ");
	Serial.print(xSpeed);
	Serial.print(" ySpeed = ");
	Serial.print(ySpeed);
	Serial.print(" button = ");
	Serial.print(button);
	Serial.println("  ");

	radio.write(&Direction, sizeof(Direction));
	radio.write(&xSpeed, sizeof(xSpeed));
	radio.write(&ySpeed, sizeof(ySpeed));
	radio.write(&button, sizeof(button));

	delay(10);

}