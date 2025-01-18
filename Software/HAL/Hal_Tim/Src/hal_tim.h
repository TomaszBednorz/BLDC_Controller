#ifndef _HAL_TIM_H_
#define _HAL_TIM_H_

/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include <stdint.h>

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

typedef enum
{
    HAL_TIM_TIMER_1,
    HAL_TIM_TIMER_MAX
}Hal_Tim_Timer_t;

/***********************************************************************************************************
 ********************************************* Exported objects ********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ************************************** Exported function prototypes ***************************************
 ***********************************************************************************************************/

void Hal_Tim_Init(void);
void Hal_Tim_Deinit(void);
void Hal_Tim_SetFreq(Hal_Tim_Timer_t timer, uint32_t freq);
uint32_t Hal_Tim_GetFreq(Hal_Tim_Timer_t timer);
void Hal_Tim_SetPeriodReg(Hal_Tim_Timer_t timer, uint16_t period);
uint16_t Hal_Tim_GetPeriodReg(Hal_Tim_Timer_t timer);
uint16_t Hal_Tim_GetCunterReg(Hal_Tim_Timer_t timer);


#endif  /* _HAL_TIM_H_ */
