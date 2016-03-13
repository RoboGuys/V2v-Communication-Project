//Action-to-take functions
void forward()
  {  //run motors forward at specified speed
              //left motor, right motor
        motors.runMtr(speedd,speedd);
  }

void backward()
  {  
  //run motors backward at speed
    motors.runMtr(-speedd,-speedd);
  }

void leftt()
  {
    // run only left motor at speed
      motors.runMtrLeft(speedd);
  }
  
void rightt()
  {
    //run only right motor at speed
      motors.runMtrRight(speedd);
  }
  
void stopp()
  {
    //stop motors
     motors.runMtr(0,0);
  }

//Speed changers
void speedUp()
   {
      speedd+=10;    
      //speed shouldnt be more than 255
      if (speedd>255)
        speedd=255;
  }
  
void speedDown()
  {
    speedd-=10;  
    //speed shouldn't be below 100
    if(speedd<100)
      speedd=100;
  }
