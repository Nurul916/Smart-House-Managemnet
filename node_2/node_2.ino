#include <Wire.h>
#include <VirtualWire.h>
String x;
String str;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

const int buttonPin = 2; // the number of the pushbutton pin
const int buttonPin2 = 4;
const int buttonPin3 = 8;


int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;

 

void setup()
{
  
Wire.begin(9); // join i2c bus with address #8
Wire.onReceive(receiveEvent); // register event
Serial.begin(9600);

pinMode(buttonPin, INPUT);
pinMode(buttonPin2, INPUT);
pinMode(buttonPin3, INPUT);

  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_set_tx_pin(12);
}

void receiveEvent()
{
  while(0 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    str=str+c;
    //Serial.println(c);         // print the character
  }
  x=str;
}
void loop()
{
  Serial.println(x);
  delay(1000);
  str="";

  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  if (buttonState == HIGH) {
    // turn LED on:
  String msg="P1 push button is pressed";
  vw_send(msg.c_str(), msg.length());
  delay(500); //delay of 3 seconds
  }


  else if (buttonState2 == HIGH) {
    // turn LED on:
  String msg="hello world 2";
  vw_send(msg.c_str(), msg.length());
  delay(500); //delay of 3 seconds
 
  }

  else if (buttonState3 == HIGH) {
    // turn LED on:
  String msg="hello world 3";
  vw_send(msg.c_str(), msg.length());
  delay(500); //delay of 3 seconds
  
  
}

}
