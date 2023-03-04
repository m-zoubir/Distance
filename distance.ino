#include <LiquidCrystal_I2C.h>


const int trig = 7 ; 
const int echo = 8 ; 

LiquidCrystal_I2C lcd(0x27,16,2);  

void setup()
{
  lcd.init();                      
  lcd.backlight();
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  
  
}


void loop()
{
   long duration , cm ; 
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(20);
  digitalWrite(trig,LOW);
  
  duration = pulseIn(echo , HIGH);
  cm = duration *34000 /2000000 ;
  // the sound speed is 340m/s and converting to cm/us => 34000/1000000 = 0.034cm /us 
  // deviding by 2 to calculate the distance one time ( forth or back )
  lcd.setCursor(0,0);
  lcd.print("the distance :");
  lcd.setCursor(3,1);
  lcd.print("          ");
  lcd.setCursor(3,1);
  lcd.print(cm);
  lcd.setCursor(7,1);
  lcd.print("cm");
  delay(10);
}