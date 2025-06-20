#include <Servo.h>
#include <Wire.h>
#include <LCD_I2C.h>

const int soilSensorPin = A0;
const int TrigPin = 9;
const int EchoPin = 10;
const int servoMotorPin = 6;

LCD_I2C lcd(0x27);
Servo servoMotor;

void setup() {
  Serial.begin(9600);
  lcd.begin();
	lcd.backlight();

  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  servoMotor.attach(servoMotorPin);
}

void loop() {
  slideToCenter();
  int soilMoisture = analogRead(soilSensorPin);
  float distance = getUltrasonicDistance(); 
  float distanceThreshold = 10.0;  // Set detection range from 0 to 10 cm TRASH RANGE

  if (distance > 0 && distance <= distanceThreshold) {
    Serial.println("Trash detected");
    lcd.clear();
    lcd.setCursor(5, 0);
	  lcd.print("Trash");
	  lcd.setCursor(4, 1);
   	lcd.print("Detected");
    delay(2000);

    if (soilMoisture > 1020) {
      lcd.clear();
      lcd.setCursor(6, 0);
	    lcd.print("Dry");
	    lcd.setCursor(5, 1);
     	lcd.print("Waste");
      slideToRight();
      delay(1000);
      slideToCenter();
      Serial.println("Dry - Sliding to the right");
    } else {
      lcd.clear();
      lcd.setCursor(6, 0);
	    lcd.print("Wet");
	    lcd.setCursor(5, 1);
     	lcd.print("Waste");
      slideToLeft();
      delay(1000);
      slideToCenter();
      Serial.println("Wet - Sliding to the left");
    }
    Serial.print("Moisture: ");
    Serial.println(soilMoisture);
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    Serial.println("No trash detected");
    lcd.clear();
    lcd.setCursor(2, 0);
	  lcd.print("Wet and Dry");
	  lcd.setCursor(2, 1);
   	lcd.print(" Segregator");
  }

  delay(500);
}

float getUltrasonicDistance() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(7);
  digitalWrite(TrigPin, LOW);
  float duration = pulseIn(EchoPin, HIGH);
  float distance_cm = duration * 0.0343 / 2.0;  // Use 2.0 for accurate floating-point division
  return distance_cm;
}

void slideToCenter() {
  servoMotor.write(97);
}


void slideToLeft() {
  for (int pos = 97; pos >= 7; pos--) {
    servoMotor.write(pos);
    delay(15);  // Adjust the delay to control the speed of the movement
  }
  delay(1000);
  for (int pos = 7; pos <= 97; pos++){
    servoMotor.write(pos);
    delay (15);
  }
}

void slideToRight() {
  for (int pos = 97; pos <= 187; pos++) {
    servoMotor.write(pos);
    delay(15);  // Adjust the delay to control the speed of the movement
  }
  delay (1000);
  for (int pos = 187; pos >= 97; pos--){
    servoMotor.write(pos);
    delay(15);
  }
}