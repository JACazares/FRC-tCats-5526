/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/Timer.h>
#include <frc/smartdashboard/SmartDashboard.h>

Robot::Robot()
{
  m_robotDrive.SetExpiration(0.1);
}

void Robot::RobotInit()
{
}

void Robot::Autonomous()
{
  int autoSelected = 0;
  m_robotDrive.SetSafetyEnabled ( false );

  switch ( autoSelected )
  {
    case 1:
      std::cout << "Autonomous 1 selected\n";
      Autonomous1();
      break;
    case 2:
      std::cout << "Autonomous 2 selected\n";
      Autonomous2();
      break;
    case 3:
      std::cout << "Autonomous 3 selected\n";
      Autonomous3();
      break;
    default:
      std::cout << "Autonomous code not selected\n";
      break;
  }
}

void Robot::OperatorControl()
{
  m_robotDrive.SetSafetyEnabled(true);
  while ( IsOperatorControl() && IsEnabled() )
  {
    m_robotDrive.ArcadeDrive ( m_leftStick.GetY() * speedRobot, m_leftStick.GetX() * speedTurn );
    
    if ( m_leftStick.GetRawButton(1) )
    {
      while ( IsOperatorControl() && IsEnabled() && m_leftStick.GetRawButton(1) )
      {
        m_elevator.Set ( 1 );
        m_robotDrive.ArcadeDrive ( m_leftStick.GetY() * speedRobot, m_leftStick.GetX() * speedTurn );
      }
    }

    if ( m_leftStick.GetRawButton(2) )
    {
      while ( IsOperatorControl() && IsEnabled() && m_leftStick.GetRawButton(2) )
      {
        m_elevator.Set ( -1 );
        m_robotDrive.ArcadeDrive ( m_leftStick.GetY() * speedRobot, m_leftStick.GetX() * speedTurn );
      }
    }

    if ( m_leftStick.GetRawButton(3) )
    {
      while ( IsOperatorControl() && IsEnabled() && m_leftStick.GetRawButton(3) )
      {
        m_climber.Set ( .3 );
        m_robotDrive.ArcadeDrive ( m_leftStick.GetY() * speedRobot, m_leftStick.GetX() * speedTurn );
      }
    }

    if ( m_leftStick.GetRawButton(4) )
    {
      while ( IsOperatorControl() && IsEnabled() && m_leftStick.GetRawButton(4) )
      {
        m_climber.Set ( -.3 );
        m_robotDrive.ArcadeDrive ( m_leftStick.GetY() * speedRobot, m_leftStick.GetX() * speedTurn );
      }
    }
    
    frc::Wait(0.005);
  }
}

void Robot::Test() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
