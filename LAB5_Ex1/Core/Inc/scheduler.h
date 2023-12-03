/*
 * scheduler.h
 *
 *  Created on: Dec 1, 2023
 *      Author: mitph
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include "main.h"

typedef struct {
	void (*pTask)(void);		// con trỏ hàm gọi đến Task trong khi tiến hành trừ Delay và Period
	uint32_t 	Delay;
	uint32_t 	Period;
	uint32_t 	RunMe;			// timer_flag: Khi RunMe > 0 giống như timer_flag = 1 -> thực hiện task

	uint32_t  	TaskID;			// Hiện thực tác vụ thêm
}sTasks;


#define SCH_MAX_TASKS	40

void SCH_Init(void);

uint32_t SCH_Add_Task (void (*pFunction)(),
						uint32_t DELAY,
						uint32_t PERIOD);		// setTimer



void SCH_Update(void);		// vai trò giống timerRun : được gọi trong ngắt timer

void SCH_Dispatch_Tasks(void); 		// giống vai trò kiểm tra flag : được gọi trong while(1)

uint32_t SCH_Delete_Task(uint32_t ID);

void update_time();
void timestamp(unsigned char index);

#endif /* INC_SCHEDULER_H_ */
