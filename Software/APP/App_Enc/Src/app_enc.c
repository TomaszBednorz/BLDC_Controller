/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include "app_enc.h"
#include "app_enc_cfg.h"
#include "math_trig.h"
#include "hal_enc.h"
#include "lowpass_filter.h"

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

typedef struct
{
    LowpassFilter_3rdStage_t pid_sin;
    LowpassFilter_3rdStage_t pid_cos;
}App_Enc_Data_t;

/***********************************************************************************************************
 **************************************** Local function prototypes ****************************************
 ***********************************************************************************************************/

static float App_Enc_CalculateAngle(void);
static float App_Enc_CalculateAnglef(float y, float x);
static float App_Enc_CorrectionFactor(float angle);
static float App_Enc_DetectPosition(float angle);

/***********************************************************************************************************
 ******************************************** Exported objects *********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ********************************************* Local objects ***********************************************
 ***********************************************************************************************************/

static float App_Enc_Angle;
static float App_Enc_PrevAngle;
static App_Enc_Data_t App_Enc_Data;

/***********************************************************************************************************
 ******************************************* Exported functions ********************************************
 ***********************************************************************************************************/

void App_Enc_Init(void)
{
    Lowpass_Filter_3rdOrderInit(&App_Enc_Data.pid_sin, APP_HALL_LOWPASS_FILTER_ALPHA);
    Lowpass_Filter_3rdOrderInit(&App_Enc_Data.pid_cos, APP_HALL_LOWPASS_FILTER_ALPHA);
}


char buffer[50];
#include "UART/uart.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "DIGITAL_IO/digital_io.h"
#include "app_6step.h"


void App_Enc_Task(void)
{
    float sin, cos, angle, speed;

    static uint32_t local_cnt;

    local_cnt++;

    int16_t sin_diff = (int16_t)Hal_Enc_Results.sin_p - (int16_t)Hal_Enc_Results.sin_n;
    int16_t cos_diff = (int16_t)Hal_Enc_Results.cos_p - (int16_t)Hal_Enc_Results.cos_n;

    sin = Lowpass_Filter_3rdOrderUpdate(&App_Enc_Data.pid_sin, (float)sin_diff);
    cos = Lowpass_Filter_3rdOrderUpdate(&App_Enc_Data.pid_cos, (float)cos_diff);

    angle = App_Enc_CalculateAnglef(sin, cos);

    App_Enc_Angle = App_Enc_DetectPosition(angle) / 6.0f;
}

static float App_Enc_DetectPosition(float angle)
{
    static uint32_t local_cnt;
    static bool zeroing_flag;
    static int32_t laps_cnt;
    static float calibration_angle, prev_angle;
    
    local_cnt++;

    angle = (angle < 0.0f) ? (angle + 360.0f) : angle;

    if((!zeroing_flag) && (2U == local_cnt))
    {
        zeroing_flag = true;
        calibration_angle = angle;
    }

    if(zeroing_flag)
    {
        if((angle < 3.0f) && (prev_angle > 357.0f))
        {
            laps_cnt++;
        }

        if((angle > 357.0f) && (prev_angle < 3.0f))
        {
            laps_cnt--;
        }
    }

    prev_angle = angle;

    return laps_cnt * 360.0f + angle - calibration_angle;
}

float App_Enc_GetAngle(void)
{
    return App_Enc_Angle;
}

/***********************************************************************************************************
 ******************************************** Local functions **********************************************
 ***********************************************************************************************************/

static float App_Enc_CalculateAngle(void)
{
    int16_t sin_diff = (int16_t)Hal_Enc_Results.sin_p - (int16_t)Hal_Enc_Results.sin_n;
    int16_t cos_diff = (int16_t)Hal_Enc_Results.cos_p - (int16_t)Hal_Enc_Results.cos_n;

    float angle = Math_Trig_Atan2(cos_diff, sin_diff);

    if(angle < 0.0f)
    {
        angle += MATH_TRIG_RAD_2_PI;
    }

    angle = (Math_Trig_RadToDegs(angle) - App_Enc_CorrectionFactor(angle));

    return angle;
}

static float App_Enc_CalculateAnglef(float y, float x)
{
    float angle = Math_Trig_Atan2f(x, y);

    if(angle < 0.0f)
    {
        angle += MATH_TRIG_RAD_2_PI;
    }

    angle = (Math_Trig_RadToDegs(angle) - App_Enc_CorrectionFactor(angle));

    return angle;
}

static float App_Enc_CorrectionFactor(float angle)
{
    float sin_val = 0.0f, cos_val = 0.0f;
    float factor = 0.0f;
    float in_angle = 0.0f;

    for(uint8_t i = 0; i < APP_ENC_HARMONICS_NBR; i++)
    {
        in_angle = Math_Trig_NormAngle(angle * (i + 1));
        Math_Trig_SinCos(in_angle, &sin_val, &cos_val);

        factor += (App_Enc_HarmonicsAlfa[i] * sin_val);
        factor += (App_Enc_HarmonicsBeta[i] * cos_val);
    }

    factor += APP_ENC_HARMONICS_OFFSET;

    return factor;
}
