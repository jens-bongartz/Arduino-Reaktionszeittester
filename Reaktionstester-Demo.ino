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
  digitalWrite(led_gruen, LOW);
  digitalWrite(led_rot, LOW);
  
  lcd.init();                      // initialize the lcd 
  //lcd.noBacklight();
  lcd.backlight();
  lcd.clear();
  lcd.noCursor();
  lcd.noBlink();
  lcd.setCursor(0,0);
  lcd.print("R-Zeit[ms]:");
  lcd.setCursor(0,1);
  lcd.print("Start>rote Taste");
}

void loop()
{
   // Warten, dass der rote Taster betaetigt wird
   bool taster_rot_state;
   do {
      taster_rot_state = digitalRead(taster_rot);
   } while (taster_rot_state == HIGH);
   // Beginn der Messung
   // rote LED an / gruene LED aus
   digitalWrite(led_rot,HIGH);
   digitalWrite(led_gruen,LOW);
   lcd.setCursor(0,1);
   lcd.print("Messung laeuft! ");
   // zufaellige Wartezeit
   int wartezeit = random(2000,6000);
   delay(wartezeit);
   // gruene LED an / rote LED aus  
   digitalWrite(led_rot,LOW);
   digitalWrite(led_gruen,HIGH);
   // Messung der Reaktionszeit
   // Speichern der aktuellen Zeit beim Einschalten der gruenen LED
   long t0 = millis();
   bool taster_gruen_state;
   do {
      taster_gruen_state = digitalRead(taster_gruen);
   } while (taster_gruen_state == HIGH);
   // Reaktionszeit ist aktuelle Zeit beim Druecken des gruenen Tasters 
   // minus t0
   int reaktionszeit = millis() - t0;
   // Ausgabe des Ergebnisses auf dem LCD
   lcd.setCursor(11,0);
   lcd.print("    ");
   lcd.setCursor(11,0);
   lcd.print(reaktionszeit);   
   lcd.setCursor(0,1);
   lcd.print("Messung beendet!");
   delay(3000);
   lcd.setCursor(0,1);
   lcd.print("Start>rote Taste");
} 
