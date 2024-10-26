#include <Servo.h>
Servo servo1;
Servo servo2;
int eje1=180;
int eje2=180;
void setup(){  
  servo1.attach(3);
  servo2.attach(5);
  servo1.write(180);
  servo2.write(180);
}
void loop(){
  if (analogRead(0)<200 && eje1<180){
    eje1++;
    servo1.write(eje1);
  }
  if (analogRead(0)>700 && eje1>0){
    eje1--;
    servo1.write(eje1);
  }
  if (analogRead(1)<200 && eje2<180){
    eje2++;
    servo2.write(eje2);
  }
  if (analogRead(1)>700 && eje2>0){
    eje2--;
    servo2.write(eje2);
  }
  delay(15);
}