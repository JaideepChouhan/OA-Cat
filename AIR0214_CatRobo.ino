//Jai Shree Ram...

#include<Servo.h>
    int eco=5,tri=4,distance,duration;
    int value = 0,leftV=0,rightV=0;
    Servo serL,serR;
//****************************SETUP
void setup()
{
  serL.attach(8);
  serR.attach(13);
pinMode(eco,INPUT);https://github.com/JaideepChouhan
pinMode(tri,OUTPUT);

  serL.write(90);
  serR.write(90);
Serial.begin(9600);  
}
//***********************************LOOP
void loop()
{
  value = dist();
  Serial.println(value);
  delay(100);

  if (value > 20)
  {
    wf();
  } else {
    turnL();
  }

if (value <= 20 && value >15)
{
  turnL();
  delay(2000);
  stop();
  leftV=dist();
  delay(1000);
  
  turnR();
  delay(2000);
  stop();
  rightV=dist();
  delay(1000);

  if (leftV>rightV)
  {
    turnL();
    delay(2000);
  } else {
    wf();
  }
} else if (value <=15)
{
  wb();
} else {
  wf();
}

}
void turnL()
{
   serR.write(100);
   serL.write(80);
}
void turnR()
{
   serR.write(87);
   serL.write(93);
}
void wf()
{
  serL.write(100);
  serR.write(100);
}
void wb()
{
  serL.write(87);
  serR.write(87);
}
void stop()
{
  serR.write(90);
  serL.write(90);
}
int dist()
{
  digitalWrite(tri,HIGH);
  delayMicroseconds(10);
  digitalWrite(tri,LOW);
  duration=pulseIn(eco,HIGH);
  distance=duration*0.034/2;
  return distance;
}
