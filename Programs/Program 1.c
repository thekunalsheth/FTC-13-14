#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S2,     lightsensor,    sensorLightActive)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_1,     motorJ,        tmotorTetrix, openLoop) reversed)
#pragma config(Motor,  mtr_S1_C4_2,     motorK,        tmotorTetrix, openLoop)
#include "JoystickDriver.c"

//Motor Labels:
//A - NXT Wheels Motors
//B - NXT Wheels Motors
//C - NXT Rack Motor
//D - Right Arm Motor
//E - Flag Motor
//F - Front Left Motor
//G - Rear Left Motor
//H - Front Right Motor
//I - Rear Right Motor
//J - Left Arm Motor
//K - TETRIX Rack Motor

//Joystick Controls:
//Joystick 1 -->>
//Left Axis - Left side motors(F, G)
//Right Axis - Right side motors(H, I)
//D-pad - slow(UP - Forward)(DOWN - Backward)(Left - Point turn left)(RIGHT - Point turn right)
//Buttons -> (3 - Flag motor Clockwise)(1 - Flag motor Anti-Clockwise)(6 - Arm stall)
//Joystick 2 -->>
//Left Axis - Arm control (Joystick press - Arm stall)
//D-pad - (UP - TETRIX rack Forward)(DOWN - TETRIX rack Backward)
//Buttons -> (2 - NXT Wheels inside)(3 - NXT Wheels outside)(1 - NXT rack inside)(4 - NXT rack outside)

task main(){
	while(true){
		getJoystickSettings(joystick);

		//Joystick 1 -->>
		if(abs(joystick.joy1_y1) > 10 && abs(joystick.joy1_y2) < 10 && joystick.joy1_TopHat == -1){
			motor[motorF] = joystick.joy1_y1*-1; //Power = joystick value (Left side wheels control)
			motor[motorG] = joystick.joy1_y1*-1;
		}
		else if(abs(joystick.joy1_y2) > 10 && abs(joystick.joy1_y1) < 10 && joystick.joy1_TopHat == -1){
			motor[motorH] = joystick.joy1_y2*-1; //Power = joystick value (right side wheels control)
			motor[motorI] = joystick.joy1_y2*-1;
		}
		else if(abs(joystick.joy1_y2) > 10 && abs(joystick.joy1_y1) > 10 && joystick.joy1_TopHat == -1){
			motor[motorF] = joystick.joy1_y1*-1; //Power = joystick value
			motor[motorG] = joystick.joy1_y1*-1;
			motor[motorH] = joystick.joy1_y2*-1;
			motor[motorI] = joystick.joy1_y2*-1;
		}
		else if(abs(joystick.joy1_y2) < 10 && abs(joystick.joy1_y1) < 10 && joystick.joy1_TopHat == 0){
			motor(motorF) = -10; //slow speed forward
			motor(motorG) = -10;
			motor(motorH) = -10;
			motor(motorI) = -10;
		}
		else if(abs(joystick.joy1_y2) < 10 && abs(joystick.joy1_y1) < 10 && joystick.joy1_TopHat == 4){
			motor(motorF) = 10; //slow speed back
			motor(motorG) = 10;
			motor(motorH) = 10;
			motor(motorI) = 10;
		}
		else if(abs(joystick.joy1_y2) < 10 && abs(joystick.joy1_y1) < 10 && joystick.joy1_TopHat == 6){
			motor(motorF) = -10; //slow speed left point turn
			motor(motorG) = -10;
			motor(motorH) = 10;
			motor(motorI) = 10;
		}
		else if(abs(joystick.joy1_y2) < 10 && abs(joystick.joy1_y1) < 10 && joystick.joy1_TopHat == 2){
			motor(motorF) = 10; //slow speed right point turn
			motor(motorG) = 10;
			motor(motorH) = -10;
			motor(motorI) = -10;
		}
		else{
			motor(motorF) = 0;
			motor(motorG) = 0;
			motor(motorH) = 0;
			motor(motorI) = 0;
		}

		if(joy1Btn(3) == 1){
			motor(motorE) = 100; //Flag Clockwise
		}
		else if(joy1Btn(1) == 1){
			motor(motorE) = -100; //Flag Anti-Clockwise
		}
		else{
			motor(motorE) = 0;
		}

		//Joystick 2 -->>
		if((joystick.joy2_y1) < -10 && joy2Btn(11) == 0 && joy1Btn(6) == 0){
			motor[motorD] = abs(joystick.joy2_y1)*-0.3; //Arm down
			motor[motorJ] = abs(joystick.joy2_y1)*-0.3; //Arm dwon
		}
		else if((joystick.joy2_y1) > 10 && joy2Btn(11) == 0 && joy1Btn(6) == 0){
			motor[motorD] = joystick.joy2_y1*0.3;	//Arm up
			motor[motorJ] = joystick.joy2_y1*0.3; //Arm up
		}
		else{
			motor[motorD] = 0;
			motor[motorJ] = 0;
		}

		if(joy2Btn(3) == 1){
			motor(motorA) = 100; //NXT Wheels inside
			motor(motorB) = 100;
		}
		else if(joy2Btn(2) == 1){
			motor(motorA) = -100; //NXT Wheels outside
			motor(motorB) = -100;
		}
		else{
			motor[motorA] = 0;
			motor[motorB] = 0;
		}

		if(joy2Btn(4) == 1){
			motor(motorC) = 100; //NXT rack outside
		}
		else if(joy2Btn(1) == 1){
			motor(motorC) = -100; //NXT rack inside
		}
		else{
			motor(motorC) = 0;
		}

		if(joystick.joy2_TopHat == 0){
			motor(motorK) = 100; //TETRIX rack inside
		}
		else if(joystick.joy2_TopHat == 4){
			motor(motorK) = -100; //TETRIX rack outside
		}
		else{
			motor[motorK] = 0;
		}
	}
}
