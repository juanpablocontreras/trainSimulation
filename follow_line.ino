#include <stdio.h>

#define right_wheel_negative 6
#define right_wheel_positive 5
#define left_wheel_negative 9
#define left_wheel_positive 10
#define right_IF 7
#define left_IF 8

void setup() {
  
   //left wheel
  pinMode(left_wheel_positive, OUTPUT);
  pinMode(left_wheel_negative, OUTPUT);
  
  //right wheel
  pinMode(right_wheel_positive, OUTPUT);
  pinMode(right_wheel_negative, OUTPUT);

  //infrared sensors
  pinMode(left_IF, INPUT);//left sensor
  pinMode(right_IF, INPUT);//right sensor

  //set up initial wheel speed
  digitalWrite(left_wheel_negative, LOW);//left wheel black wire
  digitalWrite(right_wheel_negative, LOW);//right wheel black wire
}

void loop() {
  //make robot follow black line
  
  if(digitalRead(left_IF)==1){
    //line detected by left sensor
    //make right wheel go at higher speed
    analogWrite(right_wheel_positive,191);
    
  }else{
    //line not detected by sensor
    //make right wheel go at lower speed
    analogWrite(right_wheel_positive,64);
  }

  if(digitalRead(right_IF)==1){
    //line detected by right sensor
    //make left wheel go at higher speed
    analogWrite(left_wheel_positive,191);
  }else{
    //make left wheel go at lower speed
    analogWrite(left_wheel_positive,64);
  }

  delay(200);
}
