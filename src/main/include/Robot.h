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
 static int kControllerPort;
 static int kMotorPortArm;
 static int kMotorPortClaw;
 static int kGamepadButtonLogitech;
 bool buttonValue;
 
 static int kMotorPortFrontLeft;
 static int kMotorPortRearLeft;
 static int kMotorPortFrontm_controller;
 static int kMotorPortRearm_controller;
 
 enum ControllerButtons : int const {
kGamepadButtonA = 1,         // A button
kGamepadButtonB = 2,         // B button
kGamepadButtonX = 3,         // X button
kGamepadButtonY = 4,         // Y button
kGamepadButtonShoulderL = 5, // Left Bumper
kGamepadButtonShoulderR = 6, // Right Bumper
kGamepadButtonBack = 7,      // Back button
kGamepadButtonStart = 8,     // Start Button
kGamepadButtonLeftStick = 9, 
kGamepadButtonm_controllerStick = 10,
kGamepadButtonMode = -1,
 
 };

    
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
