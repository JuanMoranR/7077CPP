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
 
 
 
 
class Robot : public frc::TimedRobot {
public:
 void RobotInit() override;
 void RobotPeriodic() override;
 void AutonomousInit() override;
 void AutonomousPeriodic() override;
 void TeleopInit() override;
 void TeleopPeriodic() override;
 void TestPeriodic() override;
 
 
 //0 is m_controller whilst 1 is left for the drive motors.
static int kControllerPort;
 static int kMotorPortArm;
 static int kMotorPortClaw;
 static int kGamepadButtonLogitech;
 bool buttonValue;
 
 static int kMotorPortFrontLeft;
 static int kMotorPortRearLeft;
 static int kMotorPortFrontm_controller;
 static int kMotorPortRearm_controller;
 
static int kGamepadButtonA;         // A button
static int kGamepadButtonB;         // B button
static int kGamepadButtonX;         // X button
static int kGamepadButtonY;         // Y button
static int kGamepadButtonShoulderL; // Left Bumper
static int kGamepadButtonShoulderR; // Right Bumper
static int kGamepadButtonBack;     // Back button
static int kGamepadButtonStart;     // Start Button
static int kGamepadButtonLeftStick; 
static int kGamepadButtonm_controllerStick;
static int kGamepadButtonMode;
 


    
 double LDTMotor;
 double RDTMotor;
 
 frc::Spark *m_frontLeft = new frc::Spark(kMotorPortFrontLeft);
 frc::Spark *m_rearLeft = new frc::Spark(kMotorPortRearLeft);
 frc::SpeedController *m_leftGroup = new frc::SpeedControllerGroup(*m_rearLeft, *m_frontLeft);
 frc::Spark *m_frontm_controller = new frc::Spark(kMotorPortFrontm_controller);
 frc::Spark *m_rearm_controller = new frc::Spark(kMotorPortRearm_controller);
 frc::SpeedControllerGroup *m_m_controllerGroup = new frc::SpeedControllerGroup(*m_rearm_controller, *m_frontm_controller);
 frc::Spark *m_arm = new frc::Spark(kMotorPortArm);
 frc::DoubleSolenoid *dosSol = new frc::DoubleSolenoid(0,1);
 frc::DoubleSolenoid *tresSol = new frc::DoubleSolenoid (6,7);
 frc::Compressor *compressor;
 
 
 
private:
 
 frc::SendableChooser<std::string> m_chooser;
 const std::string kAutoNameDefault = "Default";
 const std::string kAutoNameCustom = "My Auto";
 std::string m_autoSelected;
   // void SecondTimer(); This function is null until it is needed


  void TurnOffSolenoids (frc::Timer *Timer, frc::DoubleSolenoid *dossol, frc::DoubleSolenoid *tressol);

};
