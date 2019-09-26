/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "Robot.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>



void Robot::TurnOffSolenoids (frc::Timer *Timer, frc::DoubleSolenoid *FrontSol, frc::DoubleSolenoid *RearSol)
{
 
   if (Timer->HasPeriodPassed(148))
     {
           FrontSol->~DoubleSolenoid(); // Calls the deconstructor of the dossol double solenoid turning it off
           RearSol->~DoubleSolenoid(); // Calls the deconstructor of the tresol double solenoid turning it off
     }
}
 
 
void Robot::RobotInit() {

  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

   frc::DifferentialDrive m_myRobot{*mLeftGroup, *mRightGroup};
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
}
 
 /*
   compressor->SetClosedLoopControl(true);
   compressor->SetClosedLoopControl(false);
   bool enabled = compressor->Enabled();
   bool pressureSwitch = compressor->GetPressureSwitchValue();
   double current = compressor->GetCompressorCurrent();
   */
 
 
void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}
 
void Robot::TeleopInit() {}
 
void Robot::TeleopPeriodic() {

 frc::Timer *timer; // Starts a timer instance for use of the turn off solenoids function

   TurnOffSolenoids(timer,FrontSol,RearSol);

   frc::XboxController* m_controller(0);
   frc::DifferentialDrive m_myRobot{*mLeftGroup, *mRightGroup};
 
   LDTMotor = -m_controller->GetY(frc::GenericHID::kLeftHand);
   RDTMotor =  m_controller->GetY(frc::GenericHID::kRightHand);
  
   //m_myRobot.tankDrive(RDTMotor/1.3, LDTMotor/1.3);
   //m_myRobot.tankDrive(m_controller.getY(), m_controller.getX());

   if (m_controller->GetStartButton())
   {
   compressor->SetClosedLoopControl(true);
   compressor->SetClosedLoopControl(false);
   bool enabled = compressor->Enabled();
   bool pressureSwitch = compressor->GetPressureSwitchValue();
   double current = compressor->GetCompressorCurrent();
   }
   
   if(m_controller->GetAButton())
   {
     FrontSol->Set(frc::DoubleSolenoid::kForward); //
   }
   if(m_controller->GetBButton())
   {
     FrontSol->Set(frc::DoubleSolenoid::kReverse);
   }
   if(m_controller->GetXButton())
   {
     RearSol->Set(frc::DoubleSolenoid::kForward); //
   }
   if(m_controller->GetYButton())
   {
     RearSol->Set(frc::DoubleSolenoid::kReverse); 
   }
   
}
 
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
