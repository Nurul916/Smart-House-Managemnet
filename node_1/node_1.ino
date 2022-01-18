// 255/((500-200)+1) = 0.85 //color density 
// here I use far distance as 500 cm and close distance as 200 cm
//RGB color initialization
#include<Wire.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(); // join i2c bus with address #8
  dht.begin();
  
  
  pinMode(6, OUTPUT); // Trigger pin of Ultrasonic Sensor at PIn No. 6 and set as OUTPUT
  pinMode(5, INPUT); // echo pin of Ultrasonic Sensor at PIn No. 5 and set as INPUT

}

void loop() {
  // put your main code here, to run repeatedly:
  //clears the trigger pin
  digitalWrite(6, LOW);
  delayMicroseconds(2);
  
  digitalWrite(6, HIGH); // Sets Trigger pin High for 20 miliseconds
  delayMicroseconds(20);
  digitalWrite(6, LOW); // Sets Trigger pin Low for 20 miliseconds
  int duration = pulseIn(5, HIGH); // Echo pin 05, returns sound wave travel time in microseconds
  int distance= (duration*0.034)/2;// Calculating the distance of object , here I use sound travel time is 340 m/s or 0.034 cm/microseconds
  
  delay(500);
  Serial.print("Distance from the object = ");
  Serial.print(distance); // show distance in cm on the terminal
  Serial.println(" cm");
  Wire.beginTransmission(8); 
  
  Wire.write(distance);
  Wire.endTransmission();
  
  delay(500);

    

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  String humi=String(h,DEC);
  Wire.beginTransmission(9); 
  
  Wire.write(humi.c_str());
  Wire.endTransmission();
  

  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);

  delay(500);
  
  
}
