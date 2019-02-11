/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/Joystick.h>
#include <frc/SampleRobot.h>

#include <frc/drive/DifferentialDrive.h>

#include <frc/Encoder.h>

#include "ctre/Phoenix.h"
#include <frc/SpeedControllerGroup.h>

#include <frc/smartdashboard/Smartdashboard.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

#include <ADXRS450_Gyro.h>

class Robot : public frc::SampleRobot {
 public:
  Robot();
  void RobotInit() override;
  void Autonomous() override;
  void OperatorControl() override;
  void Test() override;    

  void OneMeterMove(); 
  void getMeasures();
  void GetSensors(); 
  void AimX(); 

 private:
  //Constants
  const double ELEVATORSPEED = 0.6;  
  const double ROBOTSPEED = 1; 
  const double TURNSPEED = 1; 
  const double ARMSPEED = 1; 
  const double GRABSPEED = 1;
  const double MINTURN = 2; 
  const int ONEMETER = 100;  
  
  //Motor Objects
  WPI_TalonSRX m_leftMidMotor{7};
  WPI_TalonSRX m_leftUpMotor{1};
  WPI_TalonSRX m_leftDownMotor{2};
  WPI_TalonSRX m_rightMidMotor{3};
  WPI_TalonSRX m_rightUpMotor{4};
  WPI_TalonSRX m_rightDownMotor{5}; 

  WPI_TalonSRX m_rightActuator{0}; 
  WPI_TalonSRX m_leftActuator{6}; 
  WPI_TalonSRX m_backActuator{9};
  
  //Elevator motor objects
  WPI_TalonSRX m_elevator{10}; 
  WPI_TalonSRX m_brazoAngulo{8}; 
  WPI_TalonSRX m_brazoRuedas{11};

  //Speed Controllers
  frc::SpeedControllerGroup m_rightMotor {m_rightMidMotor, m_rightUpMotor, m_rightDownMotor}; 
  frc::SpeedControllerGroup m_leftMotor {m_leftMidMotor, m_leftUpMotor, m_rightDownMotor}; 
  frc::SpeedControllerGroup m_frontActuators{m_rightActuator, m_leftActuator}; 

  //Robot Drive Object
  frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
  
  //Joysticks
  frc::Joystick m_stick{0};
  frc::Joystick m_rightStick{1}; 

  //Encoder Object
  frc::Encoder enc {0, 1, false, frc::CounterBase::EncodingType::k4X}; 
  frc::Encoder enc2 {2, 3, false, frc::CounterBase::EncodingType::k4X};  
  
  //Vision Objects
  std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight"); 

  //Gyro
  frc::ADXRS450_Gyro gyro {}; 
};