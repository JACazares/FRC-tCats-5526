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
  int portUpLeft = 0, portLoLeft = 1, portUpRight = 2, portLoRight = 3;
  int portUpElevator = 4, portLoElevator = 5, portUpClimber = 6, portLoClimber = 7;
  int portLeftStick = 0, portRightStick = 1;

  //Initialize Robot Controllers
  frc::PWMVictorSPX m_upperLeftMotor { portUpLeft };
  frc::PWMVictorSPX m_lowerLeftMotor { portLoLeft };
  frc::PWMVictorSPX m_upperRightMotor { portUpRight };
  frc::PWMVictorSPX m_lowerRightMotor { portLoRight };

  frc::SpeedControllerGroup m_leftMotor { m_upperLeftMotor, m_lowerLeftMotor };
  frc::SpeedControllerGroup m_rightMotor { m_upperRightMotor, m_lowerRightMotor };

  //Initialize Elevator Controllers
  frc::PWMVictorSPX m_upperElevator { portUpElevator };
  frc::PWMVictorSPX m_lowerElevator { portLoElevator };

  frc::SpeedControllerGroup m_elevator { m_upperElevator, m_lowerElevator };

  //Initialize Climber Controllers
  frc::PWMVictorSPX m_upperClimber { portUpClimber };
  frc::PWMVictorSPX m_lowerClimber { portLoClimber };

  frc::SpeedControllerGroup m_climber { m_upperClimber, m_lowerClimber };

  //Initialize ROBOT_DRIVE
  frc::DifferentialDrive m_robotDrive { m_leftMotor, m_rightMotor };

  //Initialize Joysticks
  frc::Joystick m_leftStick { portLeftStick };
  frc::Joystick m_rightStick { portRightStick };

  //Initialize robot constants;
  const double speedRobot = -0.9, speedTurn = 0.7;
};
