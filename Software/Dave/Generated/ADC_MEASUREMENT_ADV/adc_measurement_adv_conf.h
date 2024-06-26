/*********************************************************************************************************************
* DAVE APP Name : ADC_MEASUREMENT_ADV       APP Version: 4.0.20
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/* @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015-2020, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-10-09:
 *     - Initial version for DAVEv4.<BR>
 *
 * 2015-10-20:
 *     - Documentation updated.<BR>
 *
 * 2015-12-15:
 *     - Added support for XMC4300 devices.<BR>
 *
 * 2016-01-18:
 *     - 1.Internal consumption of request source.<BR>
 *     - 2.Support for synchronized conversion reduced from 8 master channels to 4 .<BR>
 *     - 3.Converted the SetBoundary() API from public API to private API .<BR>
 *     - 4.Updated all APIs for the Internal consumption of request source.<BR>
 * 
 *
 * 2016-02-05:
 *     - Documentation updated.<BR>
 * 
 * 2016-03-18:
 *     - Added consumption of the GLOBAL ICLASS -1 for Sync. Conversions.<BR>
 *     - Added consumption of the result register-0 for subtraction mode.<BR>
 *     - Removed ADC_MEASUREMENT_ADV_SetUniformConversion().<BR>
 *     - New API ADC_MEASUREMENT_ADV_SetIclass() added to configure the GLOBAL ICLASS for Slaves. <BR>
 *
 * 2016-04-26:
 *     - The synchronized conversion in a master slave configuration is currently not supported.<BR>
 *
 * 2016-06-17:
 *     - The synchronized conversion is supported.<BR>
 *     - Modified the Sync initialization sequence to configure the EVAL bits in the slave groups.<BR>
 *
 * 2016-08-18:
 *     - Minimum sample time at low frequencies changed to incorporate Errata ADC_AI.H006 and ADC_AI.H007.
 *
 * @endcond
 *
 *
 */

#ifndef ADC_MEASUREMENT_ADV_CONF_H
#define ADC_MEASUREMENT_ADV_CONF_H

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/


/* If a scan request source is used by any of the ADC_MEASUREMENT_ADV APP
 * Instances this macro is generated*/
#define ADC_MEASUREMENT_ADV_SCAN_USED (1U)

/* If SHS gain apart from 1:1 is needed and an alias channel is used by one of 
 * the ADC_MEASUREMENT_ADV APP Instances this macro is generated. Needed for correct configuration of the gain value.*/
#define ADC_MEASUREMENT_ADV_SHS_GAIN_ALIAS (1U)

/* If FIFO is not used by any of the ADC_MEASUREMENT_ADV APP
 * Instances this macro is generated. The Result register configuration holds only one config structure.*/
#define ADC_MEASUREMENT_ADV_RESULT_REG (1U)

/* If Internal consumption of scan request source takes place in any of the ADC_MEASUREMENT_ADV APP
 * Instances this macro is generated.*/
#define ADC_MEASUREMENT_ADV_LOCAL_SCAN_USED (1U)

/* If Start after initialization is used by any of the ADC_MEASUREMENT_ADV APP
 * Instances this macro is generated.*/
#define ADC_MEASUREMENT_ADV_START_ADC (1U)


 /* Channel and result related macros for the instance ADC_G0*/
#define ADC_G0_GROUP_PTR  ((XMC_VADC_GROUP_t*)(void*) VADC_G0)

#define ADC_G0_ADC_G0CH0_ENC_SIN_P  (ADC_G0_ADC_G0CH0_ENC_SIN_P_handle)
#define ADC_G0_ADC_G0CH0_ENC_SIN_P_RES  (VADC_G0->RES[15])

#define ADC_IrqGroup0Callback IRQ_Hdlr_19
#define ADC_G0_ADC_G0CH1_ENC_SIN_N  (ADC_G0_ADC_G0CH1_ENC_SIN_N_handle)
#define ADC_G0_ADC_G0CH1_ENC_SIN_N_RES  (VADC_G0->RES[4])

#define ADC_IrqGroup0Callback IRQ_Hdlr_19
#define ADC_G0_ADC_G0CH4_CURR_SENSE_OUT_2  (ADC_G0_ADC_G0CH4_CURR_SENSE_OUT_2_handle)
#define ADC_G0_ADC_G0CH4_CURR_SENSE_OUT_2_RES  (VADC_G0->RES[5])

#define ADC_IrqGroup0Callback IRQ_Hdlr_19
#define ADC_G0_ADC_G0CH5_CURR_SENSE_OUT_1  (ADC_G0_ADC_G0CH5_CURR_SENSE_OUT_1_handle)
#define ADC_G0_ADC_G0CH5_CURR_SENSE_OUT_1_RES  (VADC_G0->RES[8])

#define ADC_IrqGroup0Callback IRQ_Hdlr_19
#define ADC_G0_ADC_G0CH6_BEMF_N_P  (ADC_G0_ADC_G0CH6_BEMF_N_P_handle)
#define ADC_G0_ADC_G0CH6_BEMF_N_P_RES  (VADC_G0->RES[9])

#define ADC_IrqGroup0Callback IRQ_Hdlr_19
 /* Channel and result related macros for the instance ADC_G1*/
#define ADC_G1_GROUP_PTR  ((XMC_VADC_GROUP_t*)(void*) VADC_G1)

#define ADC_G1_ADC_G1CH0_ENC_COS_P  (ADC_G1_ADC_G1CH0_ENC_COS_P_handle)
#define ADC_G1_ADC_G1CH0_ENC_COS_P_RES  (VADC_G1->RES[13])

#define ADC_IrqGroup1Callback IRQ_Hdlr_25
#define ADC_G1_ADC_G1CH1_ENC_COS_N  (ADC_G1_ADC_G1CH1_ENC_COS_N_handle)
#define ADC_G1_ADC_G1CH1_ENC_COS_N_RES  (VADC_G1->RES[12])

#define ADC_IrqGroup1Callback IRQ_Hdlr_25
#define ADC_G1_ADC_G1CH2_CURR_SENSE_OUT_4  (ADC_G1_ADC_G1CH2_CURR_SENSE_OUT_4_handle)
#define ADC_G1_ADC_G1CH2_CURR_SENSE_OUT_4_RES  (VADC_G1->RES[7])

#define ADC_IrqGroup1Callback IRQ_Hdlr_25
#define ADC_G1_ADC_G1CH3_CURR_SENSE_OUT_3  (ADC_G1_ADC_G1CH3_CURR_SENSE_OUT_3_handle)
#define ADC_G1_ADC_G1CH3_CURR_SENSE_OUT_3_RES  (VADC_G1->RES[2])

#define ADC_IrqGroup1Callback IRQ_Hdlr_25
#define ADC_G1_ADC_G1CH4_BEMF_A  (ADC_G1_ADC_G1CH4_BEMF_A_handle)
#define ADC_G1_ADC_G1CH4_BEMF_A_RES  (VADC_G1->RES[1])

#define ADC_IrqGroup1Callback IRQ_Hdlr_25
#define ADC_G1_ADC_G1CH5_BEMF_B  (ADC_G1_ADC_G1CH5_BEMF_B_handle)
#define ADC_G1_ADC_G1CH5_BEMF_B_RES  (VADC_G1->RES[0])

#define ADC_IrqGroup1Callback IRQ_Hdlr_25
#define ADC_G1_ADC_G1CH6_BEMF_C  (ADC_G1_ADC_G1CH6_BEMF_C_handle)
#define ADC_G1_ADC_G1CH6_BEMF_C_RES  (VADC_G1->RES[15])

#define ADC_IrqGroup1Callback IRQ_Hdlr_25
#define ADC_G1_ADC_G1CH7_ENC_TO  (ADC_G1_ADC_G1CH7_ENC_TO_handle)
#define ADC_G1_ADC_G1CH7_ENC_TO_RES  (VADC_G1->RES[3])

#define ADC_IrqGroup1Callback IRQ_Hdlr_25
#define ADC_MEASUREMENT_ADV_GLOBAL_HANDLE ((GLOBAL_ADC_t *)(void *) &GLOBAL_ADC_0)


#define ADC_MEASUREMENT_ADV_MAJOR_VERSION (4U) /**< Major version number of ADC_MEASUREMENT_ADV APP*/
#define ADC_MEASUREMENT_ADV_MINOR_VERSION (0U) /**< Minor version number of ADC_MEASUREMENT_ADV APP*/
#define ADC_MEASUREMENT_ADV_PATCH_VERSION (20U) /**< Patch version number of ADC_MEASUREMENT_ADV APP*/

  
#endif /* _ADC_MEASUREMENT_ADV_CONF_H_ */

