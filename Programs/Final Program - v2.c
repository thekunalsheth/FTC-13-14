#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop, reversed)
#include "JoystickDriver.c"

/* Joystick 1 - Ground Control Movement.
Left Axis - Left Motor F
Right Axis - Right Motor G
*/

/* JoyStick 2 - Arm Control Movement
Left Axis -
Right Axis - Arm up-down movement
Button 1 - Rack Push / Block Drop
Button 4 - Rack Pull / Block Grab
Button 5 - Block Grab
Button 6 - Block Release
*/

task main()
{
	while (true)
	{
		getJoystickSettings(joystick);

		//Downward Press Left Axis - Joystick 1
		if (abs(joystick.joy1_y1) > 10)
		{
			motor[motorF] = joystick.joy1_y1; // Assign power
		}

		else	//stop
		{
			motor[motorF] = 0;
		}

		// Downward Press Right Axis - Joystick 1
		if (abs(joystick.joy1_y2) > 10)
		{
			motor[motorG] = joystick.joy1_y2;	//Assign power
		}

		else	// stop
		{
			motor[motorG] = 0;
		}

		// Dwonward Press Right Axis - Joystick 2
		if ((joystick.joy2_y2) < -10)
		{
			motor[motorD] = abs(joystick.joy2_y2)*-0.1; //arm down
			motor[motorE] = abs(joystick.joy2_y2)*-0.1; //arm dwon
		}

		// Upward Press Right Axis - Joystick 2
		if ((joystick.joy2_y2) > 10)
		{
			motor[motorD] = joystick.joy2_y2*0.3;	// arm up
			motor[motorE] = joystick.joy2_y2*0.3; // arm up
		}

		// stop
		if((joystick.joy2_y2) > -10 && (joystick.joy2_y2) < 10)
		{
			motor[motorD] = 0;
			motor[motorE] = 0;
		}

		// Button 5 - Joystick 2 - Grab Block - inward movement
		if (joy2Btn(5)==1)
		{
			motor(motorA) = 100;
			motor(motorB) = 100;
		}



		// Button 6 - Joystick 2 - Release Block - outward movement
		else if(joy2Btn(6) == 1)
		{
			motor(motorA) = -100;
			motor(motorB) = -100;
		}

			else		// stop
		{
			motor(motorA) = 0;
			motor(motorB) = 0;
		}


		// Rack Push
		if (joy2Btn(1) == 1)
		{
			motor(motorC) = 100;
		}


		// Rack Pull
		else if (joy2Btn(4)==1)
		{
			motor(motorC) = -100;
		}

		else
		{
			motor(motorC) = 0;
		}
	}

}
