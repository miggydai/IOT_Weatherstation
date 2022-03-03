#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int tempC;
int tempF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  lcd.begin(16, 2);
  pinMode(A0, INPUT);

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = analogRead(A0);
  int airPressure = analogRead(A2);
  int humidity = analogRead(A4);
  int anemometer = analogRead(A1);
  int waterLevel = analogRead(A3);

  digitalWrite(2, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  delay(1);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);



  float volt = temp * 5.0;
  tempC = ((( volt - 0.5) * 100 + 50) / 1000) - 1;
  tempF = (tempC * 9 / 5) + 32;


  //temp C
  if (digitalRead(11) == HIGH && digitalRead(8) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature C:");
    lcd.setCursor(0, 1);
    lcd.print(tempC);
    delay(250);
  }
  //Temp F
  if (digitalRead(12) == HIGH && digitalRead(8) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature F: ");
    lcd.setCursor(0, 1);
    lcd.print(tempF);
    delay(250);
  }
  //Air Pressure
  if (digitalRead(9) == HIGH && digitalRead(12) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Air Pressure: ");
    lcd.setCursor(0, 1);
    lcd.print(airPressure);
    delay(250);
  }
  //Humidity
  if (digitalRead(11) == HIGH && digitalRead(9) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.setCursor(0, 1);
    lcd.print(humidity);
    delay(250);
  }
  //Water Level
  if (digitalRead(10) == HIGH && digitalRead(12) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Water Level: ");
    lcd.setCursor(0, 1);
    lcd.print(waterLevel);
    delay(250);
  }
  //Wind Speed
  if (digitalRead(10) == HIGH && digitalRead(11) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wind Speed km/h: ");
    lcd.setCursor(0, 1);
    lcd.print(anemometer);
    delay(250);
  }

  //Serial output
  Serial.print("wsp");
  Serial.print(anemometer);
 

  Serial.print(",ap");
  Serial.print(airPressure);


  Serial.print(",wl");
  Serial.print(waterLevel);
 

  Serial.print(",hu");
  Serial.print(humidity);


  Serial.print(",tc");
  Serial.print(tempC);


  Serial.print(",tf");
  Serial.print(tempF);
  
  Serial.print("yas");
  Serial.print("\n");
  


}
