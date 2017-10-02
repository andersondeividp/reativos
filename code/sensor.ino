#include <Ultrasonic.h>

#define B_OUT 10


 Ultrasonic ultrassom(8,9);

long t = 250;
long cMillis = 0;

int state = 0;

int x = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(B_OUT,OUTPUT);
}

void loop() {
  long m = millis();
  long b = m - cMillis;
  long distancia = ultrassom.Ranging(CM);
  t = ((distancia * 100)/3) * x;
  if(state == 0){
    if(cMillis == 0 || b >= t){
      tone(B_OUT,440);
      cMillis = m;
      state = 1;
      x = 1;
    }
  }else if(state == 1){
    if(b >= t){
      noTone(B_OUT);
      cMillis = m;
      state = 0;
      x = 2;
    }
  }
}
