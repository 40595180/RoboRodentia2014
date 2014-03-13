#include <AFMotor.h>
#include <Servo.h>
 
#define OPEN_LEFT 0
#define OPEN_RIGHT 180
#define BLACK 500
#define LEFT 0
#define RIGHT 1
#define Line_f1 0
#define Line_f2 1
#define Line_l1 2
#define Line_r1 3
#define GATE_SERVO 9

AF_DCMotor left_motor(1);
AF_DCMotor right_motor(2);  
AF_DCMotor front_motor(3);
AF_DCMotor back_motor(4);

Servo gate_servo;

void move_forward(AF_DCMotor motor1){
   motor1.setSpeed(255);
   motor1.run(FORWARD);
}

void move_backward(AF_DCMotor motor1){
   motor1.setSpeed(255);
   motor1.run(BACKWARD);
}

void stop_motor(AF_DCMotor motor){
  motor.setSpeed(0);
  motor.run(BRAKE);
}
void reload(){
  
}

void shoot(Servo gate, int side_open){
  gate.write(side_open);
//delay 10000;
  gate.write(180-side_open);
}
void setup() {  
  
   int f1_val = analogRead(Line_f1);
   int f2_val = analogRead(Line_f2);
   int r1_val = analogRead(Line_r1);
   int l1_val = analogRead(Line_l1);
   
   gate_servo.attach(9);
   
   move_forward(left_motor);
   move_forward(right_motor);
   while ((f1_val<BLACK) && (f2_val<BLACK)){
      f1_val = analogRead(Line_f1);
      f2_val = analogRead(Line_f2);
   }
   stop_motor(right_motor);
   stop_motor(left_motor);
}

void loop() {
   AF_DCMotor left_motor(1);
   AF_DCMotor right_motor(2);  
   AF_DCMotor front_motor(3);
   AF_DCMotor back_motor(4);
   
  
   int side = 0;
   
   int f1_val = analogRead(Line_f1);
   int f2_val = analogRead(Line_f2);
   int r1_val = analogRead(Line_r1);
   int l1_val = analogRead(Line_l1);
  
   if((side % 2) == LEFT){ // if it is supposed to go left
      move_backward(front_motor);
      move_backward(back_motor);
      while(l1_val < BLACK){
         l1_val = analogRead(Line_l1);
      }
      stop_motor(front_motor);
      stop_motor(back_motor);
      reload;
      // need a way to straighten out before shooting
      shoot(gate_servo, OPEN_RIGHT);
      side++;
   }else{
      move_forward(front_motor);
      move_forward(back_motor);
      while (r1_val < BLACK){
        f1_val = analogRead(Line_f1);
        f2_val = analogRead(Line_f2);
      }
      stop_motor(front_motor);
      stop_motor(back_motor);
      // need a way to straighten out before shooting
      shoot(gate_servo, OPEN_LEFT);
      reload;
      side++;
 }  
}
