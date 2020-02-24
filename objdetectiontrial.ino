
// Define pins for ultrasonic and ledpin
int const trigPin = 3;
int const echoPin = 2;
int const ledpin = 13;

#define right_wheel_negative 6 //right wheel black wire

#define right_wheel_positive 5 //right wheel red wire 

#define left_wheel_negative 9 //left wheel black wire

#define left_wheel_positive 10 //left wheel red wire 

void setup()
{Serial.begin(9600);

  //left wheel 

  pinMode(left_wheel_positive, OUTPUT); 
   
  //right wheel 

  pinMode(right_wheel_positive, OUTPUT); 


pinMode(LED_BUILTIN, OUTPUT);//led pin is output 
pinMode(trigPin, OUTPUT); // trig pin will have pulses output
pinMode(echoPin, INPUT); // echo pin should be input to get pulse width

//set up initial wheel speed 

  digitalWrite(left_wheel_positive, 191);//left wheel black wire 

  digitalWrite(right_wheel_positive, 191);//right wheel black wire 

}
void loop()
{
// Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
int duration, distance;

// Output pulse with 1ms width on trigPin

digitalWrite(trigPin, HIGH); // ultrasonic pin 
delay(1);

digitalWrite(trigPin, LOW);
// Measure the pulse input in echo pin
duration = pulseIn(echoPin, HIGH);

// Distance is half the duration devided by 29.1 (from datasheet)
distance = (duration/2) / 29.1;

      Serial.println(distance);// if distance less than 0.3 meter and more than 0 (0 or less means over range)
if (distance <= 30 && distance >= 0) {
// object detected

//stop the vehicle 
analogWrite(left_wheel_positive,0); 
analogWrite(left_wheel_positive,0);

//turn on led on board 

 digitalWrite(LED_BUILTIN, HIGH);

} else {
//no object
// continue moving forward 
analogWrite(left_wheel_positive,0); 
analogWrite(left_wheel_positive,0);

//led showuld not be on 
 digitalWrite(LED_BUILTIN, LOW);
 }
 
// Waiting 60 ms 
//after waitign check gain 
delay(60);
}
