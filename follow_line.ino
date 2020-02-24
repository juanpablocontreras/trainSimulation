#include <stdio.h>

#define right_wheel_negative 6
#define right_wheel_positive 5
#define left_wheel_negative 9
#define left_wheel_positive 10
#define right_IF 7
#define left_IF 8
#define left_sensor_trig 11
#define left_sensor_echo 12

long left_sensor_duration;  //microseconds
int left_sensor_dist; //cm

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

  //set up initial wheel speed to zero
  digitalWrite(left_wheel_negative, LOW);//left wheel black wire
  digitalWrite(right_wheel_negative, LOW);//right wheel black wire

  // Left Sensor
  pinMode(left_sensor_trig, OUTPUT);
  pinMode(left_sensor_echo, INPUT);

  Serial.begin(9600);

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

  // Clear trig pin
  digitalWrite(left_sensor_trig, LOW);
  delayMicroseconds(2);

  //Set trig pin high for 10 microseconds
  digitalWrite(left_sensor_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(left_sensor_trig, LOW);

  //Read echo
  left_sensor_duration = pulseIn(left_sensor_echo, HIGH);

  //Calculate distance
  left_sensor_dist = left_sensor_duration * 0.034/2 //Speed of sound = 0.034cm/microsecond & wave travels there and back
  
  Serial.println(left_sensor_dist);

  delay(50);
}
