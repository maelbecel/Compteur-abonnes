// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 


Servo servo1;  // create servo object to control a servo 
Servo servo2;                // a maximum of eight servo objects can be created
Servo servo3;
Servo servo4;

int nb = 9898;
 
void setup() 
{
  servo1.attach(8);
  servo2.attach(9);  // attaches the servo on pin 9 to the servo object
  servo3.attach(10);
  servo4.attach(11);
}

void move_s(Servo serv, int n)
{                              
    serv.write(10*n);               
    delay(15*n);                       
}

void loop() 
{
  move_s(servo1, nb / 1000 % 10);
  move_s(servo2, nb / 100 % 10);
  move_s(servo3, nb / 10 % 10);
  move_s(servo4, nb % 10);
  nb++;
} 
