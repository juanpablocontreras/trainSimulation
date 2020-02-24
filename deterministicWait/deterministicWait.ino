//Juan Pablo Contreras
//Implementation of the station deterministic feature

#include <stdio.h>
#include <time.h>

#define right_wheel_negative 6
#define right_wheel_positive 5
#define left_wheel_negative 9
#define left_wheel_positive 10
#define right_IF 7
#define left_IF 8

//defines used for simulation (remove for real project)
#define LOWER 0
#define UPPER 10
#define TRESHOLD 8
#define DIVIDER 2

//functions
void stationWait(int secs);
int getRandomInt();

//variables
int waitTime = 0;

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


  //initialize random to simulate station detected 
  srand(time(0));
}

void loop() {
  
  //make robot follow black line
  //if random number over a treshold, then simulated detecting a station
  
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

  //check for a station and wait
  //if random number is above threshold, simulate station wait
  waitTime = getRandomInt(LOWER,UPPER);
  if(waitTime > TRESHOLD){
    //simulate station
    stationWait(waitTime / DIVIDER);
  }

  delay(50);
}

void stationWait(int secs){
  //stop the wheels and wait for secs number of seconds
  //return from function to loop to restart car and continue following line
  //function does not restart the car

  //stop car
  digitalWrite(left_wheel_negative, LOW);//left wheel black wire
  digitalWrite(right_wheel_negative, LOW);//right wheel black wire
  digitalWrite(left_wheel_positive, LOW);//left wheel black wire
  digitalWrite(right_wheel_positive, LOW);//right wheel black wire

  //wait
  delay(secs*1000);
  
  return;
}

int getRandomInt(int lower, int upper){
  return (rand() % (upper - lower +1)) + lower;
}
