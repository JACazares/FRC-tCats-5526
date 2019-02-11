#include "Robot.h"
#include <iostream>

void Robot::OneMeterMove(){
    /*int A = enc.Get(); 
    std::cout<<A<<" "; */
}

void Robot::GetSensors(){
    int gyroMeasure = gyro.GetAngle();
    int encDistance = enc.Get(); 
    std::cout<<"Gyro: "<<gyroMeasure<<"\nEncoder: "<<encDistance<<"\n";  
}