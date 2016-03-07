//Header Files for Motor Base
//Functions controlling Motors



#ifndef Motors_h

	#define Motors_h
	#include "stdint.h"

	//For running 2 motors simultaneously
	class Motors2
	{
	public:
		//Creates instance of class and takes pins
			Motors2(unsigned int pinLa, unsigned int pinLb, unsigned int pinRa, unsigned int pinRb);
			~Motors2();
		//Runs Motor at specified speed
		//Of form runMtr(20,-20):Runs Left motor at speed 20 in forward direction
		//						 Runs Right motor at speed 20 in reverse direction
			 void runMtr(short int leftSpeed, short int rightSpeed);
			void runMtrLeft(short int leftSpeed);
			void runMtrRight(short int rightSpeed);
			//void stop(short int time)::runMtr();
			//void stop();
			//void revolve(short int speed, char direction, short int time);
			//int showSpeed();

		#ifdef DEBUG
			int showSpeed();
		#endif

	private:

		//Motor Pins
			uint8_t leftMtrA, leftMtrB;
			uint8_t rightMtrA, rightMtrB;

	};

	//For running a single motor
	class Motors1 
	{
	public:
		
		//Initialize & delete a motor 
			Motors1(unsigned int pin1, unsigned int pin2);
			~Motors1();

		//rum motor at specified speed

			void runMtr(short int speed);

	private:

		//Pins
		uint8_t pinA, pinB;

	};

#endif

//End of Header Files

