#include "../include/controllerUI.h"

int initAutonSide(pros::Controller& Master)
{
    Master.print(0, 0, "A = Red, X = Blue");
	pros::lcd::initialize();
	while(true)
	{
		if(Master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
		{
			Master.clear_line(0);
			pros::delay(500);
			Master.print(0, 0, "RED SELECTED");
			pros::delay(1000);
			Master.clear_line(0);
			return 1;
		}
		else if(Master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X))
		{
			Master.clear_line(0);
			pros::delay(500);
			Master.print(0, 0, "BLUE SELECTED");
			pros::delay(1000);
			Master.clear_line(0);
			return 2;
		}
        pros::delay(20);
	}
}