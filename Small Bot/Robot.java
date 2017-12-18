package org.usfirst.frc.team5526.robot;

import edu.wpi.first.wpilibj.RobotDrive;
import edu.wpi.first.wpilibj.SampleRobot;
import edu.wpi.first.wpilibj.Spark;
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.Timer;
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
	//---------------------------OBJECTS-------------------
		RobotDrive smallBot;
		XboxController xboxControl;
		Spark upperLeft, lowerLeft, upperRight, lowerRight;
	//---------------------------PORTS---------------------
		//CONTROLLER
		static final int portXboxControl = 0;
		//MOTORS
		static final int portUpperRight=0; 
		static final int portLowerRight=1;
		static final int portUpperLeft=2;
		static final int portLowerLeft=3;
	
	//---------------------------VARIABLES---------------------- 
		//Speed of Different motors
		static final double speedRobot = .5, turnRobot = .7;
	
	//---------------------------CODE-----------------------
	public Robot() {
		smallBot= new RobotDrive(portUpperLeft, portLowerLeft, portUpperRight, portLowerRight);
		xboxControl = new XboxController(portXboxControl);
	}

	@Override
	public void robotInit() {
		
	}

	
	@Override
	public void autonomous() {
		
	}

	
	@Override
	public void operatorControl() {
		smallBot.setSafetyEnabled(true);
		smallBot.stopMotor();
		
		while(isOperatorControl() && isEnabled()) {
			smallBot.arcadeDrive(xboxControl.getY()*speedRobot, xboxControl.getX()*turnRobot, true);
		}
	}

	/**
	 * Runs during test mode
	 */
	@Override
	public void test() {
	}
}
