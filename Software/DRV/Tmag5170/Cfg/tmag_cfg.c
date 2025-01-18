// /***********************************************************************************************************
//  ********************************************* Included files **********************************************
//  ***********************************************************************************************************/

// #include "tmag_cfg.h"
// #include "SPI_MASTER/spi_master.h"
// #include "DIGITAL_IO/digital_io.h"

// /***********************************************************************************************************
//  ************************************************* Defines *************************************************
//  ***********************************************************************************************************/

// /***********************************************************************************************************
//  *********************************************** Data types ************************************************
//  ***********************************************************************************************************/

// /***********************************************************************************************************
//  **************************************** Local function prototypes ****************************************
//  ***********************************************************************************************************/

// static void Tmag_DataTransferStartSensor0(uint8_t* tx_data_ptr, uint8_t* rx_data_ptr);
// static void Tmag_DataTransferStartSensor1(uint8_t* tx_data_ptr, uint8_t* rx_data_ptr);
// static void Tmag_DataTransferStopSensor0(void);
// static void Tmag_DataTransferStopSensor1(void);
// static bool Tmag_IsDataTransferBusySensor0(void);
// static bool Tmag_IsDataTransferBusySensor1(void);

// /***********************************************************************************************************
//  ******************************************** Exported objects *********************************************
//  ***********************************************************************************************************/

// Tmag_Config_t Tmag_Config[TMAG_SENSOR_NBR_MAX] = 
// {
//     /* SENSOR 0 */
//     {
//         /* DEVICE_CONFIG */
//         .device.field.t_hlt_en = TMAG_T_HLT_EN_OFF,
//         .device.field.t_rate = TMAG_T_RATE_SAME_AS_OTHERS,
//         .device.field.r_ch_en = TMAG_T_CH_EN_ENABLED,
//         .device.field.operating_mode = TMAG_OPERATING_MODE_ACTIVE_MEASURE,
//         .device.field.mag_tempco = TMAG_MAG_TEMPCO_0_12_DEG,
//         .device.field.conv_avg = TMAG_MAG_CONV_AVG_8X,
        
//         /* SENSOR_CONFIG */
//         .sensor.field.x_range = TMAG_X_RANGE_100_MT,
//         .sensor.field.y_range = TMAG_Y_RANGE_100_MT,
//         .sensor.field.z_range = TMAG_Z_RANGE_100_MT,
//         .sensor.field.mag_ch_en = TMAG_MAG_CH_EN_XYZ,
//         .sensor.field.sleep_time = 0U,
//         .sensor.field.angle_en = TMAG_DATA_ANGLE_EN_XY,

//         /* SYSTEM_CONFIG */
//         .system.field.x_hlt_en = TMAG_X_HLT_EN_OFF,
//         .system.field.y_hlt_en = TMAG_Y_HLT_EN_OFF,
//         .system.field.z_hlt_en = TMAG_Z_HLT_EN_OFF,
//         .system.field.diag_en = TMAG_DIAG_EN_DISABLED,
//         .system.field.data_type = TMAG_DATA_TYPE_DEFAULT,
//         .system.field.trigger_mode = 0U,
//         .system.field.diag_sel = TMAG_DIAG_SEL_ALL_TOGETHER,

//         /* ALERT_CONFIG */
//         .alert.value = 0U,       /* Reset value */

//         /* X_THRX_CONFIG */
//         .x_thrx.value = 0x7D83,  /* Reset value */

//         /* Y_THRX_CONFIG */
//         .y_thrx.value = 0x7D83,  /* Reset value */

//         /* Z_THRX_CONFIG */
//         .z_thrx.value = 0x7D83,  /* Reset value */

//         /* T_THRX_CONFIG */
//         .t_thrx.value = 0x6732,  /* Reset value */

//         /* MAG_GAIN_CONFIG */
//         .mag_gain.field.gain_selection = TMAG_GAIN_SELECTION_Y,
//         .mag_gain.field.gain_value = 449U,

//         /* Data transfer */
//         .data_transfer_start = Tmag_DataTransferStartSensor0,
//         .data_transfer_stop = Tmag_DataTransferStopSensor0,
//         .is_data_transfer_busy = Tmag_IsDataTransferBusySensor0,
//     },
//     /* SENSOR 1 */
//     {
//         /* DEVICE_CONFIG */
//         .device.field.t_hlt_en = TMAG_T_HLT_EN_OFF,
//         .device.field.t_rate = TMAG_T_RATE_SAME_AS_OTHERS,
//         .device.field.r_ch_en = TMAG_T_CH_EN_ENABLED,
//         .device.field.operating_mode = TMAG_OPERATING_MODE_ACTIVE_MEASURE,
//         .device.field.mag_tempco = TMAG_MAG_TEMPCO_0_12_DEG,
//         .device.field.conv_avg = TMAG_MAG_CONV_AVG_8X,
        
//         /* SENSOR_CONFIG */
//         .sensor.field.x_range = TMAG_X_RANGE_50_MT,
//         .sensor.field.y_range = TMAG_Y_RANGE_50_MT,
//         .sensor.field.z_range = TMAG_Z_RANGE_50_MT,
//         .sensor.field.mag_ch_en = TMAG_MAG_CH_EN_XYZ,
//         .sensor.field.sleep_time = 0U,
//         .sensor.field.angle_en = TMAG_DATA_ANGLE_EN_XY,

//         /* SYSTEM_CONFIG */
//         .system.field.x_hlt_en = TMAG_X_HLT_EN_OFF,
//         .system.field.y_hlt_en = TMAG_Y_HLT_EN_OFF,
//         .system.field.z_hlt_en = TMAG_Z_HLT_EN_OFF,
//         .system.field.diag_en = TMAG_DIAG_EN_DISABLED,
//         .system.field.data_type = TMAG_DATA_TYPE_DEFAULT,
//         .system.field.trigger_mode = 0U,
//         .system.field.diag_sel = TMAG_DIAG_SEL_ALL_TOGETHER,

//         /* ALERT_CONFIG */
//         .alert.value = 0U,       /* Reset value */

//         /* X_THRX_CONFIG */
//         .x_thrx.value = 0x7D83,  /* Reset value */

//         /* Y_THRX_CONFIG */
//         .y_thrx.value = 0x7D83,  /* Reset value */

//         /* Z_THRX_CONFIG */
//         .z_thrx.value = 0x7D83,  /* Reset value */

//         /* T_THRX_CONFIG */
//         .t_thrx.value = 0x6732,  /* Reset value */

//         /* MAG_GAIN_CONFIG */
//         .mag_gain.field.gain_selection = TMAG_GAIN_SELECTION_Y,
//         .mag_gain.field.gain_value = 974U,

//         /* Data transfer */
//         .data_transfer_start = Tmag_DataTransferStartSensor1,
//         .data_transfer_stop = Tmag_DataTransferStopSensor1,
//         .is_data_transfer_busy = Tmag_IsDataTransferBusySensor1
//     }
// };

// /***********************************************************************************************************
//  ********************************************* Local objects ***********************************************
//  ***********************************************************************************************************/

// /***********************************************************************************************************
//  ******************************************* Exported functions ********************************************
//  ***********************************************************************************************************/

// /***********************************************************************************************************
//  ******************************************** Local functions **********************************************
//  ***********************************************************************************************************/

// /** @brief The functions triggers the SPI data transmission process for sensor 0. 
//  *         When the transmission is complete, call the Tmag_TransferReady() function.
//  *  @param tx_data_ptr Tx data pointer. It should contain 4 bytes of data.
//  *  @param rx_data_ptr Rx data pointer. It should contains 4 bytes of data.
//  *  @return void
//  */
// static void Tmag_DataTransferStartSensor0(uint8_t* tx_data_ptr, uint8_t* rx_data_ptr)
// {
//     DIGITAL_IO_SetOutputLow(&PIN_SPI1_CS0);
//     (void)SPI_MASTER_Transfer(&SPI1_EXT_ENCODER, tx_data_ptr, rx_data_ptr, 4U);
// }

// /** @brief The functions triggers the SPI data transmission process for sensor 1. 
//  *         When the transmission is complete, call the Tmag_TransferReady() function.
//  *  @param tx_data_ptr Tx data pointer. It should contain 4 bytes of data.
//  *  @param rx_data_ptr Rx data pointer. It should contains 4 bytes of data.
//  *  @return void
//  */
// static void Tmag_DataTransferStartSensor1(uint8_t* tx_data_ptr, uint8_t* rx_data_ptr)
// {
//     DIGITAL_IO_SetOutputLow(&PIN_SPI1_CS1);
//     (void)SPI_MASTER_Transfer(&SPI1_EXT_ENCODER, tx_data_ptr, rx_data_ptr, 4U);
// }

// static void Tmag_DataTransferStopSensor0(void)
// {
//     DIGITAL_IO_SetOutputHigh(&PIN_SPI1_CS0);
// }

// static void Tmag_DataTransferStopSensor1(void)
// {
//     DIGITAL_IO_SetOutputHigh(&PIN_SPI1_CS1);
// }

// static bool Tmag_IsDataTransferBusySensor0(void)
// {
//     return SPI_MASTER_IsRxBusy(&SPI1_EXT_ENCODER);
// }

// static bool Tmag_IsDataTransferBusySensor1(void)
// {
//     return SPI_MASTER_IsRxBusy(&SPI1_EXT_ENCODER);
// }
