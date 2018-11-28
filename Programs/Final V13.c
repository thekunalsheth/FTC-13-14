#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S2,     lightsensor,    sensorLightActive)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_1,     motorJ,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorK,        tmotorTetrix, openLoop)

#define SLOW 20         //slow FORWARD speed when d-pad is pressed
#define SLOWR -20       //slow REVERSE speed when d-pad is pressed
#define MULTI -0.2     //multiplier for driving motors: increase this to increase robot movement speed
#define ARMMULTI 0.2  //multiplier for arm movement motors: increase this to increase arm movement speed
#define ARMSTALL 10    //arm stall speed

#include "JoystickDriver.c"



 /*///// MOTORS ///////////////

 A: Cube mechanism motor 1
 B: Cube mechanism motor 2
 C: Cube rack motor
 D: Main arm motor 1
 E: Flag mechanism motor
 F: Left motor 1
 G: Left motor 2
 H: Right motor 1
 I: Right motor 2
 J: Main arm motor 2
 K: Main rack motor

 /////////////////////////////

 /////// CONTROLS ////////////
  
Joystick 1:
  left motors: left analog stick
  right motors: right analog stick
  flag: A/Y
  
Joystick 2:
  Cube Rack: A/Y
  Wheels: B/X
  Arm: right analog stick
  Arm Stall: R2

 ///////////////////////////*/

void left (int speed) //left motors function

{
	motor[motorF] = speed;
	motor[motorG] = speed;
}


void right (int speed) //right motors function

{
	motor[motorH] = speed;
	motor[motorI] = speed;
}

void arm (int speed) //arm movement function

{
    motor[motorD] = speed;
    motor[motorJ] = speed;
}

void grabber (int speed) //grabber wheels function

{
    motor[motorA] = speed;
    motor[motorB] = speed;
}

void analogmove ()

{
  	if(abs(joystick.joy1_y1) > 10) {left(joystick.joy1_y1 * MULTI);}
  	else {left(0);}

  	if(abs(joystick.joy1_y2) > 10){right(joystick.joy1_y2 * MULTI);}
 		else{right(0);}
}


task main()

{
  while (true)
  {
  	getJoystickSettings(joystick);

  	switch(joystick.joy1_TopHat)
  	{

  	case 0:
  	left(SLOWR);
  	right(SLOWR);
  	break;

  	case 2:
  	right(SLOWR);
  	break;

  	case 4:
  	left(SLOW);
  	right(SLOW);
  	break;

  	case 6:
  	left(SLOWR);
  	break;

  	default:
		analogmove();
		break;
  	}

   	if(abs(joystick.joy2_y2) > 10) {arm(joystick.joy2_y2 * ARMMULTI);}
    else if (joy2Btn(8) == 1) {arm(ARMSTALL);}
    else{arm(0);}

    if (joy2Btn(3) == 1) {grabber(100);}
	else if (joy2Btn(2) == 1) {grabber(-100);}
	else {grabber (0);}

	if (joy2Btn(4) == 1) {motor[motorC] = 100;}
	else if (joy2Btn(1) == 1) {motor[motorC] = -100;}
	else {motor[motorC] = 0;}

	if (joystick.joy2_TopHat == 0) {motor[motorK] = 100;}
    else if (joystick.joy2_TopHat == 4) {motor[motorK] = -100;}
    else {motor[motorK] = 0;}
}
}
