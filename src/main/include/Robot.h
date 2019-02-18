/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SampleRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <frc/smartdashboard/Smartdashboard.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

#include "ctre/Phoenix.h"
#include <frc/SpeedControllerGroup.h>
#include <frc/Encoder.h>
#include <frc/XboxController.h>



/**
 * This is a demo program showing the use of the DifferentialDrive class. The
 * SampleRobot class is the base of a robot application that will automatically
 * call your Autonomous and OperatorControl methods at the right time as
 * controlled by the switches on the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're
 * inexperienced, don't. Unless you know what you are doing, complex code will
 * be much more difficult under this system. Use TimedRobot or Command-Based
 * instead if you're new.
 */
class Robot : public frc::SampleRobot {
 public:
  Robot();

  void RobotInit() override;
  void Autonomous() override;
  void OperatorControl() override;
  void Test() override;
 
  void ControlArm();  
  void RaiseLow(); 
  void RaiseMid(); 
  void ResetElevator(); 
  void RaiseMax(); 
  void ControlLauncher(); 
  void AimBot(); 
  void GetMeasures(); 

 private:
  //Constants
  const int FIRSTPORT = 0;
  const int SECPORT = 1;
  const double MOVESPEED = 0.9;
  const double TURNSPEED = 0.7;
  const double ELEVATORSPEED = 1;
  const double SHOOTSPEED = 1;
  const double ANGLESPEED = 1;
  const double ONEMETER = 1;
  const int LOWHEIGHT = 19000; 
  const int MIDHEIGHT = 31300;
  const int MAXHEIGHT = 40000; 
  const int POSZERO = 0; 
  const int POSELEVATOR = 70; 
  const int POSDOWN = 180; 


  //XboxController
  frc::XboxController control {1};

  // Robot drive system
  WPI_TalonSRX m_leftUpMotor {1};
  WPI_TalonSRX m_leftDowmMotor {0};
  WPI_TalonSRX m_leftMiddleMotor {11};
  WPI_TalonSRX m_rightUpMotor {10};
  WPI_TalonSRX m_rightDowmMotor {3};
  WPI_TalonSRX m_rightMiddleMotor {8};

  //Elevator
  WPI_TalonSRX m_elevator {9};
  WPI_TalonSRX m_brazoAngle {2};
  WPI_TalonSRX m_brazoShoot {5};

  //Speed Controller Group
  frc::SpeedControllerGroup m_leftMotor {m_leftDowmMotor, m_leftMiddleMotor, m_leftUpMotor};
  frc::SpeedControllerGroup m_rightMotor {m_rightDowmMotor, m_rightMiddleMotor, m_rightUpMotor};

  //Differential Drive
  frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};

  //Encoders
  frc::Encoder m_encElevator {2, 3, true, frc::CounterBase::EncodingType::k4X};
  frc::Encoder m_encBrazo {0, 1, false, frc::CounterBase::EncodingType::k4X};

  //Joysticks
  frc::Joystick m_stick{FIRSTPORT};
  
  //Vision Objects
  std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight"); 

  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
};
