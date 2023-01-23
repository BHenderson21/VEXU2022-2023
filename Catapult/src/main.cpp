#include "main.h"
#include "DiffDrive.h"
#include "MinesMotorGroup.h"
#include "globals.h"
#include "pros/misc.h"

using namespace Mines;

MinesMotorGroup leftDriveMotors(leftDriveVector);
MinesMotorGroup rightDriveMotors(rightDriveVector);
MinesMotorGroup catapultMotors(catapultVector);

//globals

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

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
	endgame.set_value(0);
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
	endgame.set_value(0);
catapultMotors.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
	//pros::lcd::print(0,"Start");
	//fire(cat);

	//DiffDrive drive(leftDriveVector, rightDriveVector, intertialSensor);
	//pros::lcd::print(1,"Build Drive");
	// drive.setDrivePIDVals(1, 0, 0);
	// drive.setTurnPIDVals(0,0,0);

	if(skills)
	{
		shield.set_value(1);
		pros::delay(200);
		while(!limitSwitch.get_new_press())
		{
			catapultMotors.move(127);
		}
		catapultMotors.brake();
		shield.set_value(0);

		leftDriveMotors.moveVelocity(100);
		rightDriveMotors.moveVelocity(-100);//straight
		pros::delay(1000);
		leftDriveMotors.moveVelocity(100);//turn
		rightDriveMotors.moveVelocity(100);
		pros::delay(950);
		leftDriveMotors.moveVelocity(100);//rev
		rightDriveMotors.moveVelocity(-100);
		intake.move(127);
		pros::delay(3000);
		leftDriveMotors.moveVelocity(-100);//rev
		rightDriveMotors.moveVelocity(100);
		intake.brake();
		pros::delay(500);
		leftDriveMotors.moveVelocity(100);
		rightDriveMotors.moveVelocity(100);
		pros::delay(950);
		leftDriveMotors.moveVelocity(100);
		rightDriveMotors.moveVelocity(-100);
		pros::delay(1400);
		leftDriveMotors.brake();
		rightDriveMotors.brake();
		topRollerFront.move(127);
		pros::delay(275);
		topRollerFront.brake();
		leftDriveMotors.moveVelocity(-100);
		rightDriveMotors.moveVelocity(100);
		pros::delay(1000);
		leftDriveMotors.moveVelocity(100);
		rightDriveMotors.moveVelocity(100);
		pros::delay(475);
		leftDriveMotors.moveVelocity(-100);
		rightDriveMotors.moveVelocity(100);
		pros::delay(1300);
		leftDriveMotors.moveVelocity(100);
		rightDriveMotors.moveVelocity(100);
		pros::delay(475);
		leftDriveMotors.moveVelocity(-100);
		rightDriveMotors.moveVelocity(100);
		pros::delay(1100);
		leftDriveMotors.brake();
		rightDriveMotors.brake();
		topRoller.move(127);
		pros::delay(275);
		topRoller.brake();
		leftDriveMotors.moveVelocity(100);
		rightDriveMotors.moveVelocity(-100);
		pros::delay(500);
		leftDriveMotors.moveVelocity(-100);
		rightDriveMotors.moveVelocity(-100);
		pros::delay(950);
		leftDriveMotors.moveVelocity(-100);
		rightDriveMotors.moveVelocity(100);
		pros::delay(5300);
		leftDriveMotors.brake();
		rightDriveMotors.brake();
		shield.set_value(1);
		pros::delay(1000);
		while(limitSwitch.get_value() == 1)
		{
			catapultMotors.move(127);
		}
		catapultMotors.brake();
		leftDriveMotors.moveVelocity(100);
		rightDriveMotors.moveVelocity(-100);
		pros::delay(6000);
		leftDriveMotors.moveVelocity(100);
		rightDriveMotors.moveVelocity(100);
		pros::delay(950);
		leftDriveMotors.moveVelocity(100);
		rightDriveMotors.moveVelocity(-100);
		pros::delay(750);
		leftDriveMotors.moveVelocity(100);
		rightDriveMotors.moveVelocity(100);
		pros::delay(2375);
		leftDriveMotors.brake();
		rightDriveMotors.brake();
		
		endgame.set_value(1);
		pros::delay(1000);
		leftDriveMotors.moveVelocity(100);
		rightDriveMotors.moveVelocity(100);
		pros::delay(475);
		leftDriveMotors.brake();
		rightDriveMotors.brake();

		// leftDriveMotors.moveVelocity(-100);
		// rightDriveMotors.moveVelocity(90);
		// pros::delay(1000);
		// leftDriveMotors.brake();
		// rightDriveMotors.brake();
		// for(int i = 0; i < 3; i++)
		// {
		// 	pros::delay(8000);
		// 	leftDriveMotors.moveVelocity(100);
		// 	rightDriveMotors.moveVelocity(-100);
		// 	pros::delay(1000);
		// 	leftDriveMotors.brake();
		// 	rightDriveMotors.brake();
		// 	while(limitSwitch.get_value() == 1)
		// 	{
		// 		catapultMotors.move(127);
		// 	}
		// 	leftDriveMotors.moveVelocity(-100);
		// 	rightDriveMotors.moveVelocity(90);
		// 	pros::delay(1000);
		// 	leftDriveMotors.brake();
		// 	rightDriveMotors.brake();
		// 	while(limitSwitch.get_value() == 0)
		// 	{
		// 		catapultMotors.move(127);
		// }
		}
		
	//}
	else
	{

	}
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


// MotPID::MotPID()
// {

// }

// double MotPID::getPositionPID()
// {
// 	double pos = test_mtr.get_position();
// 	pros::lcd::print(4, "get_position|calls: %d, pos: %f", calls, pos);
// 	calls++;
// 	return pos;
// }

// void MotPID::setVelocityPID(double value)
// {
// 	pros::lcd::print(5, "get_position velocity: %f", value);
// 	test_mtr.move_velocity(value);
// }


void opcontrol()
{
	//pros::Controller master(pros::E_CONTROLLER_MASTER);
	// test_mtr.tare_position();
	// MotPID in;
	// Mines::PID pid(&in);
	// pid.SetPIDConst(0.1, 0.001, 0);
	// pid.StartTask();

	// int loopCount = 0;

	// pid.SetTarget(5000);

	// while(loopCount < 20)
	// {
	// 	pros::lcd::print(6, "main loop: %d", loopCount);
	// 	loopCount++;
	// 	pros::c::delay(100);
	// }

	bool catapultGoal = 1;

	MinesMotorGroup leftDriveMotors(leftDriveVector);
	MinesMotorGroup rightDriveMotors(rightDriveVector);
	MinesMotorGroup catapultMotors(catapultVector);

	catapultMotors.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
	shield.set_value(1);
	pros::delay(500);

	while(true)
	{
		// ***** DRIVE *****
		// 2 stick arcade
		double leftAxisY = MasterController.get_analog(axisLeftY);
		double rightAxisX = MasterController.get_analog(axisRightX);
		double leftVelocity = ((rightAxisX + leftAxisY));
		double rightVelocity = ((rightAxisX - leftAxisY));

		// Tank
		// double leftAxisY = MasterController.get_analog(axisLeftY);
	    // double rightAxisY = MasterController.get_analog(axisRightY);
		// double leftVelocity = ((leftAxisY) * axisPercentBlue);
		// double rightVelocity = ((-rightAxisY) * axisPercentBlue);

		driveLoop(leftDriveMotors, rightDriveMotors, leftVelocity, rightVelocity);
		// ***** END DRIVE *****



		// ***** INTAKE *****
		if(MasterController.get_digital_new_press(buttonR1))
		{
			toggleIntake();
		}

		intakeLoopToggle(MasterController.get_digital(buttonR2), 1);
		//intakeLoopHold(MasterController.get_digital(R1), MasterController.get_digital(R2));
		// ***** END INTAKE *****



		// ***** CATAPULT *****
		if(MasterController.get_digital_new_press(buttonL2))
		{
			if(catapultGoal == 0)
			{
				shield.set_value(1);
				pros::delay(750);
				catapultGoal = 1;
			}

			else
			{
				shield.set_value(1);
				pros::delay(750);
				catapultGoal = 0;
			}
		}

		if(limitSwitch.get_value() != catapultGoal)
		{
			catapultLoop(catapultMotors, 100);
		}
		else
		{
			if(catapultGoal == 1)
			{
			    shield.set_value(0);
			}
			catapultMotors.brake();
		}
		// **** END CATAPULT *****

		if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
		{
			endgame.set_value(true);
		}
		else
		{
			endgame.set_value(false);
		}

		// ***** ROLLER *****
		rollerLoop(topRoller, topRollerFront, red, MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_L1), MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT));
		// ***** END ROLLER *****
	}

	//pid.SetTarget(-120);

	//DO NOT REMOVE: Main should not exit while there are subtasks going on - it will crash the robot
	while(true)
	{
		pros::c::delay(1000);
	}
}
