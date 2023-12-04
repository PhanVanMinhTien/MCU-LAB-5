/*
 * software_timer.c
 *
 *  Created on: Nov 2, 2023
 *      Author: mitph
 */

#include "fsm.h"
#include <string.h>
#include <stdio.h>

int state = IDLE;
int command_flag = 0;
uint8_t temp = 0;
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint32_t ADC_value = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
char command_data[30];
ADC_HandleTypeDef hadc1;

UART_HandleTypeDef huart2;

void clear_buffer() {
	memset(buffer, 0, sizeof(buffer));
	index_buffer = 0;
}

void command_parser_fsm() {
	switch(state) {
	case IDLE:
		if (temp == '!') {
			state = RECEIVING;
			clear_buffer();
		}
		break;
	case RECEIVING:
		//RST#
		if (buffer[0]=='R' && buffer[1] == 'S' && buffer[2]=='T' && buffer[3]=='#') {
			command_flag = 1;
			HAL_ADC_Start(&hadc1);
			ADC_value = HAL_ADC_GetValue(&hadc1);
			HAL_ADC_Stop(&hadc1);
			state = IDLE;
			clear_buffer();
		}
		//OK#
		else if (buffer[0]=='O' && buffer[1]=='K' && buffer[2]=='#') {
			command_flag = 0;
			state = IDLE;
			clear_buffer();
			timer1_flag = 1;
		}
		else if (temp == '!') {
			clear_buffer();
		}
		break;
	default:
		break;
	}
}
char str[100];
void uart_communication_fsm() {
	if (command_flag == 1) {
		if (timer1_flag == 1) {
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_UART_Transmit(&huart2, "\r\n !ADC=", 10, 1000);
			HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "%d\n", ADC_value), 1000);
			setTimer1(1000);
		}
	}
	else {
	}

}




