#ifndef _APP_6STEP_H_
#define _APP_6STEP_H_

/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include <stdint.h>
#include "hal_gate_drv.h"


/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

/* @APP_6STEP_DIR */
#define APP_6STEP_DIR_COUNTERWISE    (-1)
#define APP_6STEP_DIR_CLOCKWISE      (1)

/* Motor control methods using PWM, @APP_6STEP_METHOD */
#define APP_6STEP_METHOD_HIGH_SIDE_MODULTATION      (1U)
#define APP_6STEP_METHOD_LOW_SIDE_MODULTATION       (2U)
#define APP_6STEP_METHOD_HIGH_SIDE_SYNCHRO          (3U)  // Valid only in apropriate pins configuration
#define APP_6STEP_METHOD_TWO_PHASE_SYNCHRO          (4U)
#define APP_6STEP_METHOD_HIGH_AND_LOW_SIDE_SYNCHRO  (5U)  // Valid only in apropriate pins configuration

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ********************************************* Exported objects ********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ************************************** Exported function prototypes ***************************************
 ***********************************************************************************************************/

void App_6step_SetDir(int8_t new_dir);
int8_t App_6step_GetDir(void);
void App_6step_SetStepNumber(uint8_t new_step);
uint8_t App_6step_GetActualStepNumber(void);
void App_6step_SetDutyCycle(uint32_t new_duty_cycle);
void App_6step_Enable(void);
void App_6step_Disable(void);
void App_6step_AlgoIteration(void);

#endif  /* _APP_6STEP_H_ */
