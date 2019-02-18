#include "Robot.h"
#include <iostream>

void Robot::ControlArm(){
    int currentPos = m_encBrazo.Get();
    int dPad = control.GetPOV(); 
    if(dPad == 0){
        m_brazoAngle.Set(-SHOOTSPEED); 
    }
    else if(dPad == 180){
      m_brazoAngle.Set(SHOOTSPEED); 
    }
    else
      m_brazoAngle.Set(0); 
}

void Robot::ControlLauncher(){
  if(m_stick.GetRawButton(1))
    m_brazoShoot.Set(SHOOTSPEED); 
  else if(m_stick.GetRawButton(2))
    m_brazoShoot.Set(-SHOOTSPEED);
  else
    m_brazoShoot.Set(0); 
}

void Robot::RaiseLow(){
  int initDist = m_encElevator.Get(); 
  int currentDist = initDist; 

  if(currentDist > LOWHEIGHT){
    while(currentDist > LOWHEIGHT){
      m_robotDrive.ArcadeDrive(-m_stick.GetY()*MOVESPEED, m_stick.GetX()*TURNSPEED);
      currentDist = m_encElevator.Get(); 
      m_elevator.Set(-0.6);
      frc::Wait(0.005); 
    }
  }
  else {
    while(currentDist < LOWHEIGHT){
      m_robotDrive.ArcadeDrive(-m_stick.GetY()*MOVESPEED, m_stick.GetX()*TURNSPEED);
      currentDist = m_encElevator.Get(); 
      m_elevator.Set(0.8);
      frc::Wait(0.005);  
    }
  }
  m_elevator.Set(0.1);
}

void Robot::RaiseMid(){
  int currentDist = m_encElevator.Get(); 
  if(currentDist > MIDHEIGHT){
    while(currentDist > MIDHEIGHT){
      m_robotDrive.ArcadeDrive(-m_stick.GetY()*MOVESPEED, m_stick.GetX()*TURNSPEED);
      currentDist = m_encElevator.Get(); 
      m_elevator.Set(-0.6);
      frc::Wait(0.005); 
    }
  }
  else {
    while(currentDist < MIDHEIGHT){
      m_robotDrive.ArcadeDrive(-m_stick.GetY()*MOVESPEED, m_stick.GetX()*TURNSPEED);
      currentDist = m_encElevator.Get(); 
      m_elevator.Set(0.8);
      frc::Wait(0.005);  
    }
  }
  m_elevator.Set(0.2);
}
void Robot::RaiseMax(){
  int currentDist = m_encElevator.Get(); 
  if(currentDist > MAXHEIGHT){
    while(currentDist > MAXHEIGHT){
      m_robotDrive.ArcadeDrive(-m_stick.GetY()*MOVESPEED, m_stick.GetX()*TURNSPEED);
      currentDist = m_encElevator.Get(); 
      m_elevator.Set(-0.6);
      frc::Wait(0.005); 
    }
  }
  else {
    while(currentDist < MAXHEIGHT){
      m_robotDrive.ArcadeDrive(-m_stick.GetY()*MOVESPEED, m_stick.GetX()*TURNSPEED);
      currentDist = m_encElevator.Get(); 
      m_elevator.Set(0.8);
      frc::Wait(0.005);  
    }
  }
  m_elevator.Set(0.2);
}

void Robot::ResetElevator(){
  int currentDist = m_encElevator.Get(); 
  while(currentDist > 0){
    m_robotDrive.ArcadeDrive(-m_stick.GetY()*MOVESPEED, m_stick.GetX()*TURNSPEED);
    currentDist = m_encElevator.Get(); 
    m_elevator.Set(-0.6); 
    frc::Wait(0.005); 
  }
  m_elevator.Set(0); 
}

