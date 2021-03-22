#define ADC_DELTA 5 
#define ADC1 1

int initial_voltage = 0;

int read_voltage(int pin) {
  int retry = 20;
  int voltage = 0;
  for(int i=0; i < retry; i++) {
    voltage += analogRead(pin);
    delay(10);
  }
  return (int)(voltage/retry);
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
