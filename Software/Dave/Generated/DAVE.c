
/**
 * @cond
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
 * 2014-06-16:
 *     - Initial version<br>
 * 2015-08-28:
 *     - Added CLOCK_XMC1_Init conditionally
 * 2018-08-08:
 *     - Add creation of projectData.bak file
 * 2019-01-30:
 *     - Fix creation of projectData.bak file
 * 2019-04-29:
 *     - Make DAVE_Init() weak, the user can reimplement the function
 *
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "DAVE.h"

/***********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/

/*******************************************************************************
 * @brief This function initializes the APPs Init Functions.
 *
 * @param[in]  None
 *
 * @return  DAVE_STATUS_t <BR>
 ******************************************************************************/
__WEAK DAVE_STATUS_t DAVE_Init(void)
{
  DAVE_STATUS_t init_status;
  
  init_status = DAVE_STATUS_SUCCESS;
     /** @Initialization of APPs Init Functions */
     init_status = (DAVE_STATUS_t)CLOCK_XMC4_Init(&CLOCK_XMC4_0);

  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance PIN_SPI1_CS0 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&PIN_SPI1_CS0); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance PIN_SPI1_CS1 */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&PIN_SPI1_CS1); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of PWM_CCU4 APP instance PWM_GATE_DRV_HC */
	 init_status = (DAVE_STATUS_t)PWM_CCU4_Init(&PWM_GATE_DRV_HC); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of PWM_CCU4 APP instance PWM_GATE_DRV_HB */
	 init_status = (DAVE_STATUS_t)PWM_CCU4_Init(&PWM_GATE_DRV_HB); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of PWM_CCU8 APP instance PWM_GATE_DRV_LA */
	 init_status = (DAVE_STATUS_t)PWM_CCU8_Init(&PWM_GATE_DRV_LA); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of PWM_CCU8 APP instance PWM_GATE_DRV_LB */
	 init_status = (DAVE_STATUS_t)PWM_CCU8_Init(&PWM_GATE_DRV_LB); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of PWM_CCU8 APP instance PWM_GATE_DRV_HA */
	 init_status = (DAVE_STATUS_t)PWM_CCU8_Init(&PWM_GATE_DRV_HA); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of PWM_CCU8 APP instance PWM_GATE_DRV_LC */
	 init_status = (DAVE_STATUS_t)PWM_CCU8_Init(&PWM_GATE_DRV_LC); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of ADC_MEASUREMENT_ADV APP instance ADC_G0 */
	 init_status = (DAVE_STATUS_t)ADC_MEASUREMENT_ADV_Init(&ADC_G0); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of ADC_MEASUREMENT_ADV APP instance ADC_G1 */
	 init_status = (DAVE_STATUS_t)ADC_MEASUREMENT_ADV_Init(&ADC_G1); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of TIMER APP instance TIM_COMMUTATION */
	 init_status = (DAVE_STATUS_t)TIMER_Init(&TIM_COMMUTATION); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of INTERRUPT APP instance INT_TIM_COMMUTATION */
	 init_status = (DAVE_STATUS_t)INTERRUPT_Init(&INT_TIM_COMMUTATION); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of TIMER APP instance TIM_SYSTEM */
	 init_status = (DAVE_STATUS_t)TIMER_Init(&TIM_SYSTEM); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of INTERRUPT APP instance INT_TIM_SYSTEM */
	 init_status = (DAVE_STATUS_t)INTERRUPT_Init(&INT_TIM_SYSTEM); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of PWM_CCU4 APP instance PWM_BEMF_TRIG */
	 init_status = (DAVE_STATUS_t)PWM_CCU4_Init(&PWM_BEMF_TRIG); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance PIN_DEBUG */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&PIN_DEBUG); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of UART APP instance UART_0 */
	 init_status = (DAVE_STATUS_t)UART_Init(&UART_0); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance PIN_ENC_ZERO */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&PIN_ENC_ZERO); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of DIGITAL_IO APP instance PIN_ENC_MAG */
	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&PIN_ENC_MAG); 
   } 
  if (init_status == DAVE_STATUS_SUCCESS)
  {
	 /**  Initialization of I2C_MASTER APP instance I2C_ENC */
	 init_status = (DAVE_STATUS_t)I2C_MASTER_Init(&I2C_ENC); 
   }  
  return init_status;
} /**  End of function DAVE_Init */

