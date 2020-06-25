#ifndef Continuum_h
#define Continuum_h
#include "Arduino.h"
#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"

// Define class
class Continuum
{
private:
    // Define Variables
    int _SERVOMIN = 120;    // This is the 'minimum' pulse length count (out of 4096)
    int _SERVOMAX = 500;    // This is the 'maximum' pulse length count (out of 4096)
    int _USMIN = 600;       // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
    int _USMAX = 2400;      // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
    int _SERVO_FREQ = 50;   // Analog servos run at ~50 Hz updates
    double _angleArray[16]; //
    int _sections = 3;              // Number of continuum robot sections
    Adafruit_PWMServoDriver pwm;    // Adafruit PWM Servo driver definition
    double _cardTuner = 0.5;        //
    double _sectionTuner = 0;       //

public:
    // Define methods
    Continuum(int startAngle);                                            //
    Continuum(int startAngle, int sections);                              //
    void pwmSetup();                                                      //
    void setCardinalTuner(double cardTuner);                              //
    void setSectionTuner(double sectionTuner);                            //
    void setPWMBounds(int SERVOMIN, int SERVOMAX);                        //
    double pulseLength(double angle);                                     //
    void startPull();                                                     //
    void pullIncrement(int section, double incrementAngle, int card);     //
    void setAngles(double angleArray[]);                                  //
    void singleServoAdjust(int section, double angle, int card);          //
    double currentAngle(int section, int card);                           // 
    void easyPull(int section, int incrementAngle, int card);             //
};
#endif
