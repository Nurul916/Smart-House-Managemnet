#include <Wire.h>
int x;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
Wire.begin(8); // join i2c bus with address #8
Wire.onReceive(receiveEvent); // register event
Serial.begin(9600);
}

void receiveEvent(int bytes)
{
  x = Wire.read();
}
void loop()
{
  Serial.println(x);
  if(x<=100){
    setColor(255, 0, 0); 
    delay(500);
    
  }
  else{
    setColor(0, 255, 0);  // green
    delay(500);
  }
  delay(1000);
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
