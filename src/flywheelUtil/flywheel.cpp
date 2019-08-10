#include "C:\Users\clove\Desktop\X4\include\main.h"
#include "pidVelSystem.hpp"
#include "C:\Users\clove\Desktop\X4\src\robotUtil\initRobot.hpp"
//Motor* flywheel = new okapi::Motor(7);
double flywheelRatio = 5;
using namespace flywheelLib;
flywheelLib::velPID* pid = new flywheelLib::velPID(0.5, 0.05, 0.055, 0.9);

flywheelLib::emaFilter* rpmFilter = new flywheelLib::emaFilter(0.15);

double motorSlew = 0.7;



double targetRPM = 460*5;

double currentRPM = 0;

double lastPower = 0;

double motorPower = 0;

double error = 0;

float driveVar;
float gain;
long firstCross;
float driveApprox;
double lastError = 0;
float driveZero;
float predictedDrive = 0.9;
void setFlywheelVelocity(double inputRPM){
  targetRPM = inputRPM;
    error = targetRPM - currentRPM;
    lastError = error;
    driveApprox = predictedDrive;
    firstCross = 1;
    driveZero = 0;

}
void flywheelControl()

{
  if(motorPower <= 0) motorPower = 0;


  //currentRPM = rpmFilter->filter(flywheel->getActualVelocity() * flywheelRatio);
  currentRPM = flywheel->getActualVelocity() * flywheelRatio;
  error = targetRPM - currentRPM;
  driveVar = driveVar + (error * gain);

  if((sgn(error) != sgn(lastError))){
    if(firstCross){
      firstCross = 0;
      driveVar = driveApprox;
    } else{

      driveVar = 0.5*(driveVar + driveZero);
    }
    driveZero = driveVar;
  }
  lastError = error;


/*

  motorPower = pid->calculate(targetRPM, currentRPM);



  if(motorPower <= 0) motorPower = 0; //Prevent motor from spinning backward



  //Give the motor a bit of a starting boost

  if(motorPower > lastPower && lastPower < 10 && motorPower > 10) lastPower = 30;



  //This slews the motor by limiting the rate of change of the motor speed

  double increment = motorPower - lastPower;

  if(abs(increment) > motorSlew) motorPower = lastPower + (motorSlew * flywheelLib::sgn(increment));

  lastPower = motorPower;



  flywheel->move(motorPower);



  //std::cout << "RPM: " << currentRPM << " Power: "<< motorPower << " Error: "<< flywheelPID.getError() << "\n";
*/
  //pros::delay(20);

}

void flywheelControlTask(void*param){
  gain = 0.0005;
  while(true){
    setFlywheelVelocity(iRPM);
    flywheelControl();

    motorPower = (driveVar*127) + 0.5;
    flywheel->move(motorPower);
    pros::delay(20);
  }

}
