/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include "hal_adc_if.h"

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 **************************************** Local function prototypes ****************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ******************************************** Exported objects *********************************************
 ***********************************************************************************************************/

/* 
 * ADC group configuration: instance -> instance_idx -> handler for every group
 */
const Hal_Adc_Config_t Hal_Adc_Config[HAL_ADC_GROUP_MAX] = 
{
    /* Group 0 */
    {
        /* Instances - channel 0 to 7 */
        { 
            HAL_ADC_INSTANCE_ENC, 
            HAL_ADC_INSTANCE_ENC,
            HAL_ADC_UNUSED,
            HAL_ADC_UNUSED,
            HAL_ADC_INSTANCE_CURR_SENSE,
            HAL_ADC_INSTANCE_CURR_SENSE,
            HAL_ADC_INSTANCE_BEMF,
            HAL_ADC_UNUSED
        },  
        /* Indexes - channel 0 to 7 */
        { 
            HAL_ADC_ENC_SIN_P_IDX,
            HAL_ADC_ENC_SIN_N_IDX,
            HAL_ADC_UNUSED,
            HAL_ADC_UNUSED,
            HAL_ADC_CURR_SENSE_OUT2_IDX,
            HAL_ADC_CURR_SENSE_OUT1_IDX,
            HAL_ADC_BEMF_N_P_IDX,
            HAL_ADC_UNUSED
        },
        /* Handlers - channel 0 to 7 */
        {
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G0_ADC_G0CH0_ENC_SIN_P_handle,
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G0_ADC_G0CH1_ENC_SIN_N_handle,
            (void*)0,
            (void*)0,
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G0_ADC_G0CH4_CURR_SENSE_OUT_2_handle,
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G0_ADC_G0CH5_CURR_SENSE_OUT_1_handle,
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G0_ADC_G0CH6_BEMF_N_P_handle,
            (void*)0
        }
    },
    /* Group 1 */
    {
        /* Instances - channel 0 to 7 */
        {
            HAL_ADC_INSTANCE_ENC,
            HAL_ADC_INSTANCE_ENC,
            HAL_ADC_INSTANCE_CURR_SENSE,
            HAL_ADC_INSTANCE_CURR_SENSE,
            HAL_ADC_INSTANCE_BEMF,
            HAL_ADC_INSTANCE_BEMF,
            HAL_ADC_INSTANCE_BEMF,
            HAL_ADC_INSTANCE_ENC
        },
        /* Indexes - channel 0 to 7 */
        { 
            HAL_ADC_ENC_COS_P_IDX,
            HAL_ADC_ENC_COS_N_IDX,
            HAL_ADC_CURR_SENSE_OUT4_IDX,
            HAL_ADC_CURR_SENSE_OUT3_IDX,
            HAL_ADC_BEMF_A_IDX,
            HAL_ADC_BEMF_B_IDX,
            HAL_ADC_BEMF_C_IDX,
            HAL_ADC_ENC_TO_IDX
        },
        /* Handlers - channel 0 to 7 */
        {
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G1_ADC_G1CH0_ENC_COS_P_handle,
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G1_ADC_G1CH1_ENC_COS_N_handle,
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G1_ADC_G1CH2_CURR_SENSE_OUT_4_handle,
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G1_ADC_G1CH3_CURR_SENSE_OUT_3_handle,
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G1_ADC_G1CH4_BEMF_A_handle,
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G1_ADC_G1CH5_BEMF_B_handle,
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G1_ADC_G1CH6_BEMF_C_handle,
            (ADC_MEASUREMENT_ADV_CHANNEL_t*)&ADC_G1_ADC_G1CH7_ENC_TO_handle
        }
    }
};

/***********************************************************************************************************
 ********************************************* Local objects ***********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ******************************************* Exported functions ********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ******************************************** Local functions **********************************************
 ***********************************************************************************************************/
