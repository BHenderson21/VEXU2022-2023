#include "main.h"
#include "DiffDrive.h"
#include "globals.h"
#include "pros/rtos.h"

//globals

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

using namespace Mines;

bool skills = 1;
int redBlue = 0;

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */


void initialize() 
{
	intertialSensor.reset();
	//redBlue = initAutonSide(MasterController);
	//set up PIDs
	//testPID = Mines::PID();	
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() 
{
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() 
{
	//DiffDrive drive(leftDriveMotors, rightDriveMotors, intertialSensor);
	//drive.setDrivePIDVals(0.81, 0, 0.004242);
	//drive.setDrivePIDTol(10);
	//drive.setTurnPIDVals(0.01, 0, 0);
	//drive.setTurnPIDTol(2);

	//drive.driveTiles(1000);
	//drive.turnDegreesAbsolute(720);
	
	if(skills) // Skills route
	{
		//drive.driveTiles(1000); //Tuning PID

		//drive.driveTiles(100);
		// leftDriveMotors.moveVelocity(100);
		// rightDriveMotors.move(100);
		// pros::delay(1500);
		// //drive.turnDegreesAbsolute(90);
		// leftDriveMotors.moveVelocity(100);
		// rightDriveMotors.move(-100);

		//bot moving forward is intake
		//shooting is back of bot


		leftDriveMotors.moveVelocity(-30); //move backward to roller
		rightDriveMotors.moveVelocity(-30);

 		topRoller.move(127); //move roller while applying pressure
		pros::delay(500);
		leftDriveMotors.brake();
		rightDriveMotors.brake();
		topRoller.brake();

		leftDriveMotors.moveVelocity(80); //move forward IN LINE
		rightDriveMotors.moveVelocity(80);
		pros::delay(180);
		leftDriveMotors.brake();
		rightDriveMotors.brake();		
 
		leftDriveMotors.moveVelocity(40); //RIGHT turn towards goal
		rightDriveMotors.moveVelocity(-40);
		pros::delay(850);
		leftDriveMotors.brake();
		rightDriveMotors.brake();

		flywheelsGroup.move(110); //shoot preloads
		pros::delay(2500);
 		for( int i = 0; i < 2; i++)
		{
			push.set_value(1);
			pros::delay(100);
			push.set_value(0);
			pros::delay(1000);
		}
		flywheelsGroup.brake();

 		leftDriveMotors.moveVelocity(50); //LEFT slight turn
		rightDriveMotors.moveVelocity(-50);
		pros::delay(120);
		leftDriveMotors.brake();
		rightDriveMotors.brake();

		intake.move(-127);

		leftDriveMotors.moveVelocity(-30); //move forward to corner disc
		rightDriveMotors.moveVelocity(-30);
		pros::delay(1600);
		leftDriveMotors.brake();
		rightDriveMotors.brake();		

		// leftDriveMotors.moveVelocity(80); //RIGHT towards next disc
		// rightDriveMotors.moveVelocity(-80);
		// pros::delay(500);

		leftDriveMotors.moveVelocity(50); //LEFT slight turn
		rightDriveMotors.moveVelocity(-50);
		pros::delay(632);
		leftDriveMotors.brake();
		rightDriveMotors.brake();

		leftDriveMotors.moveVelocity(-50); //move forward to corner disc
		rightDriveMotors.moveVelocity(-50);
		pros::delay(1200);
		leftDriveMotors.brake();
		rightDriveMotors.brake();
		intake.brake();

		leftDriveMotors.moveVelocity(-50); //LEFT slight turn
		rightDriveMotors.moveVelocity(50);
		pros::delay(632);
		leftDriveMotors.brake();
		rightDriveMotors.brake();

		leftDriveMotors.moveVelocity(-30); //move backward to roller
		rightDriveMotors.moveVelocity(-30);
		pros::delay(1200);
 		topRoller.move(127); //move roller while applying pressure
		pros::delay(200);
		leftDriveMotors.brake();
		rightDriveMotors.brake();
		topRoller.brake();

		leftDriveMotors.moveVelocity(50); //move forward to corner disc
		rightDriveMotors.moveVelocity(50);
		pros::delay(1500);
		leftDriveMotors.brake();
		rightDriveMotors.brake();

		leftDriveMotors.moveVelocity(-50); //LEFT slight turn
		rightDriveMotors.moveVelocity(50);
		pros::delay(316);
		leftDriveMotors.brake();
		rightDriveMotors.brake();

		leftDriveMotors.moveVelocity(-50); //move forward to corner disc
		rightDriveMotors.moveVelocity(-50);
		pros::delay(700);
		leftDriveMotors.brake();
		rightDriveMotors.brake();

		pros::delay(17277);
		launch.set_value(1);
		pros::delay(1000);
		leftDriveMotors.moveVelocity(-50); //LEFT slight turn
		rightDriveMotors.moveVelocity(50);
		pros::delay(530);
		leftDriveMotors.brake();
		rightDriveMotors.brake();
		
		flywheelsGroup.move(113); //shoot preloads
		pros::delay(2500);
			push.set_value(1);
			pros::delay(100);
			push.set_value(0);
		flywheelsGroup.brake();



/* 		leftDriveMotors.moveVelocity(-200); //move forward to next disc
		rightDriveMotors.moveVelocity(-200);
		pros::delay(1000);
		leftDriveMotors.moveVelocity(-100); //turn towards next disc
		rightDriveMotors.moveVelocity(100);
		pros::delay(750);
		intake.brake();
		leftDriveMotors.moveVelocity(-200); //move forward to next disc
		rightDriveMotors.moveVelocity(-200);
		pros::delay(1000);
		topRoller.move(127);
		pros::delay(150);
		topRoller.brake();
		leftDriveMotors.moveVelocity(200); 
		rightDriveMotors.moveVelocity(200);
		pros::delay(100);
		leftDriveMotors.moveVelocity(100); 
		rightDriveMotors.moveVelocity(-100);
		pros::delay(150);
		flywheelsGroup.move(127); //shoot preloads
		pros::delay(1500);
		for( int i = 0; i < 3; i++)
		{
			push.set_value(1);
			push.set_value(0);
			pros::delay(500);
		}
		flywheelsGroup.brake(); //flywheel stop //STEP 2

		leftDriveMotors.moveVelocity(100); 
		rightDriveMotors.moveVelocity(-100);
		pros::delay(700);
		intake.move(127);
		leftDriveMotors.moveVelocity(-200); 
		rightDriveMotors.moveVelocity(-200);
		pros::delay(2000);
		leftDriveMotors.moveVelocity(-100); 
		rightDriveMotors.moveVelocity(100);
		pros::delay(500);
		flywheelsGroup.move(127); //shoot preloads
		pros::delay(1500);
		for( int i = 0; i < 3; i++)
		{
			push.set_value(1);
			push.set_value(0);
			pros::delay(500);
		}
		flywheelsGroup.brake(); //flywheel stop //STEP 2
		leftDriveMotors.moveVelocity(-100); 
		rightDriveMotors.moveVelocity(100);
		pros::delay(500);
		leftDriveMotors.moveVelocity(200); 
		rightDriveMotors.moveVelocity(200);
		pros::delay(2000);
		leftDriveMotors.moveVelocity(100); 
		rightDriveMotors.moveVelocity(-100);
		pros::delay(200);
		launch.set_value(1);  */

		//endgame launch      //STEP 6
		//*/


		//small back
		//roller
		//turn
		//shoot preloads goal 1
		//pick up two along diagnol
		//move to roller
		//roller
		//turn toward goal 2
		//shoot goal 2
		//turn and pick up three
		//turn and shoot goal 2
		
	}
	else // Match auton route
	{
		// small move back
		//roller
		//small move forward
		//aim
		//shoot
		//turn
		//drive w/ intakes
		// pick up 3
		// turn
		//shoot
		//turn
		//drive w/ intakes
		//pick up 3
		// turn
		//shoot
	}

	//Attention! do not remove, bot will crash
	while(true)
	{
		pros::delay(1000);
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol()
{	
	int flywheelPct = 100;

	while(true)
	{		
		// 2 stick arcade
		// double leftAxisY = MasterController.get_analog(axisLeftY);
		// double rightAxisX = MasterController.get_analog(axisRightX);
		// double leftVelocity = ((rightAxisX + leftAxisY) * axisPercentBlue);
		// double rightVelocity = ((rightAxisX - leftAxisY) * axisPercentBlue);

		// 1 stick arcade
		double leftAxisY = MasterController.get_analog(axisLeftY);
		double leftAxisX = MasterController.get_analog(axisLeftX);
		double rightAxisX = MasterController.get_analog(axisRightX);
		double aimVelocityLeft = (rightAxisX) * 0.06;
		double aimVelocityRight = -rightAxisX * 0.06;
		double leftVelocity = ((leftAxisY + leftAxisX + aimVelocityLeft));
		double rightVelocity = ((leftAxisY - leftAxisX + aimVelocityRight));

		// Tank
		// double leftAxisY = MasterController.get_analog(axisLeftY);
	    // double rightAxisY = MasterController.get_analog(axisRightY);
		// double leftVelocity = ((leftAxisY) * axisPercentBlue);
		// double rightVelocity = ((-rightAxisY) * axisPercentBlue);

		if(MasterController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2))
		{
			toggleFlywheels();
		}
		if(MasterController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1))
		{
			toggleIntake();
		}

		if(MasterController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT))
		{
			flywheelPct = 100;
		}
		if(MasterController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN))
		{
			flywheelPct = 75;
		}
		if(MasterController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT))
		{
			flywheelPct = 50;
		}

		driveLoop(leftDriveMotors, rightDriveMotors, leftVelocity, rightVelocity);
		rollerLoop(topRoller, green, MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_X), MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_Y));
		//intakeLoopToggle(MasterController.get_digital(buttonR2), 1);
		flywheelsGroup.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
		intakeLoopHold(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_R1), MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_R2), 100);
		flywheelLoopToggle(flywheelsGroup, flywheelPct);

		if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
		{
			launch.set_value(true);
		}
		else
		{
			launch.set_value(false);
		}

		if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			push.set_value(true);
		}
		else
		{
			push.set_value(false);
		}
	}
}
