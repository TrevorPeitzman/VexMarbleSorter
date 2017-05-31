#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    linefollow,     sensorLineFollower)
#pragma config(Sensor, dgtl1,  sortenc1,       sensorQuadEncoder)
#pragma config(Sensor, dgtl10, metalsw,        sensorTouch)
#pragma config(Sensor, dgtl11, startsw,        sensorTouch)
#pragma config(Motor,  port1,           light,         tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           sortmotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           indexservo,    tmotorServoStandard, openLoop)
#pragma config(DatalogSeries, 0, "Encoder Pos", Sensors, Sensor, dgtl1, 50)
#pragma config(DatalogSeries, 1, "SortMtr Pwr", Motors, MotorPower, port2, 50)
#pragma config(DatalogSeries, 2, "LineFollw Val", Sensors, Sensor, in1, 50)
#pragma config(DatalogSeries, 3, "Metal SW", Sensors, Sensor, dgtl10, 50)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Sort Motor Speed
int posmotor = 25;
int negmotor = -25;

//Servo Value Constants
int grabmarble = 40;
int dropmarble = -70;
int scanclosed = -100;
int neutral = 0;

//Encoder Position Values
int metalbox = 0;
int woodbox = 261;
int opaquebox = -219;

//Marble Line Follow Value Constants
int clearlo = 2196;
int clearhi = 2779;
//int woodlo = 317;
//int woodhi = 1128;
int opaquelo = 0;
int opaquehi = 1000;

task main()
{
	while(true){

		//Setup
		setServo(indexservo, scanclosed);
		SensorValue[sortenc1] = 0;
		motor[light] = 127;

		if(SensorValue[startsw]){
			while(true){
				setServo(indexservo, grabmarble);
				wait(0.4);
				setServo(indexservo, dropmarble);
				wait(0.4);
				setServo(indexservo, scanclosed);
				wait(4);

				//Begin Marble Type Determnination
				if(SensorValue[metalsw]){
					if(SensorValue[sortenc1] < metalbox){
						repeatUntil(SensorValue[sortenc1] == metalbox){
							startMotor(sortmotor, negmotor);
						}
						stopMotor(sortmotor);
						setServo(indexservo, neutral);
					}
					if(SensorValue[sortenc1] > metalbox){
						repeatUntil(SensorValue[sortenc1] == metalbox){
							startMotor(sortmotor, posmotor);
						}
						stopMotor(sortmotor);
						setServo(indexservo, neutral);
					}
				}
				if(SensorValue[linefollow] >= clearlo && SensorValue[linefollow] <= clearhi){
					if(SensorValue[sortenc1] < woodbox){
						repeatUntil(SensorValue[sortenc1] == woodbox){
							startMotor(sortmotor, negmotor);
						}
						stopMotor(sortmotor);
						setServo(indexservo, neutral);
					}
					if(SensorValue[sortenc1] > woodbox){
						repeatUntil(SensorValue[sortenc1] == woodbox){
							startMotor(sortmotor, posmotor);
						}
						stopMotor(sortmotor);
						setServo(indexservo, neutral);
					}
				}
				if(SensorValue[linefollow] >= opaquelo && SensorValue[linefollow] <= opaquehi){
					if(SensorValue[sortenc1] < opaquebox){
						repeatUntil(SensorValue[sortenc1] == opaquebox){
							startMotor(sortmotor, negmotor);
						}
						stopMotor(sortmotor);
						setServo(indexservo, neutral);
					}
					if(SensorValue[sortenc1] > opaquebox){
						repeatUntil(SensorValue[sortenc1] == opaquebox){
							startMotor(sortmotor, posmotor);
						}
						stopMotor(sortmotor);
						setServo(indexservo, neutral);
					}
				}
			}
		}
	}
}
