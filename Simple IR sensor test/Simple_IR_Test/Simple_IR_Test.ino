/* Simple test to see what our IR sensors see, plug them in
   to the A0 and A1 pins on the board */

const int
Sensor_1 = 0,
Sensor_2 = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(Sensor_1));
//  Serial.println(analogRead(Sensor_2));
// read the analog values the sensors are returning, 1023
//  means that its seeing black (I think).
}
