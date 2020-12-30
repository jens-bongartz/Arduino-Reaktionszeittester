#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define taster_gruen 6
#define taster_rot 7
#define led_gruen 9
#define led_rot 10

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  pinMode(taster_gruen,INPUT_PULLUP);
  pinMode(taster_rot,INPUT_PULLUP);
  pinMode(led_gruen, OUTPUT);
  pinMode(led_rot, OUTPUT);
  lcd.init();                      // initialize the lcd 
  //lcd.noBacklight();
  lcd.backlight();
  lcd.clear();
  lcd.noCursor();
  lcd.noBlink();
  lcd.setCursor(0,0);
  lcd.print("Reaktionstest");
}

void loop()
{
   bool taster_gruen_state = digitalRead(taster_gruen);
   bool taster_rot_state = digitalRead(taster_rot);

   if (taster_gruen_state == LOW){
    digitalWrite(led_gruen, HIGH);
   }
   else {
    digitalWrite(led_gruen, LOW);    
   }

   if (taster_rot_state == LOW){
    digitalWrite(led_rot, HIGH);
   }
   else {
    digitalWrite(led_rot, LOW);    
   }
} 
