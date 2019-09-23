/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "Robot.h"
#include <iostream>
#include <string>
#include <frc/XboxController.h>
#include <frc/IterativeRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/GenericHID.h>
#include <frc/Joystick.h>
#include <frc/Timer.h>
#include <frc/IterativeRobot.h>
#include <frc/Spark.h>
#include <frc/SpeedController.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Solenoid.h>
#include <frc/Spark.h>
#include <frc/Compressor.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc;
 
// This function is nulled untill a opurtunity to use it arises
 
/*
void Robot::SecondTimer(frc::Timer *timer, float value)
{
 
   this->timer = *timer;
   timer->Reset(); // resets the time back to Zero
 
   if(timer->HasPeriodPassed(value)) // If the value  seconds have passed return a true statement
   {
     timer->Stop(); // Stop the timer
   }
 
}

*/

// Turns off the solenoids two seconds before the match ends
 
void Robot::TurnOffSolenoids (frc::Timer *Timer, frc::DoubleSolenoid *dossol, frc::DoubleSolenoid *tressol)
{
 
   if (Timer->HasPeriodPassed(148))
     {
           dossol->~DoubleSolenoid(); // Calls the deconstructor of the dossol double solenoid turning it off
           tressol->~DoubleSolenoid(); // Calls the deconstructor of the tresol double solenoid turning it off
     }
}
 
 
void Robot::RobotInit() {

   frc::DifferentialDrive m_myRobot{*m_leftGroup, *m_m_controllerGroup};
   frc::XboxController *m_controller = new frc::XboxController(0); //the number is the port in the Driver Station
}
 
/**
* This function is called every robot packet, no matter the mode. Use
* this for items like diagnostics that you want ran during disabled,
* autonomous, teleoperated and test.
*
* <p> This runs after the mode specific periodic functions, but before
* LiveWindow and SmartDashboard integrated updating.
*/
void Robot::RobotPeriodic() {}
 
/**
* This autonomous (along with the chooser code above) shows how to select
* between different autonomous modes using the dashboard. The sendable chooser
* code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
* remove all of the chooser code and uncomment the GetString line to get the
* auto name from the text box below the Gyro.
*
* You can add additional auto modes by adding additional comparisons to the
* if-else structure below with additional strings. If using the SendableChooser
* make sure to add them to the chooser code above as well.
*/
void Robot::AutonomousInit() {
 m_autoSelected = m_chooser.GetSelected();
 // m_autoSelected = SmartDashboard::GetString(
 //     "Auto Selector", kAutoNameDefault);
 std::cout << "Auto selected: " << m_autoSelected << std::endl;
 
 if (m_autoSelected == kAutoNameCustom) {
   // Custom Auto goes here
 } else {
   // Default Auto goes here
 }
 
 /*
   compressor->SetClosedLoopControl(true);
   compressor->SetClosedLoopControl(false);
   bool enabled = compressor->Enabled();
   bool pressureSwitch = compressor->GetPressureSwitchValue();
   double current = compressor->GetCompressorCurrent();
   */
 
}
 
void Robot::AutonomousPeriodic() {
 if (m_autoSelected == kAutoNameCustom) {
   // Custom Auto goes here
 } else {
   // Default Auto goes here
 }
}
 
void Robot::TeleopInit() {}
 
void Robot::TeleopPeriodic() {

 Timer *timer; // Starts a timer instance for use of the turn off solenoids function

   TurnOffSolenoids(timer,dosSol,tresSol);

   frc::XboxController* m_controller(0);
   frc::DifferentialDrive m_myRobot{*m_leftGroup, *m_m_controllerGroup};
 
 //LDTMotor = m_controller.getY(Hand.km_controller);
   //RDTMotor = m_controller.getY(Hand.kLeft);
  
   //m_myRobot.tankDrive(RDTMotor/1.3, LDTMotor/1.3);
   //m_myRobot.tankDrive(m_controller.getY(), m_controller.getX());

   if (m_controller->GetRawButton(kGamepadButtonStart)== true)
   {
   compressor->SetClosedLoopControl(true);
   compressor->SetClosedLoopControl(false);
   bool enabled = compressor->Enabled();
   bool pressureSwitch = compressor->GetPressureSwitchValue();
   double current = compressor->GetCompressorCurrent();
   }
   
   if(m_controller->GetRawButton(kGamepadButtonA)==true)
   {
     dosSol->Set(DoubleSolenoid::kOff); //
   }
   if(m_controller->GetRawButton(kGamepadButtonB)==true)
   {
     dosSol->Set(frc::DoubleSolenoid::kOff);
   }
   if(m_controller->GetRawButton(kGamepadButtonX)==true)
   {
     tresSol->Set(frc::DoubleSolenoid::kOff); //
   }
   if(m_controller->GetRawButton(kGamepadButtonY)==true)
   {
     tresSol->Set(frc::DoubleSolenoid::kOff);
   }
   
   if(m_controller->GetY(GenericHID::kLeftHand) <= -.5 && m_controller->GetY(GenericHID::kLeftHand) != 0 ){
     m_myRobot.TankDrive(-m_controller->GetY(GenericHID::kLeftHand),-m_controller->GetY(GenericHID::kLeftHand));
   } //Front
   else if (m_controller->GetY(GenericHID::kLeftHand) >= .5 && m_controller->GetY (GenericHID::kLeftHand)!= 0){
     m_myRobot.TankDrive( - (m_controller->GetY(GenericHID::kLeftHand)), -( m_controller->GetY(GenericHID::kLeftHand)) );
   } //Back
  
   else if(m_controller->GetX(GenericHID::kLeftHand) <= .5 && m_controller->GetX(GenericHID::kLeftHand) != 0 ){
     m_myRobot.TankDrive(0,-( m_controller->GetX(GenericHID::kLeftHand) ) );
   } //Left
  
   else if (m_controller->GetX(GenericHID::kLeftHand) >= -.5 && m_controller->GetX (GenericHID::kLeftHand)!= 0){
     m_myRobot.TankDrive(m_controller->GetX(GenericHID::kLeftHand), 0);
   } //right
   else {
     m_myRobot.TankDrive(0,0);
   }//Off0
 
}
 
void Robot::TestPeriodic() {}
 
int Robot::kGamepadButtonA = 1;// A button
int Robot::kGamepadButtonB = 2;         // B button
int Robot::kGamepadButtonX = 3;         // X button
int Robot::kGamepadButtonY = 4;         // Y button
int Robot::kGamepadButtonShoulderL = 5; // Left Bumper
int Robot::kGamepadButtonShoulderR = 6; // Right Bumper
int Robot::kGamepadButtonBack = 7;      // Back button
int Robot::kGamepadButtonStart = 8;     // Start Button
int Robot::kGamepadButtonLeftStick = 9; 
int Robot::kGamepadButtonm_controllerStick = 10;
int Robot::kGamepadButtonMode = -1;

 
int Robot::kMotorPortFrontLeft = 1;
int Robot::kMotorPortRearLeft = 2;
int Robot::kMotorPortFrontm_controller = 3;
int Robot::kMotorPortRearm_controller = 4;

 int Robot::kControllerPort = 1;
  int Robot::kMotorPortArm = 9;
  int Robot::kMotorPortClaw;
  int Robot::kGamepadButtonLogitech;

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
