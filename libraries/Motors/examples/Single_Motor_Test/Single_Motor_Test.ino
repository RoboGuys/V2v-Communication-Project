/**Example:: Demonstrates use of Motors.h Library
***Programmer:: OJ
*********Developed for Arduino********************/

#include <Motors.h>


//Initializing a motor called myMotor
Motors1  myMotor((uint8_t)3,(uint8_t)5);

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

	Serial.println("Test for a Motor\n!!MAX SPEED IS 255!!");
	delay(100);
}

void loop()
{
	uint8_t i;
	Serial.println("Running Motor Forward at 255 for 3 seconds");
	delay(250);
	myMotor.runMtr(255);
	delay(5000); 

	Serial.println("Running Motor Backward at 255 for 3 seconds");
	delay(250);
	myMotor.runMtr(-255);
	delay(5000);

	Serial.println("Running Motor at increasing speeds for 5 seconds");
	for(i=0;i<=255;i++)
	{
		Serial.print("Speed:: ");
		Serial.print(i);
		Serial.println();
		myMotor.runMtr(i);
		delay(20);
	}

	Serial.println("Running Motor at decreasing speeds for 5 seconds");
	for(i=255;i!=0;i--)
	{
		Serial.print("Speed:: ");
		Serial.print(i);
		Serial.println();
		myMotor.runMtr(i);
		delay(20);
	}
}

