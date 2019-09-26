/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
 
#pragma once
 
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
#include <frc/Compressor.h>
#include <frc/Timer.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>

 
 
 
 
class Robot : public frc::IterativeRobot {
public:
 void RobotInit() override;
 void RobotPeriodic() override;
 void AutonomousInit() override;
 void AutonomousPeriodic() override;
 void TeleopInit() override;
 void TeleopPeriodic() override;
 void TestPeriodic() override;
 
 
 //0 is m_controller whilst 1 is left for the drive motors.

 enum Motors
 {
   kMotorPortLeftFront = 1,
   kMotorPortLeftRear = 3,
   kMotorPortRightFront = 8,
   kMotorPortRightRear = 5,
   kMotorPortElevator = 9,
   kControllerPort = 0,
 };
 
 double LDTMotor;
 double RDTMotor;
 
 frc::Spark *mFrontLeft = new frc::Spark(kMotorPortLeftFront);
 frc::Spark *mRearLeft = new frc::Spark(kMotorPortLeftRear);
 frc::SpeedControllerGroup *mLeftGroup = new frc::SpeedControllerGroup(*mRearLeft, *mFrontLeft);
 frc::Spark *mFrontRight = new frc::Spark(kMotorPortRightFront);
 frc::Spark *mRearRight = new frc::Spark(kMotorPortRightRear);
 frc::SpeedControllerGroup *mRightGroup = new frc::SpeedControllerGroup(*mRearRight, *mFrontRight);

 frc::DifferentialDrive mDrive{*mLeftGroup,*mRightGroup};

 frc::DoubleSolenoid *FrontSol = new frc::DoubleSolenoid(0,1);
 frc::DoubleSolenoid *RearSol = new frc::DoubleSolenoid (6,7);
 frc::Compressor *compressor;
 
 
  void TurnOffSolenoids (frc::Timer *Timer, frc::DoubleSolenoid *, frc::DoubleSolenoid *);

  private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

};
