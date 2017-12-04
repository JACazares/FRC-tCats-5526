package org.usfirst.frc.team5526.robot;

import edu.wpi.first.wpilibj.RobotDrive;
import edu.wpi.first.wpilibj.SampleRobot;
import edu.wpi.first.wpilibj.Spark;
import edu.wpi.first.wpilibj.GenericHID;
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj.Victor;
import edu.wpi.first.wpilibj.VictorSP;
import edu.wpi.first.wpilibj.XboxController;
import edu.wpi.first.wpilibj.smartdashboard.SendableChooser;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;

/**
 * This is a demo program showing the use of the RobotDrive class. The
 * SampleRobot class is the base of a robot application that will automatically
 * call your Autonomous and OperatorControl methods at the right time as
 * controlled by the switches on the driver station or the field controls.
 *
 * The VM is configured to automatically run this class, and to call the
 * functions corresponding to each mode, as described in the SampleRobot
 * documentation. If you change the name of this class or the package after
 * creating this project, you must also update the manifest file in the resource
 * directory.
 *
 * WARNING: While it may look like a good choice to use for your code if you're
 * inexperienced, don't. Unless you know what you are doing, complex code will
 * be much more difficult under this system. Use IterativeRobot or Command-Based
 * instead if you're new.
 */
public class Robot extends SampleRobot {
	//------------------------OBJECTS---------------------------
	
		//Basic Drive Object
		RobotDrive Pump;
		
		//Xbox Control Object
		XboxController xboxControl;
		
		//Motor Objects
		VictorSP lowerLeft, upperLeft, lowerRight, upperRight, elevator;
		
		//Timer
		Timer countTime;
	
	//-------------------------------PORTS----------------------
		
		//Joy stick Ports
		static final int portXboxControl = 0;
		
		//Motor Ports
		static final int portLowerLeft = 0;
		static final int portUpperLeft = 1;
		static final int portLowerRight = 2;
		static final int portUpperRight = 3;
		
		//Elevator Ports
		static final int portElevator = 4;

	//---------------------------VARIABLES---------------------- 
		
		//Speed of Different motors
		static final double speedRobot = .4, turnRobot = .7;
		static final double speedElevator = .5;

	//---------------------------CODE---------------------------
		
	public Robot() {
		//Initialize Robot
		Pump = new RobotDrive(portUpperLeft, portLowerLeft, portUpperRight, portLowerRight);
		//Initialize Xbox Control
		xboxControl = new XboxController(portXboxControl);
		//Initialize Controllers
		elevator = new VictorSP(portElevator);
	}
	
	@Override
	public void autonomous() {
		
	}

	@Override
	public void operatorControl() {
		Pump.setSafetyEnabled(true);
		Pump.stopMotor();
		
		while (isOperatorControl() && isEnabled()) {
			Pump.arcadeDrive(xboxControl.getY()*speedRobot, xboxControl.getX()*turnRobot, true);
			
		}
	}

	/**
	 * Runs during test mode
	 */
	@Override
	public void test() {
	}
}
