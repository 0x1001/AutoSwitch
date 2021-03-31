#include "ACS712.h"

#define ADC_DELTA 200 
#define ADC1 1

int initial_voltage = 0;
ACS712  ACS(ADC1, 5.0, 1023, 66);

void setup() {
 //Initialisierung der digitalen PINs
 pinMode(PB0, OUTPUT); //Relay
 pinMode(PB1, INPUT); //Button
 ACS.autoMidPoint();
 initial_voltage = ACS.mA_AC();
}

void loop() {
 int voltage = ACS.mA_AC();
 int button_on_off = digitalRead(PB1);

if (button_on_off == HIGH || voltage > initial_voltage + ADC_DELTA || voltage < initial_voltage - ADC_DELTA) {
  digitalWrite(PB0, HIGH);
 } else {
  digitalWrite(PB0, LOW);
 }
 
 delay(10);
}
