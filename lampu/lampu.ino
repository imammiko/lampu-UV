#include <ezButton.h>
#include <Buzzer.h>
#define lampu1 8
#define lampu2 7
#define lampu3 4
#define lampu4 2
#define lampuMati 0
#define relayPin A0


Buzzer buzzer(11, 12);
ezButton button(A4);
byte banyakLampu = 4;
const byte lamp[] = {2, 3, 4, 5};
byte jumlahKlik = 1;
int state = 0;


int x = 0;
int y=0;

unsigned long previousMillisPressButton = 0;
const long intervalButton = 3000;
// waktu interval
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
const long interval = 2000;
const long interval15 = 920000;
const long interval30 = 1820000;
const long interval160 = 3620000;
const long intervalCustom = 40000;
const long delayAwal = 20000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  button.setDebounceTime(50);
  button.setCountMode(COUNT_FALLING);
  pinMode(relayPin, OUTPUT);
  for (int i = 0; i < banyakLampu; i++) {
    pinMode(lamp[i], OUTPUT);
    digitalWrite(lamp[i], LOW);
  }
  pinMode(A2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  button.loop();

  currentMillis = millis();



  lampu(tombolHitung());



}
int hidupLampu(byte lampu) {

  switch (lampu) {
    case 1:
      previousMillis = millis();
      buzzerSound1();
      while (1) {
        button.loop();
        currentMillis = millis();
        //Serial.println("dua");
        Serial.print(interval15);
        Serial.print("  ");
        Serial.println(currentMillis - previousMillisPressButton);
        if ((currentMillis - previousMillisPressButton >= 20000)) {
          digitalWrite(relayPin, HIGH);
          if (x < 2) {
            buzzerSound2();
            x += 1;
          }
        }
        if ((currentMillis - previousMillisPressButton >= (interval15)) || button.isPressed())
        {
          //return true;
          if (button.isPressed()){
            jumlahKlik -= 1;
          }
          x = 0;
          buzzerSound3();
          digitalWrite(relayPin, LOW);
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
        currentMillis = millis();
        //Serial.println("dua");
        Serial.print(interval15);
        Serial.print("  ");
        Serial.println(currentMillis - previousMillisPressButton);
        if ((currentMillis - previousMillisPressButton >= 20000)) {
          digitalWrite(relayPin, HIGH);
          if (x < 2) {
            buzzerSound2();
            x += 1;
          }
        }
        if ((currentMillis - previousMillisPressButton >= (interval30)) || button.isPressed())
        {
          //return true;
          if (button.isPressed()){
            jumlahKlik -= 1;
          }
          x = 0;
          buzzerSound3();
          digitalWrite(relayPin, LOW);
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
        currentMillis = millis();
        //Serial.println("dua");
        Serial.print(interval30);
        Serial.print("  ");
        Serial.println(currentMillis - previousMillisPressButton);
        if ((currentMillis - previousMillisPressButton >= 20000)) {
          digitalWrite(relayPin, HIGH);
          if (x < 2) {
            buzzerSound2();
            x += 1;
          }
        }
        
        if ((currentMillis - previousMillisPressButton >= (interval160)) || button.isPressed())
        {
          //return true;
          if (button.isPressed()){
            jumlahKlik -= 1;
          }
          x = 0;
          buzzerSound3();
          digitalWrite(relayPin, LOW);
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
        currentMillis = millis();
        //Serial.println("dua");
        Serial.print(intervalCustom);
        Serial.print("  ");
        Serial.println(currentMillis - previousMillisPressButton);
        if ((currentMillis - previousMillisPressButton >= 20000)) {
          digitalWrite(relayPin, HIGH);
          if (x < 2) {
            buzzerSound2();
            x += 1;
          }
        }
        if ((currentMillis - previousMillisPressButton >= (intervalCustom)) || button.isPressed())
        {
          //return true;
          if (button.isPressed()){
            jumlahKlik -= 1;
          }
          x = 0;
          buzzerSound3();
          digitalWrite(relayPin, LOW);
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
  while (!btnState) {
    button.loop();
    btnState = button.getState();
    currentMillis = millis();


    if (currentMillis - previousMillisPressButton >= interval) {
      return true;


    }
    if (!digitalRead(A2)) {
      //digitalWrite(relayPin, HIGH);
    } else {
      digitalWrite(relayPin, LOW);
    }
    Serial.println(currentMillis - previousMillisPressButton);
    // Serial.println("ayo");
    
  } return false;

}

int tombolHitung() {


  if (longPress()) {
    hidupLampu(jumlahKlik);
    //y=1;
    //jumlahKlik -= 1;
    //delay(400);
  }
  

  //goto label;}
  //button.loop();
  //label:
  if (jumlahKlik > 4) jumlahKlik = 1;
 
  if (button.isReleased()) {
    jumlahKlik += 1;
    
  }
   
  
  // Serial.println(jumlahKlik);
  return jumlahKlik;
}




void lampu(int nomor) {
  int namaLampu = 0;
  switch (nomor) {
    case 1:
      namaLampu = lampu1;
      break;
    case 2:
      namaLampu = lampu2;
      break;
    case 3:
      namaLampu = lampu3;
      break;
    case 4:
      namaLampu = lampu4;
      break;
    default:
      namaLampu = 0;
      break;
  }
  String binNumber = String(namaLampu, BIN);
  int binLength = binNumber.length();
  for (int i = 0, x = 1; i <= binLength; i++, x += 2) {
    if (binNumber[1] == '0') state = LOW;
    if (binNumber[i] == '1') state = HIGH;
    digitalWrite(lamp[i] + binLength - x, state);
    //Serial.println(binNumber);
    if (namaLampu == 1) {
      digitalWrite(lamp[3], LOW);
    }
  }

}
