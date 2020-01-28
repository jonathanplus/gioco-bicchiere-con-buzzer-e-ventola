#include "pitches.h"
const float velocitasuono=2.5;
const int songspeed = 1.5;
#define sensor 17 // seleziona il pin per il sensore KY-032
#define buzzerPin 2 // seleziona il pin per il buzzer KY-006
#define ledPinverde 4
#define ledPinrosso 5
#define ledPinblu 6
#define motorePin 7


int melodia[] = {
  NOTE_C4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_C5,
  NOTE_B4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_B4, NOTE_C5, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4
};

int melodia2[] = {
  NOTE_E4 , NOTE_E4 , NOTE_E4 ,NOTE_E4 , NOTE_E4 , NOTE_E4 , NOTE_E4 , NOTE_G4 , NOTE_C4 , NOTE_D4 , NOTE_E4 ,
  0 ,
  NOTE_F4 , NOTE_F4 , NOTE_F4,
  NOTE_F4 , NOTE_F4 , NOTE_E4 ,
  NOTE_E4 , NOTE_E4 , NOTE_E4 , NOTE_D4 , NOTE_D4 , NOTE_E4 , NOTE_D4 , NOTE_G4 
};

int melodia4[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

int melodia5[] = {
NOTE_E5, NOTE_E3, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, // 8
NOTE_B4, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_A3, NOTE_D5, // 8
NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E3, NOTE_E5, // 8
NOTE_E3, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_B2, // 8
NOTE_C3, NOTE_D3, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_C5, NOTE_C5, NOTE_G5, // 8
NOTE_F5, NOTE_E5, NOTE_C3, 0, NOTE_C5, NOTE_E5, NOTE_A4, NOTE_G4, NOTE_D5, // 9
NOTE_C5, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_E5, // 8
NOTE_G4, NOTE_C5, NOTE_E4, NOTE_A4, NOTE_E3, NOTE_A4, 0, // 7
NOTE_E5, NOTE_E3, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, // 8
NOTE_B4, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_A3, NOTE_D5, // 8
NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E3, NOTE_E5, // 8
NOTE_E3, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_A4, NOTE_A3, NOTE_B2, // 8
NOTE_C3, NOTE_D3, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_C5, NOTE_C5, NOTE_G5, // 8
NOTE_F5, NOTE_E5, NOTE_C3, 0, NOTE_C5, NOTE_E5, NOTE_A4, NOTE_G4, NOTE_D5, // 9
NOTE_C5, NOTE_B4, NOTE_E4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_E5, // 8
NOTE_G4, NOTE_C5, NOTE_E4, NOTE_A4, NOTE_E3, NOTE_A4, 0, // 7
};

int melodia6[] = { //Note of the song, 0 is a rest/pulse
//Repeat of first part
NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
NOTE_A4, NOTE_G4, NOTE_A4, 0,

NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
NOTE_A4, NOTE_G4, NOTE_A4, 0,

NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
NOTE_D5, NOTE_E5, NOTE_A4, 0,
NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
NOTE_C5, NOTE_A4, NOTE_B4, 0,
//End of Repeat

NOTE_E5, 0, 0, NOTE_F5, 0, 0,
NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
NOTE_D5, 0, 0, NOTE_C5, 0, 0,
NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

NOTE_E5, 0, 0, NOTE_F5, 0, 0,
NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
NOTE_D5, 0, 0, NOTE_C5, 0, 0,
NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
};

int durataNote2[] = {
  6, 6, 3, 6, 6, 3, 6, 6, 6, 6 ,
  3, 6, 6 ,
  6, 6, 6 ,
  6, 6, 6, 6, 6, 6, 6, 6, 6, 3
};

int durataNote[] = {
  4, 4, 8, 8, 4, 4, 3,
  8, 3, 8, 4, 8, 8, 8,
  8, 4, 8, 8, 8, 8, 3
};

int durataNote4[] = {
  250,
  250, 125, 125, 125, 125,
  250, 250, 250,
  250, 125, 125, 125, 125,
  250, 250, 250,
  250, 125, 125, 125, 125,
  250, 250, 125, 125,
  250, 250, 250,
  500
};

int durataNote5[] = {
8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8, // 33
8,4,8,8,16,16,8,8,8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,4, // 31
8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8, // 33
8,4,8,8,16,16,8,8,8,8,8,8,8,16,16,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4,4, // 31
};

int duration[] = { //duration of each note (in ms) Quarter Note is set to 250 ms
//Rpeat of First Part
125, 125, 250, 125, 125, // 5
125, 125, 250, 125, 125, // 5
125, 125, 375, 125, // 4

125, 125, 250, 125, 125, // 5
125, 125, 250, 125, 125, // 5
125, 125, 250, 125, 125, // 5
125, 125, 375, 125, // 4

125, 125, 250, 125, 125, // 5
125, 125, 250, 125, 125, // 5
125, 125, 250, 125, 125, // 5
125, 125, 125, 250, 125, // 5

125, 125, 250, 125, 125, // 5
250, 125, 250, 125, // 4
125, 125, 250, 125, 125, // 5
125, 125, 375, 375, // 4
//End of Repeat

250, 125, 375, 250, 125, 375, // 6
125, 125, 125, 125, 125, 125, 125, 125, 375, // 9
250, 125, 375, 250, 125, 375, // 6
125, 125, 125, 125, 125, 500, // 6

250, 125, 375, 250, 125, 375, // 6
125, 125, 125, 125, 125, 125, 125, 125, 375, // 9
250, 125, 375, 250, 125, 375, // 6
125, 125, 125, 125, 125, 500 // 6
};

int numeroNote2 = 26;

int numeroNote = 21;

int canzone = 0;

int i;

void setup()   {
  Serial.begin(9600); // Initialization serial output
  pinMode(sensor, INPUT); // Initialization sensor pin
  pinMode(buzzerPin, OUTPUT); // Initialization buzzer pin
  pinMode(ledPinverde, OUTPUT);
  pinMode(ledPinrosso, OUTPUT);
  pinMode(ledPinblu, OUTPUT);
  pinMode(motorePin, OUTPUT);
}

void loop()
{
  bool val = digitalRead (sensor);

  if (val == HIGH) // If a signal is detected, the LED will light up.
  {
    Serial.println("Nessun ostacolo");
    Serial.print("canzone :");
    Serial.println(canzone);
  }
  else
  {
    Serial.println("Trovato ostacolo");
  canzone = canzone + 1;
  }
  if(canzone == 0){
    digitalWrite(ledPinblu,LOW);
    digitalWrite(ledPinverde,LOW);
    digitalWrite(ledPinrosso,HIGH);    
    }
  if(canzone == 1){
    digitalWrite(ledPinrosso,LOW);
    digitalWrite(ledPinverde,HIGH);
    digitalWrite(motorePin,HIGH);
    for(i = 0; i < numeroNote; i++){
      int durata = 1500 / durataNote[i];
      tone(buzzerPin, melodia[i], durata);
      delay(durata * 1.3);
      }
    canzone = canzone + 1;
    digitalWrite(ledPinverde,LOW);
    digitalWrite(motorePin,LOW);
    digitalWrite(ledPinrosso,HIGH);          
    }
  if(canzone == 3){
    digitalWrite(ledPinrosso,LOW);
    digitalWrite(ledPinblu,HIGH);
    digitalWrite(motorePin,HIGH);    
    for(i = 0; i < numeroNote2; i++){
      int durata2 = 1500 / durataNote2[i];
      tone(buzzerPin, melodia2[i], durata2);
      delay(durata2 * 1.3);
    }
    canzone = 4;
    digitalWrite(ledPinblu,LOW);
    digitalWrite(motorePin,LOW);
    digitalWrite(ledPinrosso,HIGH);    
    }
  if(canzone == 5){
    digitalWrite(ledPinrosso,LOW);
    digitalWrite(ledPinverde,HIGH);
    digitalWrite(motorePin,HIGH);
    tone(buzzerPin, 660 ,100);  
    delay ( 150);  
    tone(buzzerPin, 660 ,100);  
    delay ( 300);  
    tone(buzzerPin, 660 ,100);  
    delay ( 300);  
    tone(buzzerPin, 510 ,100);  
    delay ( 100);  
    tone(buzzerPin, 660 ,100);  
    delay ( 300);  
    tone(buzzerPin, 770 ,100);  
    delay ( 550);  
    tone(buzzerPin, 380 ,100);  
    delay ( 575);  
  
    tone(buzzerPin, 510 ,100);  
    delay ( 450);  
    tone(buzzerPin, 380 ,100);  
    delay ( 400);  
    tone(buzzerPin, 320 ,100);  
    delay ( 500);  
    tone(buzzerPin, 440 ,100);  
    delay ( 300);  
    tone(buzzerPin, 480 ,80);  
    delay ( 330);  
    tone(buzzerPin, 450 ,100);  
    delay ( 150);  
    tone(buzzerPin, 430 ,100);  
    delay ( 300);  
    tone(buzzerPin, 380 ,100);  
    delay ( 200);  
    tone(buzzerPin, 660 ,80);  
    delay ( 200);  
    tone(buzzerPin, 760 ,50);  
    delay ( 150);  
    tone(buzzerPin, 860 ,100);  
    delay ( 300);  
    tone(buzzerPin, 700 ,80);  
    delay ( 150);  
    tone(buzzerPin, 760 ,50);  
    delay ( 350);  
    tone(buzzerPin, 660 ,80);  
    delay ( 300);  
    tone(buzzerPin, 520 ,80);  
    delay ( 150);  
    tone(buzzerPin, 580 ,80);  
    delay ( 150);  
    tone(buzzerPin, 480 ,80);  
    delay ( 500);  
  
    tone(buzzerPin, 510 ,100);  
    delay ( 450);  
    tone(buzzerPin, 380 ,100);  
    delay ( 400);  
    tone(buzzerPin, 320 ,100);  
    delay ( 500);  
    tone(buzzerPin, 440 ,100);  
    delay ( 300);  
    tone(buzzerPin, 480 ,80);  
    delay ( 330);  
    tone(buzzerPin, 450 ,100);  
    delay ( 150);  
    tone(buzzerPin, 430 ,100);  
    delay ( 300);  
    tone(buzzerPin, 380 ,100);  
    delay ( 200);  
    tone(buzzerPin, 660 ,80);  
    delay ( 200);  
    tone(buzzerPin, 760 ,50);  
    delay ( 150);  
    tone(buzzerPin, 860 ,100);  
    delay ( 300);  
    tone(buzzerPin, 700 ,80);  
    delay ( 150);  
    tone(buzzerPin, 760 ,50);  
    delay ( 350);  
    tone(buzzerPin, 660 ,80);  
    delay ( 300);  
    tone(buzzerPin, 520 ,80);  
    delay ( 150);  
    tone(buzzerPin, 580 ,80);  
    delay ( 150);  
    tone(buzzerPin, 480 ,80);  
    delay ( 500);  
  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
  
    tone(buzzerPin, 760 ,100);  
    delay ( 100);  
    tone(buzzerPin, 720 ,100);  
    delay ( 150);  
    tone(buzzerPin, 680 ,100);  
    delay ( 150);  
    tone(buzzerPin, 620 ,150);  
    delay ( 300);  
  
    tone(buzzerPin, 650 ,150);  
    delay ( 300);  
    tone(buzzerPin, 380 ,100);  
    delay ( 150);  
    tone(buzzerPin, 430 ,100);  
    delay ( 150);  
  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
    tone(buzzerPin, 430 ,100);  
    delay ( 150);  
    tone(buzzerPin, 500 ,100);  
    delay ( 100);  
    tone(buzzerPin, 570 ,100);  
    delay ( 220);  
  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
  
    tone(buzzerPin, 760 ,100);  
    delay ( 100);  
    tone(buzzerPin, 720 ,100);  
    delay ( 150);  
    tone(buzzerPin, 680 ,100);  
    delay ( 150);  
    tone(buzzerPin, 620 ,150);  
    delay ( 300);  
  
    tone(buzzerPin, 650 ,200);  
    delay ( 300);  
  
    tone(buzzerPin, 1020 ,80);  
    delay ( 300);  
    tone(buzzerPin, 1020 ,80);  
    delay ( 150);  
    tone(buzzerPin, 1020 ,80);  
    delay ( 300);  
  
    tone(buzzerPin, 380 ,100);  
    delay ( 300);  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
  
    tone(buzzerPin, 760 ,100);  
    delay ( 100);  
    tone(buzzerPin, 720 ,100);  
    delay ( 150);  
    tone(buzzerPin, 680 ,100);  
    delay ( 150);  
    tone(buzzerPin, 620 ,150);  
    delay ( 300);  
  
    tone(buzzerPin, 650 ,150);  
    delay ( 300);  
    tone(buzzerPin, 380 ,100);  
    delay ( 150);  
    tone(buzzerPin, 430 ,100);  
    delay ( 150);  
  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
    tone(buzzerPin, 430 ,100);  
    delay ( 150);  
    tone(buzzerPin, 500 ,100);  
    delay ( 100);  
    tone(buzzerPin, 570 ,100);  
    delay ( 420);  
  
    tone(buzzerPin, 585 ,100);  
    delay ( 450);  
  
    tone(buzzerPin, 550 ,100);  
    delay ( 420);  
  
    tone(buzzerPin, 500 ,100);  
    delay ( 360);  
  
    tone(buzzerPin, 380 ,100);  
    delay ( 300);  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
    tone(buzzerPin, 500 ,100);  
    delay ( 150);  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
  
    tone(buzzerPin, 760 ,100);  
    delay ( 100);  
    tone(buzzerPin, 720 ,100);  
    delay ( 150);  
    tone(buzzerPin, 680 ,100);  
    delay ( 150);  
    tone(buzzerPin, 620 ,150);  
    delay ( 300);  
  
    tone(buzzerPin, 650 ,150);  
    delay ( 300);  
    tone(buzzerPin, 380 ,100);  
    delay ( 150);  
    tone(buzzerPin, 430 ,100);  
    delay ( 150);  
  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
    tone(buzzerPin, 430 ,100);  
    delay ( 150);  
    tone(buzzerPin, 500 ,100);  
    delay ( 100);  
    tone(buzzerPin, 570 ,100);  
    delay ( 220);  
  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
  
    tone(buzzerPin, 760 ,100);  
    delay ( 100);  
    tone(buzzerPin, 720 ,100);  
    delay ( 150);  
    tone(buzzerPin, 680 ,100);  
    delay ( 150);  
    tone(buzzerPin, 620 ,150);  
    delay ( 300);  
  
    tone(buzzerPin, 650 ,200);  
    delay ( 300);  
  
    tone(buzzerPin, 1020 ,80);  
    delay ( 300);  
    tone(buzzerPin, 1020 ,80);  
    delay ( 150);  
    tone(buzzerPin, 1020 ,80);  
    delay ( 300);  
  
    tone(buzzerPin, 380 ,100);  
    delay ( 300);  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
  
    tone(buzzerPin, 760 ,100);  
    delay ( 100);  
    tone(buzzerPin, 720 ,100);  
    delay ( 150);  
    tone(buzzerPin, 680 ,100);  
    delay ( 150);  
    tone(buzzerPin, 620 ,150);  
    delay ( 300);  
  
    tone(buzzerPin, 650 ,150);  
    delay ( 300);  
    tone(buzzerPin, 380 ,100);  
    delay ( 150);  
    tone(buzzerPin, 430 ,100);  
    delay ( 150);  
  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
    tone(buzzerPin, 430 ,100);  
    delay ( 150);  
    tone(buzzerPin, 500 ,100);  
    delay ( 100);  
    tone(buzzerPin, 570 ,100);  
    delay ( 420);  
  
    tone(buzzerPin, 585 ,100);  
    delay ( 450);  
  
    tone(buzzerPin, 550 ,100);  
    delay ( 420);  
  
    tone(buzzerPin, 500 ,100);  
    delay ( 360);  
  
    tone(buzzerPin, 380 ,100);  
    delay ( 300);  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);  
    tone(buzzerPin, 500 ,100);  
    delay ( 150);  
    tone(buzzerPin, 500 ,100);  
    delay ( 300);    

    
    canzone = 6;
    digitalWrite(ledPinverde,LOW);
    digitalWrite(motorePin,LOW);
    digitalWrite(ledPinrosso,HIGH);    
    }
  if(canzone == 7){
    digitalWrite(ledPinrosso,LOW);
    digitalWrite(ledPinblu,HIGH);
    digitalWrite(motorePin,HIGH);    
    float durata4;
    for(i=0;i<30;i++){
      durata4=velocitasuono * durataNote4[i];
      tone(buzzerPin,melodia4[i],durata4); 
      delay(durata4);  

      }
    
    canzone = 8;
    digitalWrite(ledPinblu,LOW);
    digitalWrite(motorePin,LOW);
    digitalWrite(ledPinrosso,HIGH);    
    }
  if(canzone == 9){
    digitalWrite(ledPinrosso,LOW);
    digitalWrite(ledPinverde,HIGH);
    digitalWrite(motorePin,HIGH);    
    for (int thisNote = 0; thisNote < 128; thisNote++){
      int noteDuration = 1000/durataNote5[thisNote];
      tone(buzzerPin, melodia5[thisNote],noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
    canzone = 10;
    digitalWrite(ledPinverde,LOW);
    digitalWrite(motorePin,LOW);
    digitalWrite(ledPinrosso,HIGH);    
    }

  if(canzone == 11){
    digitalWrite(ledPinrosso,LOW);
    digitalWrite(ledPinblu,HIGH);
    digitalWrite(motorePin,HIGH);    
    for (int i=0;i<125;i++){ //203 is the total number of music notes in the song
      int wait = duration[i] * songspeed;
      tone(buzzerPin,melodia6[i],wait); //tone(pin,frequency,duration)
      delay(wait);
    }
    canzone = 0;
    digitalWrite(ledPinblu,LOW);
    digitalWrite(motorePin,LOW);
    digitalWrite(ledPinrosso,HIGH);    
    }
  delay (30);
  }
