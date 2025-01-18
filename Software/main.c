/*
 * main.c
 *
 *  Created on: 2023 Sep 19 19:38:19
 *  Author: tomek
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include <stdint.h>

#include "app_motor.h"

#include "tmag.h"
// #include "hal_hall.h"

#include "hal_gate_drv.h"
#include "app_6step.h"

#include "hal_adc.h"

#include "hal_tim.h"

// #include "app_hall.h"

#include "int_manager.h"

#include "app_counter.h"

#include "am4096.h"

#include "hal_enc.h"
#include "app_enc.h"

int main(void)
{
	DAVE_STATUS_t status;

	status = DAVE_Init();           /* Initialization of DAVE APPs  */

	if (status != DAVE_STATUS_SUCCESS)
	{
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
		XMC_DEBUG("DAVE APPs initialization failed\n");

		while(1U)
		{

		}
	}

	Am4096_Init();
	// Tmag_Init();

	Hal_GateDrv_Init();
	// Hal_Hall_Init();
	Hal_Tim_Init();

	App_Enc_Init();

	App_Motor_Init();

	while(1U)
	{
		if(App_Counter_GlobalFlag == true)
		{
			App_Counter_GlobalFlag = false;

			if((App_Counter_GlobalTime % HAL_MOTOR_TASK_PERIOD) == HAL_MOTOR_TASK_OFFSET)
			{
				App_Motor_Task();
			}

			if((App_Counter_GlobalTime % HAL_ENC_TASK_PERIOD) == HAL_ENC_TASK_OFFSET)
			{
				Hal_Enc_Task();
			}

			if((App_Counter_GlobalTime % APP_ENC_TASK_PERIOD) == APP_ENC_TASK_OFFSET)
			{
				App_Enc_Task();
			}

			// if((App_Counter_GlobalTime % HAL_HALL_TASK_PERIOD) == HAL_HALL_TASK_OFFSET)
			// {
			// 	Hal_Hall_Task();
			// }

			// if((App_Counter_GlobalTime % APP_HALL_TASK_PERIOD) == APP_HALL_TASK_OFFSET)
			// {
			// 	App_Hall_Task();
			// }
		}
	}
}
