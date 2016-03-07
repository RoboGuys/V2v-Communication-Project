//Motor Codes


#include "Arduino.h"
#include "Motors.h"
#define DEBUG



//Deifnes motor pins used & Initializes class
//1pin and 2pin for left motor pins
//3pin and 4pin for right motor pins
Motors2::Motors2(unsigned int pinLa, unsigned int pinLb, unsigned int pinRa, unsigned int pinRb)
{
	pinMode(pinLa, OUTPUT);
	pinMode(pinLb, OUTPUT);
	pinMode(pinRa,OUTPUT);
	pinMode(pinRb, OUTPUT);

	leftMtrA= (uint8_t) pinLa;
	leftMtrB= (uint8_t) pinLb;
	rightMtrA= (uint8_t) pinRa;
	rightMtrB= (uint8_t) pinRb;

}

//Object destructor
Motors2::~Motors2(){}

//Runs Motor at specified speed
		//Of form runMtr(20,-20):Runs Left motor at speed 20 in forward direction
		//						 Runs Right motor at speed 20 in reverse direction

void Motors2::runMtr(short int leftSpeed, short int rightSpeed)
{

	//Run Left Motor at specified speed
	if (leftSpeed>0) //Foward Speed(>0)
	{

			if(leftSpeed>255) //Speed control::Max speed is 255
			{
				leftSpeed=255;

			}

		analogWrite(leftMtrA, leftSpeed);
		analogWrite(leftMtrB, 0);
	}
	else if(leftSpeed<0) //Reverse Speed (<0)
	{
		if(leftSpeed<-255)
			{
				leftSpeed=-255;

			}
		analogWrite(leftMtrA, 0);
		analogWrite(leftMtrB, -leftSpeed);
	}
	else
	{
		analogWrite(leftMtrA, 0); //Stops Motor if speed specified = 0
		analogWrite(leftMtrB, 0);
	}

	//Run Right Motor at specified
	if (rightSpeed>0) //Motor forward if speed>0
	{
		if(rightSpeed>255)
			{
				rightSpeed=255;

			}
		analogWrite(rightMtrA, rightSpeed);
		analogWrite(rightMtrB, 0);
	}
	else if(rightSpeed<0) //Motor reverse if speed<0
	{
		if(rightSpeed<-255)
			{
				rightSpeed=-255;

			}
		analogWrite(rightMtrA, 0);
		analogWrite(rightMtrB, -rightSpeed);
	}
	else
	{
		analogWrite(rightMtrA, 0);
		analogWrite(rightMtrB, 0);
	}
}

//Runs Only Left Motor at Specified Speed
	//
void Motors2::runMtrLeft (short int leftSpeed)
{
	//Run Left Motor
	if (leftSpeed>0)
	{

			if(leftSpeed>255)
			{
				leftSpeed=255;

			}

		analogWrite(leftMtrA, leftSpeed);
		analogWrite(leftMtrB, 0);
	}
	else if(leftSpeed<0)
	{
		if(leftSpeed<-255)
			{
				leftSpeed=-255;

			}
		analogWrite(leftMtrA, 0);
		analogWrite(leftMtrB, -leftSpeed);
	}
	else
	{
		analogWrite(leftMtrA, 0);
		analogWrite(leftMtrB, 0);
	}

}

//Runs only right motor at specified speed
void Motors2::runMtrRight(short int rightSpeed)
{
	//Run Right Motor
	if (rightSpeed>0)
	{
		if(rightSpeed>255)
			{
				rightSpeed=255;
			}
		analogWrite(rightMtrA, rightSpeed);
		analogWrite(rightMtrB, 0);
	}
	else if(rightSpeed<0)
	{
		if(rightSpeed<-255)
			{
				rightSpeed=-255;

			}
		analogWrite(rightMtrA, 0);
		analogWrite(rightMtrB, -rightSpeed);
	}
	else
	{
		analogWrite(rightMtrA, 0);
		analogWrite(rightMtrB, 0);
	}
}
/*
//Stops both motors for specified time
void Motors::stop()
{
	runMtr(0,0);
}


//If in debug mode, function prints current motor speed
/*#ifdef DEBUG
	int Motors::showSpeed()
	{

	}
#endif


//Revovlves robot at speed specified in direction specified for time specified
void revolve(short int speed, char direction, short int time)
{
	if (direction=='L')
	{
		runMtr(speed, -speed);
		delay(time);
	}

	else if(direction=='R')
	{
		runMtr(-speed,speed);
		delay(time);
	}
}*/
/*********************************************************************************************************************
**********************************************************************************************************************
**********************************************************************************************************************
**********************************************  FOR MOTOR1 **********************************************************/


//Initializing a single motor and its pins
Motors1::Motors1(unsigned int pin1, unsigned int pin2)
{

	pinA = pin1;
	pinB = pin2;

	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
}

//Deleting object
Motors1::~Motors1(){}

//For running Motor at a speed

void Motors1::runMtr(short int speed)
{
	if (speed>0) //Motor forward if speed>0
	{
		if(speed>255)
			{
				speed=255;
			}
		analogWrite(pinA, speed);
		analogWrite(pinB, 0);
	}
	else if(speed<0) //Motor reverse if speed<0
	{
		if(speed<-255)
			{
				speed=-255;
			}
		analogWrite(pinA, 0);
		analogWrite(pinB, -speed);
	}
	else
	{
		analogWrite(pinA, 0);
		analogWrite(pinB, 0);
	}
}

//End of Code