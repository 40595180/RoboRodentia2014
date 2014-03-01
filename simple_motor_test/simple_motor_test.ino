/*
  A simple test for any DC motor we might pick up.
  Designed to run motor at full speed, stopped, full reverse,
  then scaling up and down through all speeds. Motor is to be
  plugged in to digital pin 3.
  last update: 1/28/14
*/


const int
MOTOR_1 = 3,
FULL_FORWARD = 255,
FULL_REVERSE = 0,
STOP = 127;

void setup(){
   Serial.begin(9600);
}

void loop(){
   analogWrite(MOTOR_1,FULL_FORWARD);
   delay(1000);
   analogWrite(MOTOR_1, STOP);
   delay(1000);
   analogWrite(MOTOR_1,FULL_REVERSE);
   delay(1000);
// full forward 1000 ms, stopped 1000 ms, full reverse 1000 ms
   for(int i = FULL_REVERSE; i <= FULL_FORWARD; i++){
    analogWrite(MOTOR_1, i);
    delay(10);
   }
// scale from full reverse to full forward
   for(int i = FULL_FORWARD; i >= FULL_REVERSE; i -= 1){
    analogWrite(MOTOR_1, i);
    delay(10);
   }
// scale from full forward to full reverse
}
