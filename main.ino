#include <SoftwareSerial.h>
#include <ArduinoBlue.h>   //I'll be using ArduioBlue library for this project

//Download the ArduinoBlue V2 app an you mobile.
//Connect to the bluetooth device.
//Configure three buttons with ID 0 for Red, 1 for Green and 2 for Blue
#define R 4
#define G 3
#define B 2
#define BL_TX 8
#define BL_RX 7

bool RL = true;
bool GL = true;
bool BL = true;

SoftwareSerial bluetooth(BL_TX, BL_RX);
ArduinoBlue phone(bluetooth);

int button;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(TR_PIN, OUTPUT);
  pinMode(EC_PIN, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {



  button = phone.getButton();

  switch(button){
    case 0: 
    if(RL){
      digitalWrite(R, HIGH);
      RL = false;
    }
    else{
      digitalWrite(R,LOW);
      RL = true;
    }
    break;
    case 1:
    if(GL){
      digitalWrite(G, HIGH);
      GL = false;
    }
    else{
      digitalWrite(G, LOW);
      GL = true;
    }
    break;
    case 2:
    if(BL){
      digitalWrite(B, HIGH);
      BL = false;
    }
    else{
      digitalWrite(B, LOW);
      BL = true;
    }
    break;
  }
}
