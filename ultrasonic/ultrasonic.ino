
#include <NewPing.h>

#define SONAR_NUM 2      // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.

const int trigPin1 = 2;
const int echoPin1 = 4;
const int trigPin2 = 1;
const int echoPin2 = 3;
const int led_1 = 9;
const int led_2 = 10;

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(1, 3, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(2, 4, MAX_DISTANCE)
};

void setup() {
  // initialize serial communication:
  Serial.begin(115200);
}

void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  int i;
  long duration[SONAR_NUM], cm[SONAR_NUM];
  
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(11,HIGH);
  digitalWrite(12, HIGH);
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
   for (i = 0; i < SONAR_NUM; i++) { // Loop through each sensor and display results.
    delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    Serial.print(i);
    Serial.print("=");
    cm[i] = sonar[i].ping_cm();
     
    if(cm[i] > 15) {
      analogWrite(led_1,0);
      analogWrite(led_2,0);
    }
    else if(cm[i]<=15 && cm[i]>7){
      analogWrite(led_1,255);
      analogWrite(led_2,0);
    }
    else if(cm[i]<=7){
      analogWrite(led_1,0);
      analogWrite(led_2,255);
    }
    
    Serial.print(cm[i]);
    Serial.print("cm ");
  }
  Serial.println();
  
  /*pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);

  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin1, HIGH);


  delayMicroseconds(60);

  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  cm1 = microsecondsToCentimeters(duration1);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
   delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(60);
  
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);

  // convert the time into a distance

  cm2 = microsecondsToCentimeters(duration2);
  Serial.print(cm1);
  Serial.print("\t");
  Serial.print(cm2);
  Serial.print("\n");*/
  
  if(cm[i] > 15) {
    analogWrite(led_1,0);
    analogWrite(led_2,0);
  }
  else if(cm[i]<=15 && cm[i]>7){
    analogWrite(led_1,255);
    analogWrite(led_2,0);
  }
  else if(cm[i]<=7){
     analogWrite(led_1,0);
    analogWrite(led_2,255);
  }
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
