#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_1,     motorJ,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorK,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

/* Joystick 1 - Ground Control Movement.
Left Axis - Left Motor F, H
Right Axis - Right Motor G, I
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
			motor[motorH] = joystick.joy1_y1*-0.3;
			motor(motorI) = joystick.joy1_y1*-0.3;
		}

		else if (abs(joystick.joy1_y1) < 10 && joy1Btn(4) == 1)

		{
			motor[motorH] = -20;
			motor[motorI] = -20;
		}

		else	//stop
		{
			motor[motorH] = 0;
			motor[motorI] = 0;
		}


		// Downward Press Right Axis - Joystick 1
		if (abs(joystick.joy1_y2) > 10)
		{
			motor[motorD] = joystick.joy1_y2*-0.3;	//Assign power
			motor[motorE] = joystick.joy1_y2*-0.3;
		}

		else if (abs(joystick.joy1_y1) < 10 && joy1Btn(4) == 1)

		{
			motor[motorD] = -20;
			motor[motorE] = -20;
		}

		else	// stop
		{
			motor[motorD] = 0;
			motor[motorE] = 0;
		}

		// Dwonward Press Right Axis - Joystick 2
		if ((joystick.joy2_y2) < -10)
		{
			motor[motorF] = abs(joystick.joy2_y2)*-0.1; //arm down
			motor[motorG] = abs(joystick.joy2_y2)*-0.1; //arm dwon
		}

		// Upward Press Right Axis - Joystick 2
		else if ((joystick.joy2_y2) > 10)
		{
			motor[motorF] = joystick.joy2_y2*0.3;	// arm up
			motor[motorG] = joystick.joy2_y2*0.3; // arm up
		}

		// stop
		else
		{
			motor[motorF] = 0;	// arm up
			motor[motorG] = 0;
		}


		// Button 6 - Joystick 2 - Grab Block - inward movement
		if (joy2Btn(6)==1)
		{
			motor(motorA) = 100;
			motor(motorB) = 100;
		}



		// Button 5 - Joystick 2 - Release Block - outward movement
		else if(joy2Btn(5) == 1)
		{
			motor(motorA) = -100;
			motor(motorB) = -100;
		}


			else		// stop
		{
			motor(motorA) = 0;
			motor(motorB) = 0;
		}

		if (joy2Btn(1) == 1)
		{
			motor(motorC) = 100;
		}

		else if (joy2Btn(4) == 1)
		{
			motor(motorC) = -100;
		}

		else
		{
			motor(motorC) = 0;
		}

		// Rack Push
		if (joy2Btn(2) == 1)
		{
			motor(motorK) = 100;
		}


		// Rack Pull
		else if (joy2Btn(3)==1)
		{
			motor(motorK) = -100;
		}

		else
		{
			motor(motorK) = 0;
		}

		// Flag Clockwise
		if (joy1Btn(2) == 1)
		{
			motor(motorJ) = 100;
		}


		// Flag Anti-clcokwise
		else if (joy1Btn(3)==1)
		{
			motor(motorJ) = -100;
		}

		else
		{
			motor(motorJ) = 0;
		}











	}

}
