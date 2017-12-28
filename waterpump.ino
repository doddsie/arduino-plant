#include <Time.h>
#include <TimeLib.h>


#include <AFMotor.h>


AF_DCMotor motor(3); // create motor #2, 64KHz pwm
time_t start_time;



#define WATER_TIME_MS 2000
#define WAIT_TIME_S 10

void waterPlants() {
   Serial.print("tick");
  
  Serial.print("tock");
  motor.run(BACKWARD);     // the other way
  delay(WATER_TIME_MS);
  
  motor.run(RELEASE);      // stopped
}

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  motor.setSpeed(255);   
  
  waterPlants();
  start_time = now(); // store the current time in time variable t
    
}

void loop() {
  time_t current_time = now();
  if (current_time - start_time > WAIT_TIME_S) {
    waterPlants();
    start_time = now();
  }
}
