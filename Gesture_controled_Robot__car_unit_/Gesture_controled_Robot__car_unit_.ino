//for Gesture controled Robotic Car  

#include <VirtualWire.h>


int lm1 = 8; //left motor output 1
int lm2 = 9; //left motor output 2
int rm1 = 10; //right motor output 1
int rm2 = 11; //right motor output 2

char d = 0;

void setup() {
  vw_set_rx_pin(12);
  vw_setup(2000);

  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  Serial.begin(38400);
  vw_rx_start();

  sTOP();
}
void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, & buflen)) {

    d = buf[0];

    if (d == 'F') {
      ForWard();
    }
    if (d == 'B') {
      BackWard();
    }

    if (d == 'L') {
            Right();

    }
    if (d == 'R') {
      Left();
    }
    if (d == 'S') {
      sTOP();
    }

  }

}

void ForWard() {
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
}
void BackWard() {
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);
}
void Left() {
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
}
void Right() {
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);
}

void sTOP() {
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);
}
