package org.usfirst.frc.team5526.robot;

import edu.wpi.first.wpilibj.GenericHID;
import edu.wpi.first.wpilibj.IterativeRobot;
import edu.wpi.first.wpilibj.RobotDrive;
import edu.wpi.first.wpilibj.Spark;
import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj.Victor;
import edu.wpi.first.wpilibj.XboxController;
import edu.wpi.first.wpilibj.smartdashboard.SendableChooser;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;

/**
 * The VM is configured to automatically run this class, and to call the
 * functions corresponding to each mode, as described in the IterativeRobot
 * documentation. If you change the name of this class or the package after
 * creating this project, you must also update the manifest file in the resource
 * directory.
 */
public class Robot extends IterativeRobot {
	final String defaultAuto = "Default";
	final String customAuto = "My Auto";
	String autoSelected;
	SendableChooser<String> chooser = new SendableChooser<>();
	
	//------------------------OBJECTS---------------------------
	
		//Basic Drive Object
		RobotDrive LancerBot;
		
		//Xbox Control Object
		XboxController xboxControl;
			GenericHID.Hand leftStick;
			GenericHID.Hand rightStick;
		
		//Motor Objects
		Victor ninja, brazo, upperLauncher, lowerLauncher;
		Spark pickUp;
		
		//Timer
		Timer countTime;
	
	//-------------------------------PORTS----------------------
		
		//Joy stick Ports
		static final int portXboxControl = 0;
		
		//Motor Ports
		static final int portLeftMotor = 0;
		static final int portRightMotor = 3;
		static final int portUpperLauncher = 6;
		static final int portLowerLauncher = 5;
		static final int portPickUp = 4;
		static final int portNinja = 1;
		static final int portBrazo = 2;

	//---------------------------VARIABLES---------------------- 
	
		//Direction of Different motors
		boolean toggleBrazo = true;
		boolean toggleNinja = true;
		boolean togglePickUp = true;
		boolean togglePickUpInv = true;
		boolean toggleLauncher = true;
		
		//Speed of Different motors
		static final double speedRobot = -.75, turnRobot = -.6;
		static final double speedNinja = .4;
		static final double speedBrazo = .7;
		static final double speedPickUp = .6;
		static final double speedLauncher = .9;
		
	//----------------------------CODE--------------------------
	
	  @Override
		public void robotInit() {
			chooser.addDefault("Default Auto", defaultAuto);
			chooser.addObject("My Auto", customAuto);
			SmartDashboard.putData("Auto choices", chooser);
			//Initialize Joysticks
			xboxControl = new XboxController(portXboxControl);
	
			//Initialize Controllers
			LancerBot = new RobotDrive(portLeftMotor, portRightMotor);
			upperLauncher = new Victor(portUpperLauncher);
			lowerLauncher = new Victor(portLowerLauncher);
			pickUp = new Spark(portPickUp);
			ninja = new Victor(portNinja);
			brazo = new Victor(portBrazo);
			
		}
	
    @Override
		public void autonomousInit() {
			autoSelected = chooser.getSelected();
			// autoSelected = SmartDashboard.getString("Auto Selector",
			// defaultAuto);
			System.out.println("Auto selected: " + autoSelected);
		}
	
	  @Override
		public void autonomousPeriodic() {
			switch (autoSelected) {
			case customAuto:
				// Put custom auto code here
				break;
			case defaultAuto:
			default:
				// Put default auto code here
				break;
			}
		}
	
	  @Override
		public void teleopPeriodic() {
			LancerBot.setSafetyEnabled(true);
			LancerBot.stopMotor();
			
			while(isOperatorControl() && isEnabled()) {
				
				//Drive the robot at speedPercentage, turnPercentage
				LancerBot.arcadeDrive(xboxControl.getY()*speedRobot, xboxControl.getX()*turnRobot, true);
				
				//Control the Ninja by applying pressure to button A
				if(xboxControl.getAButton()) {
					if(toggleNinja) {
						while(xboxControl.getAButton())
							ninja.set(speedNinja);
						toggleNinja = false;
					} else {
						while(xboxControl.getAButton())
							ninja.set(-speedNinja);
						toggleNinja = true;
					}
					ninja.set(0);
				}
				
				//Control Brazo by applying pressure to button B
				if(xboxControl.getBButton()) {
					if(toggleBrazo) {
						brazo.set(speedBrazo);
						while(xboxControl.getBButton())
							continue;
					} else {
						brazo.set(-speedBrazo);
						while(xboxControl.getBButton())
							continue;
					}
					brazo.set(0);
					toggleBrazo = !toggleBrazo;
				}
				
				//Control the Pick Up routine by applying pressure to button X
				if(xboxControl.getXButton()) {
					pickUp.set(-speedPickUp);
					while(xboxControl.getXButton())
						continue;
					pickUp.set(0);
				}
				//Control the Pick Up (Inv) routine by applying pressure to button X
				if(xboxControl.getStickButton()) {
					lowerLauncher.set(-speedLauncher);
					pickUp.set(speedPickUp);
					while(xboxControl.getStickButton())
						continue;
					lowerLauncher.set(0);
					pickUp.set(0);
				}
				
				//Control the Launch Routine by applying pressure to button Y
				if(xboxControl.getYButton()) {
					upperLauncher.set(-speedLauncher);
					lowerLauncher.set(speedLauncher);
					while(xboxControl.getYButton())
						continue;
					upperLauncher.set(0);
					lowerLauncher.set(0);
				}
				
			}
		}

}
