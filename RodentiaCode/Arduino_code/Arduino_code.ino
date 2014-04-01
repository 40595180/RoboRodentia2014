#include <AFMotor.h>
#include <Servo.h>
 
#define OPEN_LEFT 0
#define OPEN_RIGHT 180
#define BLACK 500
#define LEFT 0
#define RIGHT 1
#define Line_f1 0//outside body of robot, beyond line
#define Line_f2 1 //inside body of robot, behind line
#define Line_l1 2
#define Line_r1 3
#define GATE_SERVO 9
#define FSPEED 255 //The F is for full
#define LEDpin 10

AF_DCMotor left_motor(1);
AF_DCMotor right_motor(2);  
AF_DCMotor front_motor(3);
AF_DCMotor back_motor(4);

Servo gate_servo;

void move_forward(AF_DCMotor motor1){
   motor1.setSpeed(FSPEED);
   motor1.run(FORWARD);
}

void move_backward(AF_DCMotor motor1){
   motor1.setSpeed(FSPEED);
   motor1.run(BACKWARD);
}

void stop_motor(AF_DCMotor motor){
  motor.setSpeed(0);
  motor.run(BRAKE);
}
void reload(){
  digitalWrite(LEDpin, HIGH);//turn LED on
  int pulses = 0;
  while(pulses < 5){
    if(LEDpin != 0) pulses++;
  }
  digitalWrite(LEDpin, LOW);//turn LED off
}
  
  // press button, check if the button has been pressed enough
  
//}

void shoot(Servo gate, int side_open){
  gate.write(side_open); //Opens the selected side
//delay 10000;
  gate.write(180-side_open); //Opens the other Side
}
void setup() {  
  
   Serial.begin(9600);
  
   int f1_val = analogRead(Line_f1);
   int f2_val = analogRead(Line_f2);
   int r1_val = analogRead(Line_r1);
   int l1_val = analogRead(Line_l1);
   
   gate_servo.attach(GATE_SERVO);
   
   Serial.println(f1_val);
   Serial.println(f2_val);
   
    move_forward(left_motor);
    move_forward(right_motor);
    
    if(f2_val > BLACK){
       stop_motor(right_motor);
       stop_motor(left_motor);
       delay (100);
    }
   /*
    while ((f2_val<BLACK)){
      f1_val = analogRead(Line_f1);
      f2_val = analogRead(Line_f2);
      Serial.print(f1_val);
      Serial.print("\t");\ 
      Serial.println(f2_val);
   }
   stop_motor(right_motor);
   stop_motor(left_motor);
   
   Serial.println("Setup Finished");
  */
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
      
      while(l1_val < BLACK){
        
        l1_val = analogRead(Line_l1);
        move_forward(front_motor);
        move_backward(back_motor); 
        
        if(f1_val > BLACK){
           stop_motor(front_motor);
           delay(10);
           move_forward(front_motor);
         }

         if(f2_val > BLACK){
           stop_motor(back_motor);
           delay(10);
           move_backward(back_motor);
         }
         
      }
      stop_motor(front_motor);
      stop_motor(back_motor);
      
//      move_backward(front_motor);
//      move_backward(back_motor);
//
//    stop_motor(front_motor);
//    stop_motor(back_motor);
      shoot(gate_servo, OPEN_RIGHT);
      reload;
      // need a way to straighten out before shooting (maybe)
      
      side++;
   }else{
     
      while(r1_val < BLACK){
        
        r1_val = analogRead(Line_r1);
        move_backward(front_motor);
        move_forward(back_motor); 
        
        if(f1_val > BLACK){
           stop_motor(back_motor);
           delay (10);
           move_forward(back_motor);
         }

         if(f2_val > BLACK){
           stop_motor(front_motor);
           delay (10);
           move_backward(front_motor);
         }
         
      }
      stop_motor(front_motor);
      stop_motor(back_motor);
      
//      move_backward(front_motor);
//      move_backward(back_motor);
//
//    stop_motor(front_motor);
//    stop_motor(back_motor);
      shoot(gate_servo, OPEN_LEFT);
      reload;
      // need a way to straighten out before shooting (maybe)
      
      side++;
   }
}
      
      
      /* Obsolete (probably) code
      move_backward(front_motor);
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
*/
