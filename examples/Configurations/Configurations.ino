/*************************************************** 
  This is an example for the Continuum Robot Open source project
  Configurations.ino - This will provide examples of different ways
  the continuum robt can be actuated

  This requires the use of I2C to communicate, 2 pins are required to  
  interface and utilise the Adafruit PWMServo Driver

  Written by Visakan Mathivannan
 ****************************************************/
#include <Continuum.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Continuum robo(0, 3); //Create Robo instance for a 3 segment robot with starting angles at 0 degrees
void setup()
{
  // MAKE SURE TO CHECK BOUNDARIES FOR YOUR SERVOS FOLLOWING THE ADVICE ON ADAFRUIT PWMSERVO LIBRARY
  Serial.begin(9600);
  robo.pwmSetup(); //Enable Adafruit servodriver, you may need to check frequencies, refer to Adafruit library
  //robo.setPWMBounds(int SERVOMIN, int SERVOMAX); //Define the PWM boundary
  robo.setCardinalTuner(0.5); // Define cardinal tuner (0-1)
  robo.setSectionTuner(0);    // Define sectional tuner (0-1)
  delay(1000);
}

void loop()
{
  double x[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Explore changing values here to ensure the servo motors are correctly plugged in
  robo.setAngles(x);                                   // Changes the actual angles

  //Uncomment the different configurations to explore different positions and compare against library pictures

  // Configuration 1 - This utilises the easy pull function define the segment you want to interact with
  // and then the amount the servo should rotate and then the direction that you want to pull tendon towards
  //robo.easyPull(1,  180 ,80);
  //robo.easyPull(2,  45 ,0);
  //robo.easyPull(3,  120 ,200);

  // Configuration 2 - This utilises the increment function define first the segment, then the servo angle and then
  // the cardinal direction
  //robo.pullIncrement(3,90, 1);
  //robo.pullIncrement(1,120,3);

  // Configuration 3
  //robo.pullIncrement(3,90, 1);
  //robo.pullIncrement(2,90, 0);
  //robo.pullIncrement(1,120,3);

  // Configuration 4
  //robo.pullIncrement(3,90, 1);
  //robo.pullIncrement(2,90, 1);
  //robo.pullIncrement(1,90,1);

  // Configuration 5
  //robo.pullIncrement(3,60, 1);
  //robo.pullIncrement(2,80, 3);
  //robo.pullIncrement(1,45,1);

  //robo.startPull();
  while (1)
  {
  }
}