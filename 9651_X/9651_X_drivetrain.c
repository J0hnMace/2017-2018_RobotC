#pragma config(Sensor, in1,    goalHeight,     sensorPotentiometer)
#pragma config(Motor,  port2,           frontRight,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           backRight,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           goal,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           coneLeft,      tmotorServoContinuousRotation, openLoop)

#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"

/* calibrate sensors */
void pre_auton()
{
	SensorValue[goalHeight] = 0;
}

/* autonomous period */
task autonomous()
{
	/* first law deactivated */
	//playSoundFile("xxxxxx");

	/* LCD display */
	displayLCDPos(0,0);
	displayNextLCDString("9651X");
	displayLCDPos(1,0);
	displayNextLCDString("GonGiveItToYa");

	/* lower goal lift */
	motor[goal] = -127;
		if(SensorValue[goalHeight] > 200)
			{
				motor[goal] = 127;
			}
		else if(SensorValue[goalHeight] < 200)
			{
				motor[goal] = -127;
			}
		else if(SensorValue[goalHeight] == 200)
			{
				motor[goal] = 0;
			}
}

/* driver control period */
task usercontrol()
{
	/* threshold values */
	int Y1 = 0, X1 = 0, threshold = 20;

	while(1 == 1)
	{
		/* create deadzones */
		if(abs(vexRT[AccelY]) > threshold)
			Y1 = vexRT[AccelY]^2/127;
		else
			Y1 = 0;
		if(abs(vexRT[AccelX]) > threshold)
			X1 = vexRT[AccelX]^2/127;
		else
			X1 = 0;

		/* mecanum drive, Y1=forward/reverse, X1=turn */
		motor[frontRight] = - X1 - Y1 - vexRT[Ch4];
		motor[backRight] = - X1 - Y1 + vexRT[Ch4];
		motor[frontLeft] = - X1 + Y1 - vexRT[Ch4];
		motor[backLeft] = - X1 + Y1 + vexRT[Ch4];

		/* mobile goal lift */
		if(vexRT[Btn5D] == 1)
		{
			motor[goal] = -127;
		}
		else if(vexRT[Btn5U] == 1)
		{
			motor[goal] = 127;
		}
		else
		{
			motor[goal] = 0;
		}

		/* left side cone lift */
		if(vexRT[Btn7U] == 1)
		{
			motor[coneLeft] = -127;
		}
		else if(vexRT[Btn7D] == 1)
		{
			motor[coneLeft] = 127;
		}
		else
		{
			motor[coneLeft] = 0;
		}
	}
}
