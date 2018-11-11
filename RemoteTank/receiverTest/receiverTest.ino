#include <RF24_config.h>
#include <printf.h>
#include <L298N.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(6, 10); // CE, CSN
const byte addresses[6] = "77777";


int ena = 5;  /* digital pwm  */
int in1 = 2;  /* digital      */
int in2 = 3;  /* digital      */
int in3 = 7;  /* digital      */
int in4 = 8;  /* digital      */
int enb = 9;  /* digital pwm  */

L298N driver(ena, in1, in2, in3, in4, enb);  /* L298N pin No. */

void setup() {

	Serial.begin(9600);
	radio.begin();
	radio.openReadingPipe(0, addresses);
	radio.setPALevel(RF24_PA_MIN);
	radio.startListening();

}

void loop() {

	radio.startListening();

	if (radio.available()) {

		int Direction = 0;
		int xSpeed = 0;
		int ySpeed = 0;
		int button = 0;

		radio.read(&Direction, sizeof(Direction));
		radio.read(&xSpeed, sizeof(xSpeed));
		radio.read(&ySpeed, sizeof(ySpeed));
		radio.read(&button, sizeof(button));
		
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
		
		driver.dualWheelOutput(Direction, xSpeed, ySpeed);
	}
}