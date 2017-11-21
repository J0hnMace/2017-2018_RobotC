/* pragma statements */
#pragma config(Sensor, in1,    goalHeight, sensorPotentiometer)
#pragma config(Motor,  port2,           frontRight,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           backRight,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           backLeft,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           goal,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           coneLeft,      tmotorServoContinuousRotation, openLoop)

#pragma platform(VEX)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

/* calibrate sensors, deactivate first law  */
void pre_autonomous()
{

}

/* autonomous period */
Task autonomous()
{

}

/* driver control period */
task main()
{
	/* deadzone values */
	int Y1 = 0, X1 = 0, threshold = 30;

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
			motor[frontRight] = - Y1 - X1 - vexRT[Ch4];
    		motor[backRight] = - Y1 - X1 + vexRT[Ch4];
    		motor[frontLeft] = - Y1 + X1 + vexRT[Ch4];
    		motor[backLeft] = - Y1 + X1 - vexRT[Ch4];

    		/* mobile goal lift */
  			if(vexRT[Btn5D] == 1)
  				{motor[goal] = -127;}
  			else if(vexRT[Btn5U] == 1)
  				{motor[goal] = 127;}
    		else
    			{motor[goal] = 0;}

    		/* left side cone lift */
    		if(vexRT[Btn7U] == 1)
    			{motor[coneLeft] = -127;}
    		else if(vexRT[Btn7D] == 1)
    			{motor[coneLeft] = 127;}
    		else
    			{motor[coneLeft] = 0;}
    	}
}
