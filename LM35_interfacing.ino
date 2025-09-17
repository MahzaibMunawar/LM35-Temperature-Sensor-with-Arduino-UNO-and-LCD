
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // Adjust pins

int sensorPin = A0;  //Sensor output at A0 of Arduino
float tempC;  
float power=5000;// power source in mV
float bits=1024; // for ADC
float adcfac;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temp: ");
}

void loop() {
  int value = analogRead(sensorPin); // temperature reading
  adcfac= power/bits;
  tempC = (value *adcfac) / 10; //10mV=1C

  lcd.setCursor(0, 1);
  lcd.print(tempC);
  lcd.print(" C");
  delay(1000);
}
