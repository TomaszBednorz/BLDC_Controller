#ifndef _HAL_ADC_H_
#define _HAL_ADC_H_

/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include <stdint.h>
#include "hal_adc.h"
#include "hal_adc_cfg.h"

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ********************************************* Exported objects ********************************************
 ***********************************************************************************************************/

extern uint8_t my_flag;

/***********************************************************************************************************
 ************************************** Exported function prototypes ***************************************
 ***********************************************************************************************************/

void Hal_Adc_ConversionReady(uint8_t adc_group);
void Hal_Adc_GetInstanceData(Hal_Adc_Instance_t data_type, uint16_t* buffer);
uint16_t Hal_Adc_GetSingleData(Hal_Adc_Instance_t data_type, uint8_t idx);

#endif  /* _HAL_ADC_H_ */
