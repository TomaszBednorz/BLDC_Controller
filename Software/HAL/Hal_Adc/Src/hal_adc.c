/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include "hal_adc.h"
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

/***********************************************************************************************************
 ********************************************* Local objects ***********************************************
 ***********************************************************************************************************/

static uint16_t Hal_Adc_Results[HAL_ADC_INSTANCE_MAX][HAL_ADC_INSTANCE_MAX_LEN];

/***********************************************************************************************************
 ******************************************* Exported functions ********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ******************************************** Local functions **********************************************
 ***********************************************************************************************************/

uint16_t bemf_a[10000] = {0};
uint16_t bemf_b[10000] = {0};
uint16_t bemf_c[10000] = {0};
uint16_t bemf_n[10000] = {0};
uint32_t cnt = 0;
uint8_t flags[2] = {0, 0};


void Hal_Adc_ConversionReady(uint8_t adc_group)
{
    for(uint8_t i = 0U; i < HAL_ADC_CHANNEL_MAX; i++)
    {
        if( Hal_Adc_Config[adc_group].instance[i] != HAL_ADC_UNUSED)
        {
            Hal_Adc_Results[Hal_Adc_Config[adc_group].instance[i]][Hal_Adc_Config[adc_group].idx[i]] = ADC_MEASUREMENT_ADV_GetResult(Hal_Adc_Config[adc_group].handler[i]);
        }
    }

    // if(cnt < 10000)
    // {
    //     if(adc_group == HAL_ADC_GROUP_0)
    //     {
    //         bemf_n[cnt] = Hal_Adc_Results[HAL_ADC_INSTANCE_BEMF][HAL_ADC_BEMF_N_P_IDX];
    //         flags[0] = 1;
    //     }
    //     else
    //     {
    //         bemf_a[cnt] = Hal_Adc_Results[HAL_ADC_INSTANCE_BEMF][HAL_ADC_BEMF_A_IDX];
    //         bemf_b[cnt] = Hal_Adc_Results[HAL_ADC_INSTANCE_BEMF][HAL_ADC_BEMF_B_IDX];
    //         bemf_c[cnt] = Hal_Adc_Results[HAL_ADC_INSTANCE_BEMF][HAL_ADC_BEMF_C_IDX];
    //         flags[1] = 1;
    //     }

    //     if(flags[0] == 1 && flags[1] == 1)
    //     {
    //         flags[0] = 0;
    //         flags[1] = 0;
    //         cnt++;
    //     }
    // }
}

void Hal_Adc_GetData(Hal_Adc_Instance_t instance, uint16_t* buffer)
{
    uint8_t instance_len = 0U;

    switch (instance)
    {
        case HAL_ADC_INSTANCE_ENC:
            instance_len = HAL_ADC_ENC_IDX_MAX;
            break;
        case HAL_ADC_INSTANCE_CURR_SENSE:
            instance_len = HAL_ADC_CURR_SENSE_IDX_MAX;
            break;
        case HAL_ADC_INSTANCE_BEMF:
            instance_len = HAL_ADC_BEMF_IDX_MAX;
            break;
        default:
            break;
    }

    for(uint8_t i = 0U; i < instance_len; i++)
    {
        buffer[i] = Hal_Adc_Results[instance][i];
    }
}