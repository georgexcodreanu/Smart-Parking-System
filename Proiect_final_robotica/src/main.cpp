#include <LiquidCrystal.h>
#include <Servo.h>
#include <Wire.h>

const int rs = 12;
const int en = 11;
const int d4 = 7;
const int d5 = 8;
const int d6 = 9;
const int d7 = 10;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo myservo;

const int IR1 = 3;
const int IR2 = 2;

int Slot = 2;
int flag1 = 0;
int flag2 = 0;

bool debounce(int pin) {
  if (digitalRead(pin) == HIGH) {
    delay(50);
    if (digitalRead(pin) == HIGH) {
      return true;
    }
  }
  return false;
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  myservo.attach(4);
  myservo.write(70);

  lcd.setCursor(0, 0);
  lcd.print("     ARDUINO    ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING SYSTEM ");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Stabilizing...");
  delay(500);
  lcd.clear();
}

void loop() {
  if (debounce(IR1) && flag1 == 0) {
    if (Slot > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        myservo.write(0);
        Slot = Slot - 1;
      }
    } else {
      lcd.setCursor(0, 0);
      lcd.print("    SORRY    ");
      lcd.setCursor(0, 1);
      lcd.print("  Parking Full  ");
      delay(3000);
      lcd.clear();
    }
  }

  if (debounce(IR2) && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      myservo.write(0);
      Slot = Slot + 1;
    }
  }

  if (flag1 == 1 && flag2 == 1) {
    delay(1000);
    myservo.write(70);
    flag1 = 0;
    flag2 = 0;
  }

  lcd.setCursor(0, 0);
  lcd.print("    WELCOME!    ");
  lcd.setCursor(0, 1);
  lcd.print("Slots Left: ");
  lcd.print(Slot);
}
