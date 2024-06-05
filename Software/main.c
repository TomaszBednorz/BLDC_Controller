/*
 * main.c
 *
 *  Created on: 2023 Sep 19 19:38:19
 *  Author: tomek
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include <stdint.h>

#include "tmag.h"
#include "hal_hall.h"

#include "hal_gate_drv.h"
#include "app_bldc.h"

#include "hal_adc.h"

#include "app_hall.h"

#include "int_manager.h"


// #include "DIGITAL_IO/digital_io.h"


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

	Tmag_Init();

	Hal_GateDrv_Init();
	Hal_Hall_Init();


	while(1U)
	{
		if(global_flag == true)
		{
			global_flag = false;

			if((global_time % HAL_HALL_TASK_PERIOD) == HAL_HALL_TASK_OFFSET)
			{
				// Hal_Hall_Task();
			}

			if((global_time % APP_HALL_TASK_PERIOD) == APP_HALL_TASK_OFFSET)
			{
				App_Hall_Task();
			}
		}
	}
}
