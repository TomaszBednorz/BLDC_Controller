#ifndef _APP_MOTOR_CFG_H_
#define _APP_MOTOR_CFG_H_

/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include <stdbool.h>

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

#define APP_MOTOR_ENABLED                               (true)
#define APP_MOTOR_DISABLED                              (false)

/* CFG */
#define APP_MOTOR_BEMF_ANALYSIS                         (APP_MOTOR_DISABLED)
#define APP_MOTOR_CURRENT_ANALYSIS                      (APP_MOTOR_DISABLED)
#define APP_MOTOR_STARTUP                               (APP_MOTOR_ENABLED)
#define APP_MOTOR_PID_POSITION                          (APP_MOTOR_ENABLED)

#define APP_MOTOR_DYNAMIC                         (APP_MOTOR_ENABLED)


/* START-UP */
#define APP_MOTOR_ALIGNMENT_TIME                        (200)     /* 100 ms, 1ms base*/
#define APP_MOTOR_START_TIME                            (40000)    /* 39.9s, 40000 - APP_MOTOR_ALIGNMENT_TIME ms, 1ms base */

// #define APP_MOTOR_SPEED_START                           (0x2BF1)   /* 10ms, 100Hz */
// #define APP_MOTOR_SPEED_PID_P_TERM                      (0.04)
// #define APP_MOTOR_SPEED_PID_I_TERM                      (0.01)
// #define APP_MOTOR_SPEED_PID_D_TERM                      (0)
// #define APP_MOTOR_SPEED_PID_ANTI_WINDUP_LIMIT           (1000)     /* Be carefull */

/* BEMF */
#define APP_MOTOR_BEMF_ZCP_COEF                         (1.1f)
#define APP_MOTOR_BEMF_THRESHOLD_UP                     (550)
#define APP_MOTOR_BEMF_THRESHOLD_DOWN                   (50)

/* CURRENT */
#define APP_MOTOR_CURRENT_PWM_TARET                     (1000)  /* 10% */
#define APP_MOTOR_CURRENT_PWM_MAX                       (1500)  /* 15% */

#define APP_MOTOR_CURRENT_TARGET                        (2600)
#define APP_MOTOR_CURRENT_SCALE_FACTOR                  (float)((float)APP_MOTOR_CURRENT_PWM_TARET / (float)APP_MOTOR_CURRENT_TARGET)

#define APP_MOTOR_CURRENT_PID_P_TERM                      (0.2)
#define APP_MOTOR_CURRENT_PID_I_TERM                      (0.1)
#define APP_MOTOR_CURRENT_PID_D_TERM                      (0)
#define APP_MOTOR_CURRENT_PID_ANTI_WINDUP_LIMIT           (100)

/* SPEED config */
#define APP_MOTOR_TIM_CLOCK             (144000000.0f)
#define APP_MOTOR_TIM_PRESCALER         (512.0f)
#define APP_MOTOR_STEPS_PER_CYCLE       (720.f)
#define APP_MOTOR_CYCLE_DEGS            (360.f)
#define APP_MOTOR_STEPS_TO_CYCLE_RATIO  (2.0f)  /* APP_MOTOR_STEPS_PER_CYCLE / APP_MOTOR_CYCLE_DEGS */
#define APP_MOTOR_MAX_SPEED             (360.0f)  /* 360deg / s */



/* SPEED config */
#define APP_MOTOR_SPEED_START                           (0.0f) 
#define APP_MOTOR_SPEED_PID_P_TERM                      (0.3f)
#define APP_MOTOR_SPEED_PID_I_TERM                      (0.05f)
#define APP_MOTOR_SPEED_PID_D_TERM                      (0.0f)
#define APP_MOTOR_SPEED_PID_ANTI_WINDUP_LIMIT           (50.0f) 

#define APP_MOTOR_SPEED_MAX                             (0x01C1)   /* 0.4ms, 2500Hz */



/* POSITION config */
#define APP_MOTOR_POSITION_START                           (301.5f) 
#define APP_MOTOR_POSITION_PID_P_TERM                      (2.0f)
#define APP_MOTOR_POSITION_PID_I_TERM                      (0.4f)
#define APP_MOTOR_POSITION_PID_D_TERM                      (0.0f)
#define APP_MOTOR_POSITION_PID_ANTI_WINDUP_LIMIT           (100.0f) 

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ********************************************* Exported objects ********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ************************************** Exported function prototypes ***************************************
 ***********************************************************************************************************/

#endif  /* _APP_MOTOR_CFG_H_ */
