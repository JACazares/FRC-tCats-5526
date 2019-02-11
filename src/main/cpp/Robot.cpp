/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/Timer.h>

Robot::Robot() {
  // Note SmartDashboard is not initialized here, wait until RobotInit() to make
  // SmartDashboard calls
  m_robotDrive.SetExpiration(0.1);
}


void Robot::RobotInit() {
  enc.Reset(); 
  enc.SetDistancePerPulse(1); 
  enc2.Reset(); 
  enc.SetDistancePerPulse(1); 
  gyro.Reset(); 
  gyro.Calibrate(); 
}

void Robot::Autonomous() {
  
}

/**
 * Runs the motors with arcade steering.
 */
void Robot::OperatorControl() {
  //m_robotDrive.SetSafetyEnabled(true);
  while (IsOperatorControl() && IsEnabled()) {
    // Drive with arcade style (use right stick)
    m_robotDrive.ArcadeDrive(m_stick.GetY()*ROBOTSPEED, m_stick.GetX()*TURNSPEED);
    
    //Elevator Control
    if(m_stick.GetRawButton(1)){
      m_elevator.Set(ELEVATORSPEED); 
    }
    else if(m_stick.GetRawButton(2)){
      m_elevator.Set(-ELEVATORSPEED); 
    }
    else {
      m_elevator.Set(0.09); 
    }

    //Control de Tenaza
    if(m_stick.GetRawButton(3))
      m_brazoAngulo.Set(ARMSPEED); 
    else if(m_stick.GetRawButton(4))
      m_brazoAngulo.Set(-ARMSPEED);
    else
      m_brazoAngulo.Set(0); 
    
    //Launch
    if(m_stick.GetRawButton(5))
      m_brazoRuedas.Set(GRABSPEED); 
    else if(m_stick.GetRawButton(6))
      m_brazoRuedas.Set(-GRABSPEED); 
    else
      m_brazoRuedas.Set(0); 
    
    //dataGet
    if(m_rightStick.GetRawButton(1)){
      AimX();  
    }

    if(m_rightStick.GetRawButton(2)){
      GetSensors(); 
    }

    if(m_rightStick.GetRawButton(5)){
      getMeasures(); 
    }

    if(m_rightStick.GetRawButton(3)){
      m_backActuator.Set(-0.5);
    }
    else if(m_rightStick.GetRawButton(4)){
      m_backActuator.Set(0.5);
    }
    else {
      m_backActuator.Set(0);
    }
    frc::Wait(0.005);
  } 
}

/**
 * Runs during test mode
 */
void Robot::Test() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
