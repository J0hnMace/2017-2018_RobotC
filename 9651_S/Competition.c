#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Sensor, dgtl1,  solenoid1,            sensorDigitalOut)
#pragma config(Sensor, dgtl2,  solenoid2,            sensorDigitalOut)
#pragma config(Motor,  port2,           frontRight,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           backRight,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port4,           frontLeft,     tmotorNormal, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorNormal, openLoop)
#pragma config(Motor,  port6,           rightArm,     tmotorNormal, openLoop)
#pragma config(Motor,  port7,           leftArm,     tmotorNormal, openLoop)
#pragma config(Motor,  port8,           grabberArm,  tmotorNormal, openLoop)

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
    
	displayLCDString(0, 0, "Primary: ");
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
	displayNextLCDString(mainBattery);
	displayLCDString(1, 0, "Backup: ");
	sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');    //Build the value to be displayed
	displayNextLCDString(backupBattery);

    // Meccanum Tank Controls

    motor[frontRight] = vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4];
    motor[backRight] =  vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch4];
    motor[frontLeft] = vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4];
    motor[backLeft] =  vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4];

  if(vexRT[Btn6D] == 1){
  	 motor[rightArm] = 127;
  	 motor[leftArm] = 127;
	}
	else if(vexRT[Btn6U] == 1){
		 motor[rightArm] = -127;
		 motor[leftArm] = -127;
	}
	else{
		 motor[rightArm] = 0;
		 motor[leftArm] = 0;
	}

	if(vexRT[Btn5D] == 1){
		 motor[grabberArm] = 127;
	}
	else if(vexRT[Btn5U] == 1){
		 motor[grabberArm] = -127;
	}
	else{
		 motor[grabberArm] = 0;
	}

	if(vexRT[Btn8D] == 1) {
		clearLCDLine(0);
		clearLCDLine(1);
	}

	if(vexRT[Btn8U] == 1)         // If button 6U (upper right shoulder button) is pressed:
    {
      SensorValue[solenoid1] = 1;
      SensorValue[solenoid2] = 1; // ...activate the solenoid.
    }
    else                          // If button 6U (upper right shoulder button) is  NOT pressed:
    {
      SensorValue[solenoid1] = 0;
      SensorValue[solenoid2] = 1; // ..deactivate the solenoid.
  	}

}
}
