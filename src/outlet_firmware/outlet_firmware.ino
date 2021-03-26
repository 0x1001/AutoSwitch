#include <math.h>

#define ADC_DELTA 5 
#define ADC1 1
#define SAMPLES 100

int initial_voltage = 0;

int read_voltage(int pin) {
  int retry = SAMPLES;
  int voltage[SAMPLES];
  
  for(int i=0; i < SAMPLES; i++) {
    voltage[i] = analogRead(pin);
    delay(1);
  }

  long sum = 0;
  for(int i=0; i < SAMPLES; i++) {
    sum += pow(voltage[i], 2);
  }
  
  return (int)sqrt(sum/SAMPLES);
}

void setup() {
 //Initialisierung der digitalen PINs
 pinMode(PB0, OUTPUT); //Relay
 pinMode(PB1, INPUT); //Button
 initial_voltage = read_voltage(ADC1);
}

void loop() {
 int voltage = read_voltage(ADC1);
 int button_on_off = digitalRead(PB1);

if (button_on_off == HIGH || voltage > initial_voltage + ADC_DELTA || voltage < initial_voltage - ADC_DELTA) {
  digitalWrite(PB0, HIGH);
 } else {
  digitalWrite(PB0, LOW);
 }
 
 delay(10);
}
