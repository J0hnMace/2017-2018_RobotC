#pragma config(Sensor, dgtl7,  solenoid,            sensorDigitalOut)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
  while(true)                     // Loop Forever
  {
    if(vexRT[Btn7R] == 1)         // If button 6U (upper right shoulder button) is pressed:
    {
      SensorValue[solenoid] = 1;  // ...activate the solenoid.
    }
    else                          // If button 6U (upper right shoulder button) is  NOT pressed:
    {
      SensorValue[solenoid] = 0;  // ..deactivate the solenoid.
    }
  }
}
