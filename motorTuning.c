#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    linefollow,     sensorLineFollower)
#pragma config(Sensor, dgtl1,  sortenc1,       sensorQuadEncoder)
#pragma config(Sensor, dgtl11, startsw,        sensorQuadEncoder)
#pragma config(Motor,  port1,           light,         tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           sortmotor,     tmotorVex393_MC29, PIDControl, encoderPort, dgtl11)
#pragma config(Motor,  port3,           indexservo,    tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true){
		while(SensorValue[startsw]){
			startMotor(sortmotor, -35);
		}
		//startMotor(sortmotor, -50);
		stopMotor(sortmotor);

	}
}
