// /***********************************************************************************************************
//  ********************************************* Included files **********************************************
//  ***********************************************************************************************************/

// #include "app_hall.h"
// #include "app_hall_cfg.h"
// #include "math_trig.h"

// /***********************************************************************************************************
//  ************************************************* Defines *************************************************
//  ***********************************************************************************************************/

// /***********************************************************************************************************
//  *********************************************** Data types ************************************************
//  ***********************************************************************************************************/

// /***********************************************************************************************************
//  **************************************** Local function prototypes ****************************************
//  ***********************************************************************************************************/

// static float App_Hall_CalculateAngle(int16_t y, int16_t x);
// static float App_Hall_CorrectionFactor(float angle);

// /***********************************************************************************************************
//  ******************************************** Exported objects *********************************************
//  ***********************************************************************************************************/

// /***********************************************************************************************************
//  ********************************************* Local objects ***********************************************
//  ***********************************************************************************************************/

// static float App_Hall_Angle[APP_HALL_SENSOR_MAX];
// static float App_Hall_CalibrationAngle[APP_HALL_SENSOR_MAX];

// /***********************************************************************************************************
//  ******************************************* Exported functions ********************************************
//  ***********************************************************************************************************/

// void App_Hall_Task(void)
// {
//     App_Hall_Angle[APP_HALL_SENSOR_0] = App_Hall_CalculateAngle(Hal_Hall_Results[APP_HALL_SENSOR_0].x, Hal_Hall_Results[APP_HALL_SENSOR_0].y);

// }

// float App_Hall_GetAngle(uint8_t sensor_nbr)
// {
//     return App_Hall_Angle[sensor_nbr] - App_Hall_CalibrationAngle[sensor_nbr];
// }

// void App_Hall_Calibrate(void)
// {
//     App_Hall_CalibrationAngle[APP_HALL_SENSOR_0] = App_Hall_Angle[APP_HALL_SENSOR_0];
// }

// /***********************************************************************************************************
//  ******************************************** Local functions **********************************************
//  ***********************************************************************************************************/

// static float App_Hall_CalculateAngle(int16_t y, int16_t x)
// {
//     float angle = Math_Trig_Atan2(x, y);

//     if(angle < 0.0f)
//     {
//         angle += MATH_TRIG_RAD_2_PI;
//     }

//     angle = (Math_Trig_RadToDegs(angle) - App_Hall_CorrectionFactor(angle));

//     return angle;
// }

// static float App_Hall_CorrectionFactor(float angle)
// {
//     float sin_val = 0.0f, cos_val = 0.0f;
//     float factor = 0.0f;
//     float in_angle = 0.0f;

//     for(uint8_t i = 0; i < APP_HALL_HARMONICS_NBR; i++)
//     {
//         in_angle = Math_Trig_NormAngle(angle * (i + 1));
//         Math_Trig_SinCos(in_angle, &sin_val, &cos_val);

//         factor += (App_Hall_HarmonicsAlfa[i] * sin_val);
//         factor += (App_Hall_HarmonicsBeta[i] * cos_val);
//     }

//     factor += APP_HALL_HARMONICS_OFFSET;

//     return factor;
// }













// /***
//  * 
// #include "UART/uart.h"
// #include <stdio.h>
// #include <stdint.h>
// #include <string.h>
// #include "DIGITAL_IO/digital_io.h"
// #include "app_6step.h"

// extern uint16_t bemf_a[10000];
// extern uint16_t bemf_b[10000];
// extern uint16_t bemf_c[10000];
// extern uint16_t bemf_n[10000];
// extern uint32_t cnt;

// uint32_t int_cnt = 0;

// char buffer[50];


//     if(cnt == 10000)
//     {

//         if(int_cnt < 10000)
//         {
//             sprintf(buffer, "%d %d %d %d\r\n", bemf_a[int_cnt], bemf_b[int_cnt], bemf_c[int_cnt], bemf_n[int_cnt]);
//             UART_StartTransmitIRQ(&UART_0, (uint8_t*)buffer, (uint32_t)strlen(buffer));
//             int_cnt++;
//         }
//     }


//  */