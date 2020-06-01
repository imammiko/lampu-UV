#include <EEPROM.h>
#include <EEWrap.h>
#include <ezButton.h>
#include <Buzzer.h>

#define lampu1 1
#define lampu2 2
#define lampu3 4
#define lampu4 8
#define lampuMati 0
#define relayPin A0
#define lampuR 9
#define lampuG 10
#define lampuB 11
//#define remoteA=A1;
//#define remoteB=A2;
int16_e JUMLAHKLIK EEMEM;


Buzzer buzzer(5, 6);
ezButton button(A4);// TOMBOL FISIK 2
ezButton tombolA(A1);//TOMBOL remot A
ezButton tombolB(A2);//Tombol Remot B
ezButton tombolC(A3); //TOMBOL FISIK1
byte banyakLampu = 4;
const byte lamp[] = {2, 4, 7, 8};
byte jumlahKlik = 1;
int state = 0;


int x = 0;
int y = 0;

unsigned long previousMillisPressButton = 0;
const long intervalButton = 3000;
// waktu interval
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
const long interval = 2000;
const long interval15 = 920000;
const long interval30 = 1820000;
const long interval160 = 2720000;
const long intervalCustom = 3620000;
const long delayAwal = 20000;

//blyink withoud delay
//const int ledPin =  LED_BUILTIN;// the number of the LED pin

// Variables will change:
int ledStateBlink = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillisBlink = 0;        // will store last time LED was updated

// constants won't change:
const long intervalBlink = 1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  button.setDebounceTime(50);
  tombolA.setDebounceTime(50);
  tombolB.setDebounceTime(50);
  tombolC.setDebounceTime(50);
  button.setCountMode(COUNT_FALLING);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  for (int i = 0; i < banyakLampu; i++) {
    pinMode(lamp[i], OUTPUT);
    digitalWrite(lamp[i], LOW);
  }
  pinMode(lampuR, OUTPUT);
  pinMode(lampuG, OUTPUT);
  pinMode(lampuB, OUTPUT);
  jumlahKlik = JUMLAHKLIK;
}


void loop() {
  // put your main code here, to run repeatedly:
  button.loop();
  tombolA.loop();
  tombolB.loop();
  

  currentMillis = millis();



  lampu(tombolHitung());
  warnaLampuRGB(3);


}
int hidupLampu(byte lampu) {

  switch (lampu) {
    case 1:
      previousMillis = millis();
      buzzerSound1();
      while (1) {
        button.loop();
        tombolA.loop();
         tombolB.loop();
         tombolC.loop();
        blinkLed();
        currentMillis = millis();
        //Serial.println("dua");
        Serial.print(interval15);
        Serial.print("  ");
        Serial.println(currentMillis - previousMillisPressButton);
        if ((currentMillis - previousMillisPressButton >= 20000)) {
          digitalWrite(relayPin, LOW);
           
          if (x < 2) {
            buzzerSound2();
            x += 1;
          }
        }
        if ((currentMillis - previousMillisPressButton >= (interval15)) || button.isPressed() || tombolA.isPressed()||tombolB.isPressed()||tombolC.isPressed())
        {
          //return true;
          if (button.isPressed() || tombolA.isPressed()) {
            jumlahKlik = 1;
          }
          x = 0;
          buzzerSound3();
          digitalWrite(relayPin, HIGH);
          Serial.println("stop");
          break;
        }

      }
      break;
    case 2:
      // statements
      previousMillis = millis();
      buzzerSound1();
      while (1) {
        button.loop();
        tombolA.loop();
         tombolB.loop();
         tombolC.loop();
        blinkLed();
        currentMillis = millis();
        //Serial.println("dua");
        Serial.print(interval15);
        Serial.print("  ");
        Serial.println(currentMillis - previousMillisPressButton);
        if ((currentMillis - previousMillisPressButton >= 20000)) {
          digitalWrite(relayPin, LOW);
           
          if (x < 2) {
            buzzerSound2();
            x += 1;
          }
        }
        if ((currentMillis - previousMillisPressButton >= (interval30)) || button.isPressed() || tombolA.isPressed()||tombolB.isPressed()||tombolC.isPressed())
        {
          //return true;
          if (button.isPressed() || tombolA.isPressed()) {
            jumlahKlik = 2;
          }
          x = 0;
          buzzerSound3();
          digitalWrite(relayPin, HIGH);
          Serial.println("stop");
          break;
        }

      }
      break;
    case 3:
      previousMillis = millis();
      buzzerSound1();
      while (1) {
        button.loop();
        tombolA.loop();
        tombolB.loop();
        tombolC.loop();
        blinkLed();
        currentMillis = millis();
        //Serial.println("dua");
        Serial.print(interval30);
        Serial.print("  ");
        Serial.println(currentMillis - previousMillisPressButton);
        if ((currentMillis - previousMillisPressButton >= 20000)) {
          digitalWrite(relayPin, LOW);
          
          if (x < 2) {
            buzzerSound2();
            x += 1;
          }
        }

        if ((currentMillis - previousMillisPressButton >= (interval160)) || button.isPressed() || tombolA.isPressed()||tombolB.isPressed()||tombolC.isPressed())
        {
          //return true;
          if (button.isPressed() || tombolA.isPressed()) {
            jumlahKlik = 3;
          }
          x = 0;
          buzzerSound3();
          digitalWrite(relayPin, HIGH);
          Serial.println("stop");
          break;
        }

      }
      break;
    case 4:
      previousMillis = millis();
      buzzerSound1();
      while (1) {
        button.loop();
        tombolA.loop();
        tombolB.loop();
        tombolC.loop();
        blinkLed();
        currentMillis = millis();
        //Serial.println("dua");
        Serial.print(intervalCustom);
        Serial.print("  ");
        Serial.println(currentMillis - previousMillisPressButton);
        if ((currentMillis - previousMillisPressButton >= 20000)) {
          digitalWrite(relayPin, LOW);
           
          if (x < 2) {
            buzzerSound2();
            x += 1;
          }
        }
        if ((currentMillis - previousMillisPressButton >= (intervalCustom)) || button.isPressed() || tombolA.isPressed()||tombolB.isPressed()||tombolC.isPressed())
        {
          //return true;
          if (button.isPressed() || tombolA.isPressed()) {
            jumlahKlik = 4;
          }
          x = 0;
          buzzerSound3();
          digitalWrite(relayPin, HIGH);
          Serial.println("stop");
          break;
        }

      }
      break;
      
    default:
      // statements
      break;
  }
}
void buzzerSound1() {
  buzzer.begin(100);

  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(NOTE_E7, 80);

  buzzer.end(500);
}
void buzzerSound2() {
  buzzer.begin(100);

  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(NOTE_E8, 80);
  buzzer.sound(NOTE_E5, 80);

  buzzer.end(500);
}

void buzzerSound3() {
  buzzer.begin(100);

  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(NOTE_E5, 80);

  buzzer.end(500);
}
bool longPress() {
  //button.loop();

  currentMillis = millis();
  previousMillisPressButton = currentMillis;
  int btnState = button.getState();
  int btnState1 = tombolA.getState();
  while (!btnState || !btnState1) {
    button.loop();
    tombolA.loop();
    btnState = button.getState();
    btnState1 = tombolA.getState();
    currentMillis = millis();


    if (currentMillis - previousMillisPressButton >= interval) {
      return true;


    }
    //    if (!digitalRead(A2)) {
    //      //digitalWrite(relayPin, LOW);
    //    } else {
    //
    //      digitalWrite(relayPin, HIGH);
    //    }
    Serial.println(currentMillis - previousMillisPressButton);
    // Serial.println("ayo");

  } return false;

}

int tombolHitung() {


  if (longPress()) {
    hidupLampu(jumlahKlik);
  }


  if (jumlahKlik > 4) jumlahKlik = 1;

  if (button.isReleased() || tombolB.isPressed()) {
    jumlahKlik += 1;

  }
  JUMLAHKLIK = jumlahKlik;
  Serial.println(jumlahKlik);
  return jumlahKlik;
}




void lampu(int nomor) {
  int namaLampu = 0;
  switch (nomor) {
    case 1:
      //      namaLampu = lampu1;
      digitalWrite(lamp[0], HIGH);
      digitalWrite(lamp[1], LOW);
      digitalWrite(lamp[2], LOW);
      digitalWrite(lamp[3], LOW);
      break;
    case 2:
      //      namaLampu = lampu2;
      digitalWrite(lamp[0], LOW);
      digitalWrite(lamp[1], HIGH);
      digitalWrite(lamp[2], LOW);
      digitalWrite(lamp[3], LOW);
      break;
    case 3:
      //      namaLampu = lampu3;
      digitalWrite(lamp[0], LOW);
      digitalWrite(lamp[1], LOW);
      digitalWrite(lamp[2], HIGH);
      digitalWrite(lamp[3], LOW);
      break;
    case 4:
      //      namaLampu = lampu4;
      digitalWrite(lamp[0], LOW);
      digitalWrite(lamp[1], LOW);
      digitalWrite(lamp[2], LOW);
      digitalWrite(lamp[3], HIGH);
      break;
    case 0:
      digitalWrite(lamp[0], LOW);
      digitalWrite(lamp[1], LOW);
      digitalWrite(lamp[2], LOW);
      digitalWrite(lamp[3], LOW);
      break;
    default:
      //      namaLampu = 0;
      break;
  }
  //  String binNumber = String(namaLampu, BIN);
  //  int binLength = binNumber.length();
  //  for (int i = 0, x = 1; i <= binLength; i++, x += 2) {
  //    if (binNumber[1] == '0') state = LOW;
  //    if (binNumber[i] == '1') state = HIGH;
  //    digitalWrite(lamp[i] + binLength - x, state);
  //    Serial.println(binNumber);
  //    if (namaLampu == 1) {
  //      digitalWrite(lamp[3], LOW);
  //    }
  //  }

}

void blinkLed(){
  unsigned long currentMillisBlink = millis();

  if (currentMillisBlink - previousMillisBlink >= intervalBlink) {
    // save the last time you blinked the LED
    previousMillisBlink = currentMillisBlink;

    // if the LED is off turn it on and vice-versa:
    if (ledStateBlink == LOW) {
      ledStateBlink = HIGH;
      lampu(jumlahKlik);
    } else {
      ledStateBlink = LOW;
      lampu(0);
    }

    // set the LED with the ledState of the variable:
    
  }
}

void warnaLampuRGB(int var) {
  switch (var) {
    case 1:
      RGB_color(125, 0, 0);
      break;
    case 2:
      RGB_color(0, 125, 0);
      break;
    case 3:
      RGB_color(255, 50, 0);
      break;
    default:
      RGB_color(0, 0, 0);
      break;
  }
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(lampuR, red_light_value);
  analogWrite(lampuG, green_light_value);
  analogWrite(lampuB, blue_light_value);
}
