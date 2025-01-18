/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include "hal_gate_drv.h"
#include "hal_gate_drv_if.h"

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

typedef struct 
{
    Hal_GateDrv_CcuType_t type;
    void* handler;
    Hal_GateDrv_CcuChannel_t channel;
}Hal_GateDrv_Config_t;

/***********************************************************************************************************
 **************************************** Local function prototypes ****************************************
 ***********************************************************************************************************/

static void Hal_GateDrv_Start(void);

/***********************************************************************************************************
 ******************************************** Exported objects *********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ********************************************* Local objects ***********************************************
 ***********************************************************************************************************/

Hal_GateDrv_Config_t Hal_GateDrv_Config[HAL_GATE_DRV_SIGNAL_MAX] = 
{
    #define HAL_GATE_DRV_CFG_SIGNAL(ccu_type, ccu_channel, ccu_object) { \
        .type=ccu_type, \
        .handler=&ccu_object, \
        .channel=ccu_channel},
        HAL_GATE_DRV_CFG_TABLE
    #undef HAL_GATE_DRV_CFG_SIGNAL
};

/***********************************************************************************************************
 ******************************************* Exported functions ********************************************
 ***********************************************************************************************************/


void Hal_GateDrv_Init(void)
{
    Hal_GateDrv_SetPwmFreq(HAL_GATE_DRV_INIT_FREQ);
    Hal_GateDrv_Start();
    Hal_GateDrv_EnableSynch();

    for(uint8_t i = 0U; i < HAL_GATE_DRV_SIGNAL_MAX; i++)
    {
        Hal_GateDrv_SetPwmDutyCycle(i, 0U);
    }
}

void Hal_GateDrv_SetPwmFreq(uint32_t freq)
{
    for(uint8_t i = 0U; i < HAL_GATE_DRV_SIGNAL_MAX; i++)
    {
        switch (Hal_GateDrv_Config[i].type)
        {
            case HAL_GATE_DRV_CCU4:
                PWM_CCU4_SetFreq((PWM_CCU4_t*)Hal_GateDrv_Config[i].handler, freq); 
                break;
            case HAL_GATE_DRV_CCU8:
                PWM_CCU8_SetFreqSymmetric((PWM_CCU8_t*)Hal_GateDrv_Config[i].handler, freq); 
                break;
            default:
                break;
        }
    }
}

/* duty_cycle: 0 - 10000 */
void Hal_GateDrv_SetPwmDutyCycle(Hal_GateDrv_Signal_t signal, uint32_t duty_cycle)
{
    switch (Hal_GateDrv_Config[signal].type)
    {
        case HAL_GATE_DRV_CCU4:
            PWM_CCU4_SetDutyCycle((PWM_CCU4_t*)Hal_GateDrv_Config[signal].handler, duty_cycle);
            break;

        case HAL_GATE_DRV_CCU8:
            PWM_CCU8_SetDutyCycleSymmetric((PWM_CCU8_t*)Hal_GateDrv_Config[signal].handler, Hal_GateDrv_Config[signal].channel, duty_cycle);
            break;

        default:
            break;
    }
}

/***********************************************************************************************************
 ******************************************** Local functions **********************************************
 ***********************************************************************************************************/

static void Hal_GateDrv_Start(void)
{
    for(uint8_t i = 0U; i < HAL_GATE_DRV_SIGNAL_MAX; i++)
    {
        switch (Hal_GateDrv_Config[i].type)
        {
            case HAL_GATE_DRV_CCU4:
                PWM_CCU4_Start((PWM_CCU4_t*)Hal_GateDrv_Config[i].handler); 
                break;
            case HAL_GATE_DRV_CCU8:
                PWM_CCU8_Start((PWM_CCU8_t*)Hal_GateDrv_Config[i].handler); 
                break;
            default:
                break;
        }
    }
}

// Valid only in current configuration
// void Hal_GateDrv_SetPinsPassiveLevel(Hal_GateDrv_PinsPassiveLevel_t passive_level)
// {
//     if(HAL_GATE_DRV_PINS_PASSIVE_LEVEL_INVERTED == passive_level)
//     {
//         // LA
//          XMC_CCU8_SLICE_SetPassiveLevel((XMC_CCU8_SLICE_t*)((PWM_CCU8_t*)Hal_GateDrv_Config[HAL_GATE_DRV_SIGNAL_LA].handler)->ccu8_slice_ptr,
//                                         2,
//                                         XMC_CCU8_SLICE_OUTPUT_PASSIVE_LEVEL_HIGH);
//         // LB
//          XMC_CCU8_SLICE_SetPassiveLevel((XMC_CCU8_SLICE_t*)((PWM_CCU8_t*)Hal_GateDrv_Config[HAL_GATE_DRV_SIGNAL_LB].handler)->ccu8_slice_ptr,
//                                         2,
//                                         XMC_CCU8_SLICE_OUTPUT_PASSIVE_LEVEL_HIGH);
//         // LA
//          XMC_CCU8_SLICE_SetPassiveLevel((XMC_CCU8_SLICE_t*)((PWM_CCU8_t*)Hal_GateDrv_Config[HAL_GATE_DRV_SIGNAL_LC].handler)->ccu8_slice_ptr,
//                                         1,
//                                         XMC_CCU8_SLICE_OUTPUT_PASSIVE_LEVEL_LOW);
//     }
//     else
//     {
//         /* Do nothing */
//     }
// }
