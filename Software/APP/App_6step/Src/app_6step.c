/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include "app_6step.h"
#include "app_6step_cfg.h"
#include "DIGITAL_IO/digital_io.h"

#include "app_hall.h"

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

#define App_6step_UpdatePwmDutyCycles(ha, hb, hc, la, lb, lc) \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HA, ha); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HB, hb); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HC, hc); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LA, la); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LB, lb); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LC, lc)

#define App_6step_ResetPwmDutyCycles() \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HA, 0U); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HB, 0U); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_HC, 0U); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LA, 0U); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LB, 0U); \
    Hal_GateDrv_SetPwmDutyCycle(HAL_GATE_DRV_SIGNAL_LC, 0U)

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

typedef struct 
{
    volatile int8_t dir;                                     /* @APP_6STEP_DIR */
    volatile uint8_t step_number;
    volatile uint8_t actual_step_number;
    uint32_t duty_cycle;                                     /* 0 - 10000 => 0% - 100% */
    uint8_t status;
}App_6step_Setup_t;

/***********************************************************************************************************
 **************************************** Local function prototypes ****************************************
 ***********************************************************************************************************/

#if(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_HIGH_SIDE_MODULTATION)
static void App_6step_MethodHighSideModulation(uint8_t step);
#elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_LOW_SIDE_MODULTATION)
static void App_6step_MethodLowSideModulation(uint8_t step);
#elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_HIGH_SIDE_SYNCHRO)
static void App_6step_MethodHighSideSynchro(uint8_t step);
#elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_TWO_PHASE_SYNCHRO)
static void App_6step_MethodTwoPhaseSynchro(uint8_t step);
#elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_HIGH_AND_LOW_SIDE_SYNCHRO)
static void App_6step_MethodHighAndLowSideSynchro(uint8_t step);
#endif

/***********************************************************************************************************
 ******************************************** Exported objects *********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ********************************************* Local objects ***********************************************
 ***********************************************************************************************************/

static App_6step_Setup_t App_6step_Setup = \
{ \
   .dir=APP_6STEP_INIT_DIR, \
   .step_number=APP_6STEP_INIT_STEP, \
   .actual_step_number=APP_6STEP_INIT_STEP,  \
   .duty_cycle=APP_6STEP_INIT_DUTY_CYCLE,
   .status = true
};

/***********************************************************************************************************
 ******************************************* Exported functions ********************************************
 ***********************************************************************************************************/

void App_6step_SetDir(int8_t new_dir)
{
    App_6step_Setup.dir = new_dir;
}

int8_t App_6step_GetDir(void)
{
    return App_6step_Setup.dir;
}

void App_6step_SetStepNumber(uint8_t new_step)
{
    App_6step_Setup.step_number = new_step;
}

uint8_t App_6step_GetActualStepNumber(void)
{
    return App_6step_Setup.actual_step_number;
}

void App_6step_SetDutyCycle(uint32_t new_duty_cycle)
{
    App_6step_Setup.duty_cycle = new_duty_cycle;
}

void App_6step_Enable(void)
{
    App_6step_Setup.status = true;
}

void App_6step_Disable(void)
{
    App_6step_ResetPwmDutyCycles();
    App_6step_Setup.status = false;
}

void App_6step_AlgoIteration(void)
{
    if(App_6step_Setup.status)
    {
        #if(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_HIGH_SIDE_MODULTATION)
        App_6step_MethodHighSideModulation(App_6step_Setup.step_number);
        #elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_LOW_SIDE_MODULTATION)
        App_6step_MethodLowSideModulation(App_6step_Setup.step_number);
        #elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_HIGH_SIDE_SYNCHRO)
        App_6step_MethodHighSideSynchro(App_6step_Setup.step_number);
        #elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_TWO_PHASE_SYNCHRO)
        App_6step_MethodTwoPhaseSynchro(App_6step_Setup.step_number);
        #elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_HIGH_AND_LOW_SIDE_SYNCHRO)
        App_6step_MethodHighAndLowSideSynchro(App_6step_Setup.step_number);
        #endif

        App_6step_Setup.actual_step_number = App_6step_Setup.step_number;

        if(APP_6STEP_DIR_CLOCKWISE == App_6step_Setup.dir)
        {
            App_6step_Setup.step_number++;
            if(App_6step_Setup.step_number > 6U)
            {
                App_6step_Setup.step_number = 1U;
            }
        }
        else if(APP_6STEP_DIR_COUNTERWISE == App_6step_Setup.dir)
        {
            App_6step_Setup.step_number--;
            if(App_6step_Setup.step_number < 1U)
            {
                App_6step_Setup.step_number = 6U;
            }
        }
    }
}

/***********************************************************************************************************
 ******************************************** Local functions **********************************************
 ***********************************************************************************************************/

#if(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_HIGH_SIDE_MODULTATION)

static void App_6step_MethodHighSideModulation(uint8_t step)
{
    switch (step)
    {
        case 1U:
            App_6step_UpdatePwmDutyCycles(App_6step_Setup.duty_cycle,
                                         0U, 
                                         0U, 
                                         0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX, 
                                         0U);
            break;
        case 2U:
            App_6step_UpdatePwmDutyCycles(App_6step_Setup.duty_cycle,
                                         0U, 
                                         0U, 
                                         0U, 
                                         0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX);
            break;
        case 3U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         App_6step_Setup.duty_cycle,
                                         0U, 
                                         0U, 
                                         0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX);
            break;
        case 4U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         App_6step_Setup.duty_cycle,
                                         0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX, 
                                         0U, 
                                         0U);
            break;
        case 5U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         APP_6STEP_DUTY_CYCLE_MAX, 
                                         0U, 
                                         0U);
            break;
        case 6U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX, 
                                         0U);
            break;
        default:
            break;
    }
}

#elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_LOW_SIDE_MODULTATION)

static void App_6step_MethodLowSideModulation(uint8_t step)
{
    switch (step)
    {
        case 1U:
            App_6step_UpdatePwmDutyCycles(APP_6STEP_DUTY_CYCLE_MAX,
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         0U);
            break;
        case 2U:
            App_6step_UpdatePwmDutyCycles(APP_6STEP_DUTY_CYCLE_MAX,
                                         0U, 
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle);
            break;
        case 3U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX,
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle);
            break;
        case 4U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX,
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         0U);
            break;
        case 5U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX, 
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         0U);
            break;
        case 6U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         0U);
            break;
        default:
            break;
    }
}

#elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_HIGH_SIDE_SYNCHRO)

static void App_6step_MethodHighSideSynchro(uint8_t step)
{
    switch (step)
    {
        case 1U:
            App_6step_UpdatePwmDutyCycles(App_6step_Setup.duty_cycle, 
                                         0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         APP_6STEP_DUTY_CYCLE_MAX, 
                                         0U);
            break;
        case 2U:
            App_6step_UpdatePwmDutyCycles(App_6step_Setup.duty_cycle, 
                                         0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX);
            break;
        case 3U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         APP_6STEP_DUTY_CYCLE_MAX);
            break;
        case 4U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX, 
                                         App_6step_Setup.duty_cycle,
                                         0U);
            break;
        case 5U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle,
                                         APP_6STEP_DUTY_CYCLE_MAX, 
                                         0U, 
                                         App_6step_Setup.duty_cycle);
            break;
        case 6U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle,
                                         0U, 
                                         APP_6STEP_DUTY_CYCLE_MAX, 
                                         App_6step_Setup.duty_cycle);
            break;
        default:
            break;
    }
}

#elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_TWO_PHASE_SYNCHRO)

static void App_6step_MethodTwoPhaseSynchro(uint8_t step)
{
    switch (step)
    {
        case 1U:
            App_6step_UpdatePwmDutyCycles(App_6step_Setup.duty_cycle,
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         0U);
            break;
        case 2U:
            App_6step_UpdatePwmDutyCycles(App_6step_Setup.duty_cycle,
                                         0U, 
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle);
            break;
        case 3U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         App_6step_Setup.duty_cycle,
                                         0U, 
                                         0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle);
            break;
        case 4U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         App_6step_Setup.duty_cycle,
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         0U);
            break;
        case 5U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle,
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         0U);
            break;
        case 6U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         0U, 
                                         App_6step_Setup.duty_cycle,
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         0U);
            break;
        default:
            break;
    }
}

#elif(APP_6STEP_METHOD_USED==APP_6STEP_METHOD_HIGH_AND_LOW_SIDE_SYNCHRO)

static void App_6step_MethodHighAndLowSideSynchro(uint8_t step)
{
    switch (step)
    {
        case 1U:
            App_6step_UpdatePwmDutyCycles(App_6step_Setup.duty_cycle, 
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         App_6step_Setup.duty_cycle,  
                                         0U);
            break;
        case 2U:
            App_6step_UpdatePwmDutyCycles(App_6step_Setup.duty_cycle, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         App_6step_Setup.duty_cycle, 
                                         0U,  
                                         App_6step_Setup.duty_cycle);
            break;
        case 3U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         App_6step_Setup.duty_cycle, 
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         App_6step_Setup.duty_cycle,  
                                         App_6step_Setup.duty_cycle);
            break;
        case 4U:
            App_6step_UpdatePwmDutyCycles(App_6step_Setup.duty_cycle, 
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         App_6step_Setup.duty_cycle,  
                                         0U);
            break;
        case 5U:
            App_6step_UpdatePwmDutyCycles(App_6step_Setup.duty_cycle, 
                                         0U, 
                                         App_6step_Setup.duty_cycle, 
                                         App_6step_Setup.duty_cycle, 
                                         0U,  
                                         App_6step_Setup.duty_cycle);
            break;
        case 6U:
            App_6step_UpdatePwmDutyCycles(0U, 
                                         App_6step_Setup.duty_cycle, 
                                         App_6step_Setup.duty_cycle, 
                                         0U, 
                                         App_6step_Setup.duty_cycle,  
                                         App_6step_Setup.duty_cycle);
            break;
        default:
            break;
    }
}

#endif
