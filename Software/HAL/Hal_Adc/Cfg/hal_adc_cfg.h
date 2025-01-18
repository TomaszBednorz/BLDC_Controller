#ifndef _HAL_ADC_CFG_H_
#define _HAL_ADC_CFG_H_

/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include <stdint.h>

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

#define HAL_ADC_UNUSED          (0xFF)

/* HAL_ADC_INSTANCE_ENC indexes */
#define HAL_ADC_ENC_SIN_P_IDX   (0U)
#define HAL_ADC_ENC_SIN_N_IDX   (1U)
#define HAL_ADC_ENC_COS_P_IDX   (2U)
#define HAL_ADC_ENC_COS_N_IDX   (3U)
#define HAL_ADC_ENC_TO_IDX      (4U)
#define HAL_ADC_ENC_IDX_MAX     (5U)

/* HAL_ADC_INSTANCE_CURR_SENSE indexes */
#define HAL_ADC_CURR_SENSE_OUT1_IDX   (0U)
#define HAL_ADC_CURR_SENSE_OUT2_IDX   (1U)
#define HAL_ADC_CURR_SENSE_OUT3_IDX   (2U)
#define HAL_ADC_CURR_SENSE_OUT4_IDX   (3U)
#define HAL_ADC_CURR_SENSE_IDX_MAX    (4U)

/* HAL_ADC_INSTANCE_BEMF indexes */
#define HAL_ADC_BEMF_A_IDX     (0U)
#define HAL_ADC_BEMF_B_IDX     (1U)
#define HAL_ADC_BEMF_C_IDX     (2U)
#define HAL_ADC_BEMF_N_P_IDX   (3U)
#define HAL_ADC_BEMF_IDX_MAX   (4U)

#define HAL_ADC_INSTANCE_MAX_LEN  (HAL_ADC_ENC_IDX_MAX)

/* ADC groups */
#define HAL_ADC_GROUP_0     (0U)
#define HAL_ADC_GROUP_1     (1U)
#define HAL_ADC_GROUP_MAX   (2U)

#define HAL_ADC_CHANNEL_MAX   (8U)

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

typedef enum
{
    HAL_ADC_INSTANCE_ENC = 0U,
    HAL_ADC_INSTANCE_CURR_SENSE,
    HAL_ADC_INSTANCE_BEMF,
    HAL_ADC_INSTANCE_MAX
}Hal_Adc_Instance_t;

/***********************************************************************************************************
 ********************************************* Exported objects ********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ************************************** Exported function prototypes ***************************************
 ***********************************************************************************************************/

#endif  /* _HAL_ADC_CFG_H_ */
