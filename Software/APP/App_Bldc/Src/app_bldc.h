#ifndef _APP_BLDC_H_
#define _APP_BLDC_H_

/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include <stdint.h>
#include "hal_gate_drv.h"


/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

/* @APP_BLDC_DIR */
#define APP_BLDC_DIR_COUNTERWISE    (-1)
#define APP_BLDC_DIR_CLOCKWISE      (1)

/* BLDC control methods using PWM, @APP_BLDC_METHOD */
#define APP_BLDC_METHOD_HIGH_SIDE_MODULTATION      (1U)
#define APP_BLDC_METHOD_LOW_SIDE_MODULTATION       (2U)
#define APP_BLDC_METHOD_HIGH_SIDE_SYNCHRO          (3U)  // Valid only in apropriate pins configuration
#define APP_BLDC_METHOD_TWO_PHASE_SYNCHRO          (4U)
#define APP_BLDC_METHOD_HIGH_AND_LOW_SIDE_SYNCHRO  (5U)  // Valid only in apropriate pins configuration

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

// speed, dir itp zmiana odswiezania i wypelnienia - struct lub fun - moze w appce

typedef enum
{
    APP_BLDC_STATE_DEFAULT = 0,
    APP_BLDC_STATE_OFF,
    APP_BLDC_STATE_ON
}AppBldc_State_t;

typedef struct 
{
    AppBldc_State_t state;
    uint8_t cycle_time;                             /* ms */
    int8_t dir;                                     /* @APP_BLDC_DIR */
    uint32_t duty_cycle[HAL_GATE_DRV_SIGNAL_MAX];
}App_Bldc_Setup_t;

/***********************************************************************************************************
 ********************************************* Exported objects ********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ************************************** Exported function prototypes ***************************************
 ***********************************************************************************************************/

void App_Bldc_SetState(AppBldc_State_t new_state);
void App_Bldc_UpdateDutyCycle(uint32_t duty_cycle);
void App_Bldc_TimerTask(void);
void App_Hall_UpdateSetup(App_Bldc_Setup_t* setup);

#endif  /* _APP_BLDC_H_ */
