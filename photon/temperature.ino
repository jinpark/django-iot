// This #include statement was automatically added by the Particle IDE.

#include "application.h"
#include <math.h>


// name pins
#define TEMPPIN A0

double tempC = 0.0;
double tempF = 0.0;

void setup() {
    pinMode(TEMPPIN, INPUT);
}

void loop() {
    int B = 3975;
    int analogValue = analogRead(TEMPPIN);                                      // read temprature sensor pin
    float resistance=(float)(4095-analogValue)*10000/analogValue;               // get the resistance of the sensor
    tempC=1/(log(resistance/10000)/B+1/298.15)-273.15;                          // temprature in celcius
    tempF = tempC * 9.0 / 5.0 + 32.0;                                           // temprature in farenhiet
    String jsonDataString = String( "{ \"temp\": " + String(tempC) + "}");
    Particle.publish("temp", jsonDataString);
    Particle.publish("DEBUG", String(tempC));
    delay(3000);
}
