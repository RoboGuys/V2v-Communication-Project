


/*void setup() {
  
  // initialize serial communication:
    Serial.begin(9600);
   
   initPing(pingFW,8,9); //initializes pins of US sensor 
}

void loop()
{

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
 
      digitalWrite(pingFW.trig, LOW);
      delayMicroseconds(2);
      digitalWrite(pingFW.trig, HIGH);
      delayMicroseconds(5);
      digitalWrite(pingFW.trig, LOW);
  //time it takes to detect obstacle (max range is 200cm)
      pingFW.duration = pulseIn(pingFW.echo, HIGH, 9500); //time out is 9500 microseconds to set max range to 200cm

  // convert the time into a distance
      pingFW.distance =(int) microsecondsToCentimeters(pingFW.duration);
  
  Serial.print(pingFW.duration);
  Serial.println(" microseconds\t"); //print time taken to detect obstacle

  Serial.print(pingFW.distance); //distance to obstacle (0 if none detected within range
  Serial.println("cm");
  
}*/

//Initializes the pin of the UltraSonic sensor
void initPing(struct Ping &sensor, uint8_t trigPin, uint8_t echoPin)
{
 sensor.trig = trigPin;
 sensor.echo = echoPin;

  pinMode(sensor.trig, OUTPUT);
  pinMode(sensor.echo, INPUT); 
}

int getDist(struct Ping &sensor)
{
       digitalWrite(sensor.trig, LOW);
      delayMicroseconds(2);
      digitalWrite(sensor.trig, HIGH);
      delayMicroseconds(5);
      digitalWrite(sensor.trig, LOW);
  //time it takes to detect obstacle (max range is 200cm)
      sensor.duration = pulseIn(sensor.echo, HIGH, 9500); //time out is 9500 microseconds to set max range to 200cm

  // convert the time into a distance
      sensor.distance =(int) (sensor.duration/29/2);
      
      return sensor.distance;
}


