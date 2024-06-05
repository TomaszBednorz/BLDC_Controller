#ifndef _HAL_GATE_DRV_IF_H_
#define _HAL_GATE_DRV_IF_H_

/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include "hal_gate_drv_cfg.h"

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

/* Init freq */
#define HAL_GATE_DRV_INIT_FREQ       (10000U)

/* 
 * Gate driver signals configuration: ccu type, ccu channel, ccu object
 * Sequence: HA, HB, HC, LA, LB, LC
 */
#define HAL_GATE_DRV_CFG_TABLE  \
    HAL_GATE_DRV_CFG_SIGNAL(HAL_GATE_DRV_CCU8, HAL_GATE_DRV_CHANNEL_2, PWM_GATE_DRV_HA)        \
    HAL_GATE_DRV_CFG_SIGNAL(HAL_GATE_DRV_CCU4, HAL_GATE_DRV_CHANNEL_UNUSED, PWM_GATE_DRV_HB)   \
    HAL_GATE_DRV_CFG_SIGNAL(HAL_GATE_DRV_CCU4, HAL_GATE_DRV_CHANNEL_UNUSED, PWM_GATE_DRV_HC)   \
    HAL_GATE_DRV_CFG_SIGNAL(HAL_GATE_DRV_CCU8, HAL_GATE_DRV_CHANNEL_2, PWM_GATE_DRV_LA)        \
    HAL_GATE_DRV_CFG_SIGNAL(HAL_GATE_DRV_CCU8, HAL_GATE_DRV_CHANNEL_2, PWM_GATE_DRV_LB)        \
    HAL_GATE_DRV_CFG_SIGNAL(HAL_GATE_DRV_CCU8, HAL_GATE_DRV_CHANNEL_1, PWM_GATE_DRV_LC)

#define Hal_GateDrv_EnableSynch()  (GLOBAL_CCU8_SyncStartTriggerHigh(GLOBAL_CCU8_CCUCON_Msk | GLOBAL_CCU4_CCUCON_Msk))

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

typedef enum
{
    HAL_GATE_DRV_CCU4,
    HAL_GATE_DRV_CCU8
}Hal_GateDrv_CcuType_t;

typedef enum
{
    HAL_GATE_DRV_CHANNEL_1 = XMC_CCU8_SLICE_COMPARE_CHANNEL_1,
    HAL_GATE_DRV_CHANNEL_2 = XMC_CCU8_SLICE_COMPARE_CHANNEL_2,
    HAL_GATE_DRV_CHANNEL_UNUSED = 0xAA
}Hal_GateDrv_CcuChannel_t;

/***********************************************************************************************************
 ********************************************* Exported objects ********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ************************************** Exported function prototypes ***************************************
 ***********************************************************************************************************/

#endif  /* _HAL_GATE_DRV_IF_H_ */
