#include <Arduino.h>
#include <Adafruit_Sensor.h>

//TODO: setup code to display current lightlevel on LCD, ensure no memory leaks, 
//how to use to toggle switch?


const int out = 8; //output pin
const int sensorPin = A0; // analog pin
int sensorValue = 0; // current value of sensor
const int threshold = 500; // threshold


//function declarations
void compareLight_threshold(int sp); //takes sensor pin and compares to global thresh

void setup() {
  pinMode(out, OUTPUT); //out stores output
  Serial.begin(9600);
}

void loop() {
  compareLight_threshold(sensorPin);
  Serial.println(sensorValue);
  delay(1000);
}


//fun defs
void compareLight_threshold(int sp) {
  sensorValue = analogRead(sp);
  if (sensorValue < threshold) {
    digitalWrite(out, HIGH);
  }
  else {
    digitalWrite(out, LOW);
  }
}