#include <Servo.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);//connected ke RS,EN,D4,D5,D6,D7 di LCD
Servo servoM;  // deklarasi servo motor


#define MicServo    7        //deklarasi pin 7 untuk servo motor
#define Exit      9         //Pin connect ke EXIT sensor.
#define In        8         //Pin connect ke IN sensor.
#define Pwr  6              //Power pin tambahan untuk sensor
#define Gnd  10             //Ground pin tambahan untuk sensor
#define BarLow    90      //posisi rendah untuk barrier servo motor.
#define BarUp     177        //posisi tinggi untuk barrier servo motor.
#define CAPACITY  10         //Kapasitas tempat parkir.


void setup(){
  servoM.attach(MicServo);          // Menyalakan servo.
  lcd.begin(16,2);
  lcd.print("Parkir Kosong:");
  pinMode(Gnd, OUTPUT);
  pinMode(Pwr, OUTPUT);
  pinMode(Exit, INPUT);           // deklarasi pin sensor "EXIT" input
  pinMode(In, INPUT);             // deklarasi pin sensor "IN" input
  digitalWrite(Gnd, LOW);
  digitalWrite(Pwr, HIGH);
  servoM.write(BarLow);          //Barrier posisi rendah di awal jalannya program
//  delay(1000);
}


int  Available= 10;                    // Nominal tempat parkir kosong.


void loop(){
if (Available == 1){
  lcd.clear();
lcd.setCursor(0,0);
lcd.print("Parkir Kosong:");
lcd.setCursor(0,1);  
lcd.print(Available);
lcd.print(" Mobil");
}else{
if (Available >= 1){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Parkir kosong");
lcd.setCursor(0,1);  
lcd.print(Available);
lcd.print(" Mobil");
}else{
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Maaf");
    lcd.setCursor(0,1);
    lcd.print("Penuh");
}
}


if(digitalRead(In)==1)
{
  if(Available != 0){
    Available--;
    servoM.write(BarUp);
    delay(1000);
    servoM.write(BarLow);
    }
  }
if(digitalRead(Exit)==1)
{
  if(Available != CAPACITY){
    Available++;
    servoM.write(BarUp);
    delay(1000);
    servoM.write(BarLow);
    }
}
  delay(20);
}


