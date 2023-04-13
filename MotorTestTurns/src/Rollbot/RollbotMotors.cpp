/* -----------------------------------------------------------------------------
  Author             : Allen
  Check              : Amy
  Version            : V1.0
  Date               : 17/06/2016
  Description        : The smart car follows lines
  Company Website    : http://www.sunfounder.com
   ---------------------------------------------------------------------------*/
/* Include ------------------------------------------------------------------*/
#include "Rollbot.h"

/*********Motor drive constructor**********/
RollbotMotors::RollbotMotors()
{
  pinMode(MOTOR_R_DIR, OUTPUT);
  pinMode(MOTOR_R_PWM, OUTPUT);
  pinMode(MOTOR_L_PWM, OUTPUT);
  pinMode(MOTOR_L_DIR, OUTPUT);
}
/*********Motor drive function***********/
void RollbotMotors::Motordrive(int speed_dir, int speed_left, int speed_right)
{
  MotorSetSpeed(speed_dir,speed_left, speed_right);
}
/*********Motor stop function***********/
void RollbotMotors::Motorstop()
{
  MotorSetSpeed(0, 0, 0);
}
/*********Motor drive function***********/
void RollbotMotors:: MotorSetSpeed(int speed_dir, int speed_left, int speed_right) 
{
	switch(speed_dir)
	{
		//speed_dir = 0 means both motors work well and spin forward
		case 0:
		{
			if (speed_left > 0)
			{
				digitalWrite(MOTOR_L_DIR, LOW);
				analogWrite(MOTOR_L_PWM, speed_left);
			}
			else
			{
				digitalWrite(MOTOR_L_DIR, HIGH);
				analogWrite(MOTOR_L_PWM, (-1)*speed_left);
			}
			if (speed_right > 0)
			{
				digitalWrite(MOTOR_R_DIR, HIGH);
				analogWrite(MOTOR_R_PWM, speed_right);
			}
			else
			{
				digitalWrite(MOTOR_R_DIR, LOW);
				analogWrite(MOTOR_R_PWM, (-1)*speed_right);
			}
		}break;
		//speed_dir = 1 means both motors' rotation are reversed and spin backward 
		case 1:
		{
			if (speed_left > 0)
			{
				digitalWrite(MOTOR_L_DIR, HIGH);
				analogWrite(MOTOR_L_PWM, speed_left);
			}
			else
			{
				digitalWrite(MOTOR_L_DIR, LOW);
				analogWrite(MOTOR_L_PWM, (-1)*speed_left);
			}
			if (speed_right > 0)
			{
				digitalWrite(MOTOR_R_DIR, LOW);
				analogWrite(MOTOR_R_PWM, speed_right);
			}
			else
			{
				digitalWrite(MOTOR_R_DIR, HIGH);
				analogWrite(MOTOR_R_PWM, (-1)*speed_right);
			}
		}break;
		//speed_dir = 2 means the left motor works well and the right one spins reversely 
		case 2:
		{
			if (speed_left > 0)
			{
				digitalWrite(MOTOR_L_DIR, LOW);
				analogWrite(MOTOR_L_PWM, speed_left);
			}
			else
			{
				digitalWrite(MOTOR_L_DIR, HIGH);
				analogWrite(MOTOR_L_PWM, (-1)*speed_left);
			}
			if (speed_right > 0)
			{
				digitalWrite(MOTOR_R_DIR, LOW);
				analogWrite(MOTOR_R_PWM, speed_right);
			}
			else
			{
				digitalWrite(MOTOR_R_DIR, HIGH);
				analogWrite(MOTOR_R_PWM, (-1)*speed_right);
			}
		}break;
		//speed_dir = 3 means the right motor works well and the left one spins reversely 
		case 3:
		{
			if (speed_left > 0)
			{
				digitalWrite(MOTOR_L_DIR, HIGH);
				analogWrite(MOTOR_L_PWM, speed_left);
			}
			else
			{
				digitalWrite(MOTOR_L_DIR, LOW);
				analogWrite(MOTOR_L_PWM, (-1)*speed_left);
			}
			if (speed_right > 0)
			{
				digitalWrite(MOTOR_R_DIR, HIGH);
				analogWrite(MOTOR_R_PWM, speed_right);
			}
			else
			{
				digitalWrite(MOTOR_R_DIR, LOW);
				analogWrite(MOTOR_R_PWM, (-1)*speed_right);
			}
		}break;
	}
}

