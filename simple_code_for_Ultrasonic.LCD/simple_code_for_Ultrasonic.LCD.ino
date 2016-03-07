#include <LiquidCrystal.h>
 //Importing libraries
#include <NewPing.h>

LiquidCrystal lcd(12,11,5,4,3,2); //Creating object

#define ECHO_PIN 7//Defining pins
#define TRIG_PIN 9
#define MAX_DIST 100

int contrast = 50; //Defining contrast

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DIST); //Defining newping object (The HC-SR04)
 
void setup() { //Setup
  lcd.begin(16,2); //Change this to the size of your LCD, my happens to be 16x2
  lcd.clear(); //Clear screen
  pinMode(2, OUTPUT); //Setting contrast pin 2 to an output
  analogWrite(2, contrast); //Setting contrast
}

void loop() {
  unsigned int uS1 = sonar.ping_in(); //Ping in inches
  unsigned int uS2 = sonar.ping_cm(); // Ping in cm
  lcd.clear(); //Clearing screen
  lcd.setCursor(2,0); //Setting cursor
  lcd.print("Ping: "); //Printing text
  lcd.print(uS2);
  lcd.print(" cm");
  lcd.setCursor(2,1);
  lcd.print("Ping: ");
  lcd.print(uS1);
  lcd.print(" in");
  lcd.setCursor(1,0);
  delay(1000); //Change this to the update time you want, I just used 1000 ms
  
}
