#include <SoftwareSerial.h> // TX RX software library for bluetooth
//declare variables for pins
int m1a = 9;
int m1b = 10;
int m2a = 11;
int m2b = 12;
int m3a = 6;
int m3b = 7;
//int ena = 13;
String val;
int bluetoothTx = 0; // bluetooth tx to 0 pin
int bluetoothRx = 1; // bluetooth rx to 1 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);


void setup() {
  // put your setup code here, to run once:
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(m3a, OUTPUT);
  pinMode(m3b, OUTPUT);
//  pinMode(ena, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    val = Serial.readString();
    Serial.println(val);
  }
  if(val == "F")//forward
  {
    digitalWrite(m1a,HIGH);
    digitalWrite(m1b,LOW);
    
    digitalWrite(m2a,HIGH);
    digitalWrite(m2b,LOW);
    analogWrite(m2a,50);
    
//    analogWrite(ena,255);
  }
  else if(val == "B")//backward
  {
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,HIGH);
    
    digitalWrite(m2a,LOW);
    digitalWrite(m2b,HIGH);
    analogWrite(m2a,50);
    
//    analogWrite(ena,255);
  }
  else if(val == "L")//left and forward
  {
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,LOW);
    digitalWrite(m2a,HIGH);
    digitalWrite(m2b,LOW);
  }
  else if(val == "R")//right and forward
  {
    digitalWrite(m1a,HIGH);
    digitalWrite(m1b,LOW);
    digitalWrite(m2a,LOW);
    digitalWrite(m2b,LOW);
  }
  else if(val == "S")//stop all operations
  {
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,LOW);
    digitalWrite(m2a,LOW);
    digitalWrite(m2b,LOW);
    digitalWrite(m3a,LOW);
    digitalWrite(m3b,LOW);
  }
  else if(val == "O")//unroll or open and move forward
  {
    digitalWrite(m1a,HIGH);
    digitalWrite(m1b,LOW);
    
    digitalWrite(m2a,HIGH);
    digitalWrite(m2b,LOW);
    analogWrite(m2a,50);
    digitalWrite(m3a,HIGH);
    digitalWrite(m3b,LOW);
    
//    analogWrite(ena,255);
  }
  else if(val == "C")//roll or close and move backward
  {
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,HIGH);
    
    digitalWrite(m2a,LOW);
    digitalWrite(m2b,HIGH);
    analogWrite(m2a,50);
    digitalWrite(m3a,LOW);
    digitalWrite(m3b,HIGH);
    
//    analogWrite(ena,255);
  }
}
