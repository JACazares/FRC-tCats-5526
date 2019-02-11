#include "Robot.h"
#include <iostream>

void Robot::getMeasures(){
    double targetX = table->GetNumber("tx", 0.0);
    double targetY = table->GetNumber("ty", 0.0);
    double targetArea = table->GetNumber("ta", 0.0);
    double targetSkew = table->GetNumber("ts", 0.0); 
    
    std::cout<<"targetX: "<<targetX<<"\n";
    std::cout<<"targetY: "<<targetY<<"\n";
    std::cout<<"targetA: "<<targetArea<<"\n";
    std::cout<<"targetS: "<<targetSkew<<"\n"; 
}

void Robot::AimX(){
    double targetX = table->GetNumber("tx", 0.0);
    int direction;   
    while((targetX > 1 || targetX < -1) && m_rightStick.GetRawButton(1)){
        targetX = table->GetNumber("tx", 0.0); 
        if(targetX > 0)
            direction = 1; 
        else
            direction = -1; 
        m_robotDrive.ArcadeDrive(0, direction*0.5);
        std::cout<<"targetX: "<<targetX<<"\n"; 
        frc::Wait(0.005); 
    }
}