/*
 
 ////// MOTORS ///////////////
 
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
 
 
 Joystick 1 - Ground Control Movement
 
 Left analog stick - Left Motor F, G
 Right analog stick - Right Motor H, I
 Button A- Flag Clockwise
 Button Y - Flag anti-clockwise
 
 Joystick 2- Arm and racks
 
 Left analog stick - Main arm movement
 
 ////////////////////////////
 
 
 */

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

#define SLOW 15         //slow FORWARD speed when d-pad UP is pressed
#define SLOWR -15       //slow REVERSE speed when d-pad DOWN is pressed
#define MULTI -0.45     //multiplier for driving motors: increase this to increase robot movement speed
#define ARMMULTI -0.45  //multiplier for arm movement motors: increase this to increase arm movement speed
#define ARMSTALL -10    //arm stall speed

#include "JoystickDriver.c"



void left(int speed) //left motors function

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


task main()

{
    while (true)
        
	{
        getJoystickSettings(joystick);
        
        int topHat = joystick.joy1_TopHat; //d-pad value integer
        
		if (abs(joystick.joy1_y1) > 10)     //if joystick is moved
            
		{
            left(joystick.joy1_y1 * MULTI); //take analog stick value
		}
        
		else
        
        {
            switch(topHat)              //switch for d-pad position
            
            {
                case 2:
					left(SLOW);
					break;
                    
                case 0:
					left (SLOW);
					break;
                    
                case 4:
					left (SLOWR);
					break;
                    
                default:                //stop when neither analog stick nor d-pad moved
					left(0);
					break;
            }
        
        }
        
		if (abs(joystick.joy1_y2) > 10)
            
		{
            right(joystick.joy1_y2 * MULTI);        //take analog stick value
            
		}
        
		else
            
        {
            switch(joystick.joy1_TopHat)        //switch for d-pad position
            
            {
                case 0:
                    right(SLOW);
                    break;
                    
				case 2:
                    right(SLOW);
                    break;
                    
				case 4:
                    right(SLOWR);
                    break;
                    
				default:
                    right(0);
                    break;
            }
        
        }
        
    
        //Main arm
		if      (abs(joystick.joy2_y1) > 10)    {arm(joystick.joy2_y1 * ARMMULTI)}
        else if (joy2Btn(8) == 1)               {arm(ARMSTALL);}
		else                                    {arm(0);}
        
         //Grabber wheels
		if (joy2Btn(3)==1)          {grabber(100);}
		else if(joy2Btn(2) == 1)    {grabber(-100);}
		else                        {grabber(0);}
        
		//Cube Rack
        if      (joy2Btn(4) == 1)   {motor[motorC) = 100;}
		else if (joy2Btn(1) == 1)   {motor[motorC) = -100;}
		else                        {motor[motorC) = 0;}
                                           
		// Main Rack
		if      (joystick.joy2_TopHat == 0) {motor[motorK) = 100;}
        else if (joystick.joy2_TopHat == 4) {motor[motorK) = -100;}
        else                                {motor[motorK) = 0;}
		
        //Flag
		if (joy1Btn(2) == 1)                {motor[motorE) = 100;}
        else if (joy1Btn(4) == 1)           {motor[motorE) = -100;}
        else                                {motor[motorE) = 0;}
		
        
	}
    
}
