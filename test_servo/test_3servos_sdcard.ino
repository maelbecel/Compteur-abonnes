// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.

#include <LiquidCrystal.h>
#include <Servo.h> 
#include <SPI.h>
#include <SD.h>

Servo servo1;  // create servo object to control a servo 
Servo servo2;                // a maximum of eight servo objects can be created
Servo servo3;
Sd2Card CarteSD;
SdVolume VolumeCarteSD;
uint32_t volumesize;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int nb = 898;

#define sdCardSelect 10
 
void setup() 
{
  lcd.begin(16, 2);
  if (CarteSD.init(SPI_HALF_SPEED, sdCardSelect)) {
    lcd.print("NO SD card");
    while (1);
  } else {
    lcd.print("SD card found");
  }
  
  servo1.attach(8);
  servo2.attach(9);  // attaches the servo on pin 9 to the servo object
  servo3.attach(1);
}

void move_s(Servo serv, int n)
{                              
    serv.write(10*n);               
    delay(15*n);                       
}

void loop() 
{
  lcd.print("servo1 = ");
  lcd.setCursor(0, 1);
  lcd.print(nb / 100, DEC);
  delay(1000);
  lcd.clear();
  move_s(servo1, nb / 100);
  
  lcd.print("servo2 = ");
  lcd.setCursor(0, 1);
  lcd.print(nb / 10 % 10, DEC);
  delay(1000);
  lcd.clear(); 
  move_s(servo2, nb / 10 % 10);
  
  lcd.print("servo3 = ");
  lcd.setCursor(0, 1);
  lcd.print(nb % 10 , DEC);
  delay(1000);
  lcd.clear();
  move_s(servo3, nb % 10);
  nb++;
} 
