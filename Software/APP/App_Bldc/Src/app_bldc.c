/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include "app_bldc.h"
#include "app_bldc_cfg.h"
#include "DIGITAL_IO/digital_io.h"

#include "app_hall.h"

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

#define App_Bldc_UpdatePwmDutyCycles(ha, hb, hc, la, lb, lc) \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HA, ha); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HB, hb); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HC, hc); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LA, la); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LB, lb); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LC, lc)

#define App_Bldc_ResetPwmDutyCycles() \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HA, 0U); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HB, 0U); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HC, 0U); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LA, 0U); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LB, 0U); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LC, 0U)

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 **************************************** Local function prototypes ****************************************
 ***********************************************************************************************************/

#if(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_HIGH_SIDE_MODULTATION)
static void App_Bldc_MethodHighSideModulation(uint8_t step);
#elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_LOW_SIDE_MODULTATION)
static void App_Bldc_MethodLowSideModulation(uint8_t step);
#elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_HIGH_SIDE_SYNCHRO)
static void App_Bldc_MethodHighSideSynchro(uint8_t step);
#elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_TWO_PHASE_SYNCHRO)
static void App_Bldc_MethodTwoPhaseSynchro(uint8_t step);
#elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_HIGH_AND_LOW_SIDE_SYNCHRO)
static void App_Bldc_MethodHighAndLowSideSynchro(uint8_t step);
#endif

/***********************************************************************************************************
 ******************************************** Exported objects *********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ********************************************* Local objects ***********************************************
 ***********************************************************************************************************/

static App_Bldc_Setup_t App_Bldc_Setup = \
{ \
   .state=APP_BLDC_INIT_STATE, \
   .cycle_time=APP_BLDC_INIT_CYCLE_TIME, \
   .dir=APP_BLDC_INIT_DIR,  \
   .duty_cycle=APP_BLDC_INIT_DUTY_CYCLE
};

/***********************************************************************************************************
 ******************************************* Exported functions ********************************************
 ***********************************************************************************************************/

void App_Hall_UpdateSetup(App_Bldc_Setup_t* setup)
{
    App_Bldc_Setup.cycle_time = setup->cycle_time;
    App_Bldc_Setup.dir = setup->dir;

    for(uint8_t i = 0; i < HAL_GATE_DRV_SIGNAL_MAX; i++)
    {
        App_Bldc_Setup.duty_cycle[i] = setup->duty_cycle[i];
    }
}

void App_Bldc_UpdateDutyCycle(uint32_t duty_cycle)
{
    if(APP_BLDC_STATE_ON == App_Bldc_Setup.state)
    {
        for(uint8_t i = 0; i < HAL_GATE_DRV_SIGNAL_MAX; i++)
        {
            App_Bldc_Setup.duty_cycle[i] = duty_cycle;
        }
    }
}

void App_Bldc_SetState(AppBldc_State_t new_state)
{
    if(new_state != App_Bldc_Setup.state)
    {
        if(new_state != APP_BLDC_STATE_ON)
        {
            for(uint8_t i = 0; i < HAL_GATE_DRV_SIGNAL_MAX; i++)
            {
                App_Bldc_Setup.duty_cycle[i] = 0U;
            }
            App_Bldc_ResetPwmDutyCycles();
        }

        App_Bldc_Setup.state = new_state;
    }
}

void App_Bldc_TimerTask(void)
{
    static uint8_t current_cycle = 0U;
    static uint8_t current_step = 1U;

    if(APP_BLDC_STATE_ON == App_Bldc_Setup.state)
    {
        current_cycle++;

        if(current_cycle >= App_Bldc_Setup.cycle_time)
        {
            current_cycle = 0U;

            if(APP_BLDC_DIR_CLOCKWISE == App_Bldc_Setup.dir)
            {
                current_step++;
                if(current_step > 6U)
                {
                    current_step = 1U;
                }
            }
            else if(APP_BLDC_DIR_COUNTERWISE == App_Bldc_Setup.dir)
            {
                current_step--;
                if(current_step < 1U)
                {
                    current_step = 6U;
                }
            }

            #if(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_HIGH_SIDE_MODULTATION)
            App_Bldc_MethodHighSideModulation(current_step);
            #elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_LOW_SIDE_MODULTATION)
            App_Bldc_MethodLowSideModulation(current_step);
            #elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_HIGH_SIDE_SYNCHRO)
            App_Bldc_MethodHighSideSynchro(current_step);
            #elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_TWO_PHASE_SYNCHRO)
            App_Bldc_MethodTwoPhaseSynchro(current_step);
            #elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_HIGH_AND_LOW_SIDE_SYNCHRO)
            App_Bldc_MethodHighAndLowSideSynchro(current_step);
            #endif
        }
    }
}

/***********************************************************************************************************
 ******************************************** Local functions **********************************************
 ***********************************************************************************************************/

#if(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_HIGH_SIDE_MODULTATION)

static void App_Bldc_MethodHighSideModulation(uint8_t step)
{
    switch (step)
    {
        case 1U:
            App_Bldc_UpdatePwmDutyCycles(App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HA],
                                         0U, 
                                         0U, 
                                         0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX, 
                                         0U);
            break;
        case 2U:
            App_Bldc_UpdatePwmDutyCycles(App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HA],
                                         0U, 
                                         0U, 
                                         0U, 
                                         0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX);
            break;
        case 3U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HB],
                                         0U, 
                                         0U, 
                                         0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX);
            break;
        case 4U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HB],
                                         0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX, 
                                         0U, 
                                         0U);
            break;
        case 5U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HC], 
                                         APP_BLDC_DUTY_CYCLE_MAX, 
                                         0U, 
                                         0U);
            break;
        case 6U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HC], 
                                         0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX, 
                                         0U);
            break;
        default:
            break;
    }
}

#elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_LOW_SIDE_MODULTATION)

static void App_Bldc_MethodLowSideModulation(uint8_t step)
{
    switch (step)
    {
        case 1U:
            App_Bldc_UpdatePwmDutyCycles(APP_BLDC_DUTY_CYCLE_MAX,
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LB], 
                                         0U);
            break;
        case 2U:
            App_Bldc_UpdatePwmDutyCycles(APP_BLDC_DUTY_CYCLE_MAX,
                                         0U, 
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LC]);
            break;
        case 3U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX,
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LC]);
            break;
        case 4U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX,
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LA], 
                                         0U, 
                                         0U);
            break;
        case 5U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LA], 
                                         0U, 
                                         0U);
            break;
        case 6U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LB], 
                                         0U);
            break;
        default:
            break;
    }
}

#elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_HIGH_SIDE_SYNCHRO)

static void App_Bldc_MethodHighSideSynchro(uint8_t step)
{
    switch (step)
    {
        case 1U:
            App_Bldc_UpdatePwmDutyCycles(App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HA], 
                                         0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LA], 
                                         APP_BLDC_DUTY_CYCLE_MAX, 
                                         0U);
            break;
        case 2U:
            App_Bldc_UpdatePwmDutyCycles(App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HA], 
                                         0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LA], 
                                         0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX);
            break;
        case 3U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HB], 
                                         0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LB], 
                                         APP_BLDC_DUTY_CYCLE_MAX);
            break;
        case 4U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HB], 
                                         0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LB],
                                         0U);
            break;
        case 5U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HC],
                                         APP_BLDC_DUTY_CYCLE_MAX, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LC]);
            break;
        case 6U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HC],
                                         0U, 
                                         APP_BLDC_DUTY_CYCLE_MAX, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LC]);
            break;
        default:
            break;
    }
}

#elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_TWO_PHASE_SYNCHRO)

static void App_Bldc_MethodTwoPhaseSynchro(uint8_t step)
{
    switch (step)
    {
        case 1U:
            App_Bldc_UpdatePwmDutyCycles(App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HA],
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LB], 
                                         0U);
            break;
        case 2U:
            App_Bldc_UpdatePwmDutyCycles(App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HA],
                                         0U, 
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LC]);
            break;
        case 3U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HB],
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LC]);
            break;
        case 4U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HB],
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LA], 
                                         0U, 
                                         0U);
            break;
        case 5U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HC],
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LA], 
                                         0U, 
                                         0U);
            break;
        case 6U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HC],
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LB], 
                                         0U);
            break;
        default:
            break;
    }
}

#elif(APP_BLDC_METHOD_USED==APP_BLDC_METHOD_HIGH_AND_LOW_SIDE_SYNCHRO)

static void App_Bldc_MethodHighAndLowSideSynchro(uint8_t step)
{
    switch (step)
    {
        case 1U:
            App_Bldc_UpdatePwmDutyCycles(App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HA], 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HB], 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LA], 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LB],  
                                         0U);
            break;
        case 2U:
            App_Bldc_UpdatePwmDutyCycles(App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HA], 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HC], 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LA], 
                                         0U,  
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LC]);
            break;
        case 3U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HB], 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HC], 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LB],  
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LC]);
            break;
        case 4U:
            App_Bldc_UpdatePwmDutyCycles(App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HA], 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HB], 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LA], 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LB],  
                                         0U);
            break;
        case 5U:
            App_Bldc_UpdatePwmDutyCycles(App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HA], 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HC], 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LA], 
                                         0U,  
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LC]);
            break;
        case 6U:
            App_Bldc_UpdatePwmDutyCycles(0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HB], 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_HC], 
                                         0U, 
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LB],  
                                         App_Bldc_Setup.duty_cycle[HAL_GATE_DRV_SIGNAL_LC]);
            break;
        default:
            break;
    }
}

#endif




