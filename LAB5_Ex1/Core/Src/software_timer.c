/*
 * software_timer.c
 *
 *  Created on: Nov 2, 2023
 *      Author: mitph
 */

#include "software_timer.h"
#define TICK 	10

int timer0_counter = 0;
int timer0_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;
int timer2_counter = 0;
int timer2_flag = 0;
int timer3_counter = 0;
int timer3_flag = 0;
int timer4_counter = 0;
int timer4_flag = 0;

int timer5_counter = 0;
int timer5_flag = 0;

void setTimer0(int duration){
	timer0_counter = duration/TICK;
	timer0_flag = 0;
}
void setTimer1(int duration){
	timer1_counter = duration/TICK;
	timer1_flag = 0;
}
void setTimer2(int duration){
	timer2_counter = duration/TICK;
	timer2_flag = 0;
}
void setTimer3(int duration){
	timer3_counter = duration/TICK;
	timer3_flag = 0;
}
void setTimer4(int duration){
	timer4_counter = duration/TICK;
	timer4_flag = 0;
}
void setTimer5(int duration){
	timer5_counter = duration/TICK;
	timer5_flag = 0;
}
void timerRun(){
	//Timer0
	if (timer0_counter > 0){
		timer0_counter--;
		if (timer0_counter <= 0) {
			timer0_flag = 1;
		}
	}
	//Timer1
	if (timer1_counter > 0){
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}
	//Timer2
	if (timer2_counter > 0){
		timer2_counter--;
		if (timer2_counter <= 0) {
			timer2_flag = 1;
		}
	}
	//Timer3
	if (timer3_counter > 0){
		timer3_counter--;
		if (timer3_counter <= 0) {
			timer3_flag = 1;
		}
	}
	//Timer4
	if (timer4_counter > 0){
		timer4_counter--;
		if (timer4_counter <= 0) {
			timer4_flag = 1;
		}
	}
	//Timer5
	if (timer5_counter > 0){
		timer5_counter--;
		if (timer5_counter <= 0) {
			timer5_flag = 1;
		}
	}
}

void clearTimer0(){
	timer0_flag = 0;
	timer0_counter = 0;
}
void clearTimer1(){
	timer1_flag = 0;
	timer1_counter = 0;
}
void clearTimer2(){
	timer2_flag = 0;
	timer2_counter = 0;
}
void clearTimer3(){
	timer3_flag = 0;
	timer3_counter = 0;
}
void clearTimer4(){
	timer4_flag = 0;
	timer4_counter = 0;
}
void clearTimer5(){
	timer5_flag = 0;
	timer5_counter = 0;
}
