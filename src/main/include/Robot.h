/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/Joystick.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/PWMVictorSPX.h>
#include <frc/SampleRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "ctre/Phoenix.h"

class Robot : public frc::SampleRobot {
 public:
  Robot();

  void RobotInit() override;
  void Autonomous() override;
  void OperatorControl() override;
  void Test() override;

  void Autonomous1();
  void Autonomous2();
  void Autonomous3();

private:
  //Initialize ports
  int portUpLeft = 0, portLoLeft = 1, portMiLeft = 2, portUpRight = 3, portLoRight = 4, portMiRight = 5;
  int portLeftStick = 0, portRightStick = 1;

  //Initialize Robot Controllers
  WPI_TalonSRX m_upperLeftMotor { portUpLeft };
  WPI_TalonSRX m_lowerLeftMotor { portLoLeft };
  WPI_TalonSRX m_middleLeftMotor { portMiLeft };

  WPI_TalonSRX m_upperRightMotor { portUpRight };
  WPI_TalonSRX m_lowerRightMotor { portLoRight };
  WPI_TalonSRX m_middleRightMotor { portMiRight };

  frc::SpeedControllerGroup m_leftMotor { m_upperLeftMotor, m_middleLeftMotor, m_lowerLeftMotor };
  frc::SpeedControllerGroup m_rightMotor { m_upperRightMotor, m_middleRightMotor, m_lowerRightMotor };

  //Initialize Elevator Controllers
  /*WPI_TalonSRX m_upperElevator { portUpElevator };
  WPI_TalonSRX m_lowerElevator { portLoElevator };

  frc::SpeedControllerGroup m_elevator { m_upperElevator, m_lowerElevator };*/

  //Initialize Climber Controllers
  /*WPI_TalonSRX m_upperClimber { portUpClimber };
  WPI_TalonSRX m_lowerClimber { portLoClimber };

  frc::SpeedControllerGroup m_climber { m_upperClimber, m_lowerClimber };*/

  //Initialize ROBOT_DRIVE
  frc::DifferentialDrive m_robotDrive { m_leftMotor, m_rightMotor };

  //Initialize Joysticks
  frc::Joystick m_leftStick { portLeftStick };
  frc::Joystick m_rightStick { portRightStick };

  //Initialize robot constants;
  const double speedRobot = -0.9, speedTurn = 0.7;
};
