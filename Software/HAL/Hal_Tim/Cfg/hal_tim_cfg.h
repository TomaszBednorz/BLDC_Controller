#ifndef _HAL_TIM_CFG_H_
#define _HAL_TIM_CFG_H_

/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include "hal_tim.h"
#include "xmc_ccu4.h"

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

typedef struct
{
    XMC_CCU4_SLICE_t* const slice;
    XMC_CCU4_MODULE_t* const module;
    const XMC_CCU4_SLICE_PRESCALER_t prescaler;
    const uint16_t period;
    const XMC_CCU4_SHADOW_TRANSFER_t prescaler_shadow_transfer_mask;
    const XMC_CCU4_SHADOW_TRANSFER_t period_shadow_transfer_mask;
}Hal_Tim_TimerCfg_t;


/***********************************************************************************************************
 ********************************************* Exported objects ********************************************
 ***********************************************************************************************************/

extern const Hal_Tim_TimerCfg_t Hal_Tim_TimerCfg[HAL_TIM_TIMER_MAX];

/***********************************************************************************************************
 ************************************** Exported function prototypes ***************************************
 ***********************************************************************************************************/

#endif  /* _HAL_TIM_CFG_H_ */
