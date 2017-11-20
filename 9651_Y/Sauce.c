#pragma config(Motor,  port2,          grabbyBoi,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           backRight,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           rightArm,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           backLeft,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           leftArm,          tmotorServoContinuousRotation, openLoop)

task main()
{
	while (1==1)
	{
	motor[backRight]=vexRT[Ch2] ;
	motor[backLeft]=vexRT[Ch3] ;
motor[rightArm]=vexRT[Btn8U]*127 ;
motor[leftArm]=vexRT[Btn8U]*127 ;
motor[rightArm]=vexRT[Btn8D]*-127 ;
motor[leftArm]=vexRT[Btn8D]*-127 ;
}
}
