#include <SoftwareSerial.h>

SoftwareSerial BTSerial(9, 10);

int relayPin1 = 3;
int relayPin2 = 4;
int relayPin3 = 5;
int relayPin4 = 6;
char val;

bool is1 = false;
bool is2 = false;
bool is3 = false;

void setup() { 
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(relayPin1, OUTPUT); // 릴레이를 출력으로 설정
  pinMode(relayPin2, OUTPUT); // 릴레이를 출력으로 설정
  pinMode(relayPin3, OUTPUT); // 릴레이를 출력으로 설정
}

void loop() {
 val = BTSerial.read();
 if (val == '1') {
  is1 = !is1;
  BTSerial.write("1 input");
  }
 if (val == '2') {
  is2 = !is2;
  BTSerial.write("2 input");
 }
 if (val == '3') {
  is3 = !is3;
  BTSerial.write("3 input");
 } // switching
 
 if(is1) { 
   digitalWrite(relayPin1, HIGH); // 조건 만족하면 1채널 릴레이 ON 
   delay(500);
  } 
 else { 
   digitalWrite(relayPin1, LOW); // 아니면 1채널 릴레이 OFF 
   delay(500);
 }
 if(is2) { 
   digitalWrite(relayPin2, HIGH); 
   delay(500);
  } 
 else { 
   digitalWrite(relayPin2, LOW); 
   delay(500);
 }
 if(is3) { 
   digitalWrite(relayPin3, HIGH); 
   delay(500);
  } 
 else { 
   digitalWrite(relayPin3, LOW); 
   delay(500);
 }//relay
}