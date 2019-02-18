#include "Robot.h"
#include <iostream>

void Robot::GetMeasures(){
    double targetX = table->GetNumber("tx", 0.0);
    double targetY = table->GetNumber("ty", 0.0);
    double targetArea = table->GetNumber("ta", 0.0);
    double targetSkew = table->GetNumber("ts", 0.0); 
    
    std::cout<<"targetX: "<<targetX<<"\n";
    std::cout<<"targetY: "<<targetY<<"\n";
    std::cout<<"targetA: "<<targetArea<<"\n";
    std::cout<<"targetS: "<<targetSkew<<"\n"; 
}

void Robot::AimBot(){
    double targetX = table->GetNumber("tx", 0.0);
    double targetArea = table->GetNumber("ta", 0.0); 
    double targetY = table ->GetNumber("ty", 0.0);
    int direction;   
    while(m_stick.GetRawButton(3) && targetY < 13){
        targetX = table->GetNumber("tx", 0.0);
        targetY = table->GetNumber("ty", 0.0);
        std::cout<<targetY<<"\n"; 
        if(targetX > 2){
            direction = 1; 
        }
        else if(targetX < -2){
            direction = -1; 
        }
        else
            direction = 0; 
        m_robotDrive.ArcadeDrive(0.5, direction *0.5);
        frc::Wait(0.005); 
    }
    m_robotDrive.ArcadeDrive(0, 0); 
}