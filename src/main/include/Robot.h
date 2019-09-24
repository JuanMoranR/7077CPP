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
#include <frc/Spark.h>
#include <frc/Compressor.h>
#include <frc/Timer.h>
#include <frc/TimedRobot.h>
 
 
 
 
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
 
 frc::Spark *m_FrontLeft = new frc::Spark(kMotorPortLeftFront);
 frc::Spark *m_RearLeft = new frc::Spark(kMotorPortLeftRear);
 frc::SpeedController *mLeftGroup = new frc::SpeedControllerGroup(*mFrontLeft, *mRearLeft);
 frc::Spark *mFrontRight = new frc::Spark(kMotorPortFrontm_controller);
 frc::Spark *m_RearRight = new frc::Spark(kMotorPortRearm_controller);
 frc::SpeedControllerGroup *mRightGroup = new frc::SpeedControllerGroup(*m_rearm_controller, *m_frontm_controller);

frc::DifferentialDrive m_drive{*mLeftGroup,*mRightGroup};

 frc::DoubleSolenoid *dosSol = new frc::DoubleSolenoid(0,1);
 frc::DoubleSolenoid *tresSol = new frc::DoubleSolenoid (6,7);
 frc::Compressor *compressor;
 
 
  void TurnOffSolenoids (frc::Timer *Timer, frc::DoubleSolenoid *dossol, frc::DoubleSolenoid *tressol);

};
