#include <SoftwareSerial.h>

#include <Motors.h>


 //Creating a structure to allow us to
 //create objects (USonic sensor, example FWsensor) with all necessary data types
 //data acessed like FWsensor.distance
struct Ping 
{            
   uint8_t trig;
   uint8_t echo;
  
  long duration;
  int distance; //distance is in cm
};

struct Ping pingFW;

int speedd=240; //speed at which motors run

//time since last command has been received, time since begining of code
long timerNewState=0,timerBegin,timeToPrint=0;  //timer variables

char state; //Takes commands

Motors2 motors(5,6,10,11);
//struct Ping pingFW;

void setup()

{
  // put your setup code here, to run once:
  Serial.begin(57600);  //Fast bluetooth baud rate
  initPing(pingFW,8,9);
}

void loop()
{
  // put your main code here, to run repeatedly:

  timerBegin=millis(); //time since begining of code

  if(Serial.available()>0)  //If command is comming in:
  {
    timerNewState =millis();
    state=Serial.read();    //store command in state variable
    Serial.print("Received Command::");
    Serial.println(state);

    switch(state) //chooses action to run depending on command
    {
    case 'f':
      forward();
      //Serial.println("forward");
      break;
    case 'b':
      backward();
      //   Serial.println("backward");
      break;
    case 'l':
      leftt();
      //Serial.println("left");
      break;
    case'r':
      rightt();
      //Serial.println("right");
      break;
    case 's':
      stopp();
      // Serial.println("stop");
      break;
    case 'u':
      speedUp();
      Serial.print("speed::");
      Serial.println(speedd);
      break;
    case 'd':
      speedDown();
      Serial.println("speed::");
      Serial.println(speedd);
      break;
    default :
      break;
    }
  }
  
 else {

        if(timerBegin-timerNewState>300)
        {
            stopp();
        }
    }
    
    //****************PING**************************
    
    getDist(pingFW);
    
    
    
    if((pingFW.distance!=0) && (timerBegin>timeToPrint) )
    {
      timeToPrint=timerBegin+1000; //creating delay using timers
      Serial.print("\nDistance to nearest obstacle is:: ");
      Serial.print(pingFW.distance);
      Serial.println("cm");
      
    }
    
    else if ( (pingFW.distance==0) && (timerBegin>timeToPrint))
      {  
        timeToPrint=timerBegin+1000; //creating delay using timers
        Serial.println("\nNo obstacle within range of 2m");
      
       }
}



