#include <Arduino.h>
#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  myServo.attach (9);

  Serial.begin (9600);
}

void loop() {
  int const potPin = A0;
  int potVal;
  int angle;

  potVal = analogRead (potPin);

  float volts = ( potVal / 1023.0 ) * 5.0;

  Serial.print ("Volts: ");
  Serial.print (volts);
  Serial.print ("\n");

  // Serial.print ("potVal: ");
  // Serial.print (potVal);
  // Serial.print ("\n");

  angle = map (potVal, 0, 1023, 0, 179);

  if ( volts < 2.5 ) {
    Serial.print ("angle: 90\n");
    myServo.write (90);
  }
  else {
    Serial.print ("angle: ");
    Serial.print (angle);
    Serial.print ("\n");

    myServo.write (angle);
  }

  delay (15);
}