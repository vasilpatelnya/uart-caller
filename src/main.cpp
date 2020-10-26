#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial gtSerial(0, 1);

const int DEVICE_1 = 2;
const int DEVICE_2 = 3;
const int DEVICE_3 = 4;
const int DEVICE_4 = 5;

void setup()
{
  Serial.begin(9600);
  gtSerial.begin(9600);

  pinMode(DEVICE_1, OUTPUT);
  pinMode(DEVICE_2, OUTPUT);
  pinMode(DEVICE_3, OUTPUT);
  pinMode(DEVICE_4, OUTPUT);

  digitalWrite(DEVICE_1, HIGH);
  digitalWrite(DEVICE_2, HIGH);
  digitalWrite(DEVICE_3, HIGH);
  digitalWrite(DEVICE_4, HIGH);
}

void switchDevice(int device){
  int state = digitalRead(device);

  if (state == HIGH)
  {
    state = LOW;
  }
  else
  {
    state = HIGH;
  }

  digitalWrite(device, state);
}

void loop()
{
  if (gtSerial.available())
  {
    Serial.println(gtSerial.read());
  }
  if (Serial.available())
  {
    int signal = Serial.read();
    Serial.println(signal);
    switch (signal)
    {
    case 'a':
      Serial.println("A device");
      switchDevice(DEVICE_1);

      break;
    case 'b':
      Serial.println("B device");
      switchDevice(DEVICE_2);

      break;
    case 'c':
      Serial.println("C device");
      switchDevice(DEVICE_3);

      break;
    case 'd':
      Serial.println("D device");
      switchDevice(DEVICE_4);

      break;
    
    default:
      delay(800);
    }
  }
}