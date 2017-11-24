#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Sensor, dgtl1,  solenoid1,            sensorDigitalOut)
#pragma config(Sensor, dgtl2,  solenoid2,            sensorDigitalOut)
#pragma config(Motor,  port2,           driveRight,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           driveleft,     tmotorNormal, openLoop)
#pragma config(Motor,  port4,           armSegment1,   tmotorNormal, openLoop)
#pragma config(Motor,  port5,           armSegment2,   tmotorNormal, openLoop)
#pragma config(Motor,  port6,           armSegment3,   tmotorNormal, openLoop)
#pragma config(Motor,  port7,           armSegment4,   tmotorNormal, openLoop)


#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)


#include "Vex_Competition_Includes.c"

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

int nBatteryAverage = nAvgBatteryLevel;

task usercontrol() {

  bLCDBacklight = true;                                   
  string mainBattery, backupBattery;
  
  while(1 == 1) {

  	// Speaker
  	bPlaySounds = false;

  	if(vexRT[Btn7U] == 1){
		bPlaySounds = true;
		playSoundFile("car");
		playSoundFile("car.wav");
		while(bSoundActive)
		wait1Msec(1);
	}

    //Tank Controls
	motor[driveRight] = (vexRT[Ch3]);
    motor[driveLeft] = (vexRT[Ch2]);

	if(vexRT[Btn6D] == 1){
 		motor[armSegment1] = 127;
 		motor[armSegment2] = 127;
 		motor[armSegment3] = 127;
 		motor[armSegment4] = 127;
	}
	else if(vexRT[Btn6U] == 1){
		motor[armSegment1] = -127;
		motor[armSegment2] = -127;
		motor[armSegment3] = -127;
		motor[armSegment4] = -127;
	}
	else{
		motor[armSegment1] = 0;
		motor[armSegment2] = 0;
		motor[armSegment3] = 0;
		motor[armSegment4] = 0;
	}

	if(vexRT[Btn8D] == 1) {
		clearLCDLine(0);
		clearLCDLine(1);
	}
	else {
		displayLCDString(0, 0, "Main: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
		displayNextLCDString(mainBattery);
		displayLCDString(1, 0, "Backup: ");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');
		displayNextLCDString(backupBattery);
	}

}

}
