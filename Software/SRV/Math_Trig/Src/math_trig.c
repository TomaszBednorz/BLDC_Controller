/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include <stdbool.h>
#include <math_trig.h>

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

#define MATH_TRIG_HASTINGS_COEF_1        (0.995354f)
#define MATH_TRIG_HASTINGS_COEF_2        (0.288679f)
#define MATH_TRIG_HASTINGS_COEF_3        (0.079331f)

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 **************************************** Local function prototypes ****************************************
 ***********************************************************************************************************/

static float Math_Trig_HastingsArctan(float input);

/***********************************************************************************************************
 ******************************************** Exported objects *********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ********************************************* Local objects ***********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ******************************************* Exported functions ********************************************
 ***********************************************************************************************************/

float Math_Trig_Atan2f(float y, float x)
{
    float f_x = x;
    float f_y = y;

    bool swap = fabs(f_x) < fabs(f_y);
    float atan_input = (swap ? f_x : f_y) / (swap ? f_y : f_x);

    // Approximate atan
    float result = Math_Trig_HastingsArctan(atan_input);


    // If swapped, adjust atan output
    result = swap ? (atan_input >= 0.0f ? MATH_TRIG_RAD_PI_2 : -MATH_TRIG_RAD_PI_2) - result : result;
    
    // Adjust quadrants
    if      (x >= 0.0f && y >= 0.0f) {}                             // 1st quadrant
    else if (x <  0.0f && y >= 0.0f) { result =  MATH_TRIG_RAD_PI + result; } // 2nd quadrant
    else if (x <  0.0f && y <  0.0f) { result = -MATH_TRIG_RAD_PI + result; } // 3rd quadrant
    else if (x >= 0.0f && y <  0.0f) {}                             // 4th quadrant

    return result;
}

float Math_Trig_Atan2(int16_t y, int16_t x)
{
    float f_x = (float)x;
    float f_y = (float)y;

    bool swap = fabs(f_x) < fabs(f_y);
    float atan_input = (swap ? f_x : f_y) / (swap ? f_y : f_x);

    // Approximate atan
    float result = Math_Trig_HastingsArctan(atan_input);


    // If swapped, adjust atan output
    result = swap ? (atan_input >= 0.0f ? MATH_TRIG_RAD_PI_2 : -MATH_TRIG_RAD_PI_2) - result : result;
    
    // Adjust quadrants
    if      (x >= 0 && y >= 0) {}                             // 1st quadrant
    else if (x <  0 && y >= 0) { result =  MATH_TRIG_RAD_PI + result; } // 2nd quadrant
    else if (x <  0 && y <  0) { result = -MATH_TRIG_RAD_PI + result; } // 3rd quadrant
    else if (x >= 0 && y <  0) {}                             // 4th quadrant

    return result;
}

void Math_Trig_SinCos(float x, float *sin, float *cos)
{
    float sin_res = 0.0f, cos_res = 0.0f;
    float x_pow[7U];

    x_pow[0] = x;
    for(uint8_t i = 1; i < 7U; i++)
    {
        x_pow[i] = x * x_pow[i-1];
    }

    sin_res = x_pow[0];
    sin_res -= (x_pow[2] / 6.0f);
    sin_res += (x_pow[4] / 120.0f);
    sin_res -= (x_pow[6] / 5040.0f);

    cos_res = 1;
    cos_res -= (x_pow[1] / 2.0f);
    cos_res += (x_pow[3] / 24.0f);
    cos_res -= (x_pow[5] / 720.0f);

    *sin = sin_res;
    *cos = cos_res;
}

float Math_Trig_NormAngle(float rad)
{
    while(rad > MATH_TRIG_RAD_PI)
    {
        rad -= MATH_TRIG_RAD_2_PI;
    }

    while(rad < (-MATH_TRIG_RAD_PI))
    {
        rad += MATH_TRIG_RAD_2_PI;
    } 

    return rad;
}


float Math_Trig_RadToDegs(float rad)
{
    return rad * MATH_TRIG_180_DEG / MATH_TRIG_RAD_PI;
}

/***********************************************************************************************************
 ******************************************** Local functions **********************************************
 ***********************************************************************************************************/

static float Math_Trig_HastingsArctan(float input)
{
    float in_pow_2 = input * input;
    float in_pow_3 = input * in_pow_2;
    float in_pow_5 = in_pow_2 * in_pow_3;

    return ((MATH_TRIG_HASTINGS_COEF_1 * input) - (MATH_TRIG_HASTINGS_COEF_2 * in_pow_3) + (MATH_TRIG_HASTINGS_COEF_3 * in_pow_5));
}
