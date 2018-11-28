#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop, reversed)
#include "JoystickDriver.c"



task main()
{
	while (true)
	{
		getJoystickSettings(joystick);

		if (abs(joystick.joy1_y1)> 10)
		{
			motor[motorF] = joystick.joy1_y1;
		}

		else
		{
			motor[motorF] = 0;
		}

		if (abs(joystick.joy1_y2) > 10)
		{
			motor[motorG] = joystick.joy1_y2;
		}

		else
		{
			motor[motorG] = 0;
		}

		if ((joystick.joy2_y2) < -10)
		{
			motor[motorD] = joystick.joy2_y2*-0.4;
			motor[motorE] = joystick.joy2_y2*-0.4;
		}
		else
		{
			motor[motorD] = 0;
			motor[motorE] = 0;
		}

		if ((joystick.joy2_y2) > 10)
		{
			motor[motorD] = joystick.joy2_y2*-0.2;
			motor[motorE] = joystick.joy2_y2*-0.2;
		}
		else
		{
			motor[motorD] = 0;
			motor[motorE] = 0;
		}

		if ((joy1Btn(5)))
		{
			motor(motorA) = 100;
			motor(motorB) = 100;
		}

		else
		{
			motor(motorA) = 0;
			motor(motorB) = 0;
		}

		if ((joy1Btn(6)))
		{
			motor(motorA) = -100;
			motor(motorB) = -100;
		}

		else
		{
			motor(motorA) = 0;
			motor(motorB) = 0;
		}

		if ((joy1Btn(1)))
		{
			motor(motorC) = 100;
		}

		else
		{
			motor(motorC) = 0;
		}
		if ((joy1Btn(4)))
		{
			motor(motorC) = -100;
		}

		else
		{
			motor(motorC) = 0;
		}
	}

}
