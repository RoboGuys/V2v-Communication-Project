/**Example:: Demonstrates use of Motors.h Library
***Programmer:: OJ
*********Developed for Arduino********************/

#include <Motors.h>


//Initializing a double motor called myMotors
Motors2  myMotors(3,5,9,11);

void setup()
{
	Serial.begin(9600); //Opens serial communication with monitor

	//prints Info
		Serial.println("Starting Motor Test");
		for(int i=0;i<20;i++)
		{
			Serial.print("*");
		}
	Serial.println();
	
	delay(700);

	Serial.println("Test for 2  Motors");
	delay(100);
}

void loop()
{
	Serial.println("Running Both Motors Forward at 200 for 5 seconds");
	delay(250);
	myMotors.runMtr(200,200);
	delay(5000);

	Serial.println("Running Both Motors Backward at 200 for 5 seconds");
	delay(250);
	myMotors.runMtr(-200,-200);
	delay(5000);

	Serial.println("Running Left Motor Forward and Right Motor Backward at 180 for 5 seconds");
	delay(250);
	myMotors.runMtr(180,-180);
	delay(5000);

	Serial.println("Running Left Motor at 255 for 3 seconds");
	delay(250);
	myMotors.runMtrLeft(255);
	delay(3000);

	Serial.println("Running Right Motor at 255 for 3 seconds");
	delay(250);
	myMotors.runMtrRight(255);
	delay(3000);
}

