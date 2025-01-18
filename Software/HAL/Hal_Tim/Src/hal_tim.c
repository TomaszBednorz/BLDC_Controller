/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include "hal_tim.h"
#include "hal_tim_cfg.h"

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

#define HAL_TIM_PRESCALER_COMPUTING_BASE    (2U)

#define HAL_TIM_MCU_FREQ                    (144000000) /* 144 MHz */

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 **************************************** Local function prototypes ****************************************
 ***********************************************************************************************************/

static inline uint32_t Hal_Tim_Pow(uint32_t base, uint8_t exp);

/***********************************************************************************************************
 ******************************************** Exported objects *********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ********************************************* Local objects ***********************************************
 ***********************************************************************************************************/

static uint32_t Hal_Tim_Prescaler[HAL_TIM_TIMER_MAX];

/***********************************************************************************************************
 ******************************************* Exported functions ********************************************
 ***********************************************************************************************************/

void Hal_Tim_Init(void)
{
    for(uint8_t tim_nbr = 0U; tim_nbr < HAL_TIM_TIMER_MAX; tim_nbr++)
    {
        XMC_CCU4_StopPrescaler(Hal_Tim_TimerCfg[tim_nbr].module);
        XMC_CCU4_SLICE_SetPrescaler(Hal_Tim_TimerCfg[tim_nbr].slice, Hal_Tim_TimerCfg[tim_nbr].prescaler);
        XMC_CCU4_SLICE_SetTimerPeriodMatch(Hal_Tim_TimerCfg[tim_nbr].slice, Hal_Tim_TimerCfg[tim_nbr].period);
        XMC_CCU4_EnableShadowTransfer(Hal_Tim_TimerCfg[tim_nbr].module, Hal_Tim_TimerCfg[tim_nbr].period_shadow_transfer_mask | \
                                                                        Hal_Tim_TimerCfg[tim_nbr].prescaler_shadow_transfer_mask);
        XMC_CCU4_StartPrescaler(Hal_Tim_TimerCfg[tim_nbr].module);

        Hal_Tim_Prescaler[tim_nbr] = Hal_Tim_Pow(HAL_TIM_PRESCALER_COMPUTING_BASE, Hal_Tim_TimerCfg[tim_nbr].prescaler);
    }
}

void Hal_Tim_Deinit(void)
{
    for(uint8_t tim_nbr = 0U; tim_nbr < HAL_TIM_TIMER_MAX; tim_nbr++)
    {
        XMC_CCU4_DisableModule(Hal_Tim_TimerCfg[tim_nbr].module);
    } 
}


void Hal_Tim_SetFreq(Hal_Tim_Timer_t timer, uint32_t freq)
{
    uint32_t period_val;

    if(freq > 0U)
    {
        period_val = (HAL_TIM_MCU_FREQ / (Hal_Tim_Prescaler[timer] * freq)) - 1U;

        if(period_val <= UINT16_MAX)
        {
            XMC_CCU4_SLICE_SetTimerPeriodMatch(Hal_Tim_TimerCfg[timer].slice, (uint16_t)period_val);
            XMC_CCU4_EnableShadowTransfer(Hal_Tim_TimerCfg[timer].module, Hal_Tim_TimerCfg[timer].period_shadow_transfer_mask);
        }
    }
}

uint32_t Hal_Tim_GetFreq(Hal_Tim_Timer_t timer)
{
    uint32_t period = (uint32_t)XMC_CCU4_SLICE_GetTimerPeriodMatch(Hal_Tim_TimerCfg[timer].slice);

    return (HAL_TIM_MCU_FREQ / (Hal_Tim_Prescaler[timer] * (period + 1U)));
}

void Hal_Tim_SetPeriodReg(Hal_Tim_Timer_t timer, uint16_t period)
{
    XMC_CCU4_SLICE_SetTimerPeriodMatch(Hal_Tim_TimerCfg[timer].slice, period);
    XMC_CCU4_EnableShadowTransfer(Hal_Tim_TimerCfg[timer].module, Hal_Tim_TimerCfg[timer].period_shadow_transfer_mask);
}

uint16_t Hal_Tim_GetPeriodReg(Hal_Tim_Timer_t timer)
{
    return XMC_CCU4_SLICE_GetTimerPeriodMatch(Hal_Tim_TimerCfg[timer].slice);
}

uint16_t Hal_Tim_GetCunterReg(Hal_Tim_Timer_t timer)
{
    return XMC_CCU4_SLICE_GetTimerValue(Hal_Tim_TimerCfg[timer].slice);
}

/***********************************************************************************************************
 ******************************************** Local functions **********************************************
 ***********************************************************************************************************/

static inline uint32_t Hal_Tim_Pow(uint32_t base, uint8_t exp)
{
    uint32_t result = 1;

    for(uint8_t i = 0; i < exp; i++)
    {
        result *= base;
    }

    return result;
}
