// #ifndef _TMAG_REG_H_
// #define _TMAG_REG_H_

// #include <stdint.h>

// typedef uint16_t Tmag_Data_t;

// /*
//  * TMAG5170 Registers
//  */
// typedef enum
// {
//     TMAG_DEVICE_CONFIG = 0U,
//     TMAG_SENSOR_CONFIG,
//     TMAG_SYSTEM_CONFIG,
//     TMAG_ALERT_CONFIG,
//     TMAG_X_THRX_CONFIG,
//     TMAG_Y_THRX_CONFIG,
//     TMAG_Z_THRX_CONFIG,
//     TMAG_T_THRX_CONFIG,
//     TMAG_CONV_STATUS,
//     TMAG_X_CH_RESULT,
//     TMAG_Y_CH_RESULT,
//     TMAG_Z_CH_RESULT,
//     TMAG_TEMP_RESULT,
//     TMAG_AFE_STATUS,
//     TMAG_SYS_STATUS,
//     TMAG_TEST_CONFIG,
//     TMAG_OSC_MONITOR,
//     TMAG_MAG_GAIN_CONFIG,
//     TMAG_MAG_OFFSET_CONFIG,
//     TMAG_DATA_ANGLE_RESULT,
//     TMAG_MAGNITUDE_RESULT
// }Tmag_Register_t;

// /* 
//  * TMAG5170 DEVICE_CONFIG Register (Offset = 0h) 
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t res0           : 1;
//         uint16_t t_hlt_en       : 1;
//         uint16_t t_rate         : 1;
//         uint16_t r_ch_en        : 1;
//         uint16_t operating_mode : 3;
//         uint16_t res1           : 1; 
//         uint16_t mag_tempco     : 2; 
//         uint16_t res2           : 2; 
//         uint16_t conv_avg       : 3; 
//         uint16_t res3           : 1; 
//     }field;
// }Tmag_RegDeviceConfig_t;

// #define TMAG_T_HLT_EN_OFF  (0U)
// #define TMAG_T_HLT_EN_ON   (1U)

// #define TMAG_T_RATE_SAME_AS_OTHERS  (0U)
// #define TMAG_T_RATE_ONCE_PER_CONV   (1U)

// #define TMAG_T_CH_EN_DISABLED   (0U)
// #define TMAG_T_CH_EN_ENABLED    (1U)

// #define TMAG_OPERATING_MODE_CONFIGURATION      (0U)
// #define TMAG_OPERATING_MODE_STAND_BY           (1U)
// #define TMAG_OPERATING_MODE_ACTIVE_MEASURE     (2U)
// #define TMAG_OPERATING_MODE_ACTIVE_TRIGGER     (3U)
// #define TMAG_OPERATING_MODE_WAKE_UP_AND_SLEEP  (4U)
// #define TMAG_OPERATING_MODE_SLEEP              (5U)
// #define TMAG_OPERATING_MODE_DEEP_SLEEP         (6U)

// #define TMAG_MAG_TEMPCO_0_00_DEG  (0U)
// #define TMAG_MAG_TEMPCO_0_12_DEG  (1U)
// #define TMAG_MAG_TEMPCO_0_03_DEG  (2U)
// #define TMAG_MAG_TEMPCO_0_20_DEG  (3U)

// #define TMAG_MAG_CONV_AVG_1X   (0U)
// #define TMAG_MAG_CONV_AVG_2X   (1U)
// #define TMAG_MAG_CONV_AVG_4X   (2U)
// #define TMAG_MAG_CONV_AVG_8X   (3U)
// #define TMAG_MAG_CONV_AVG_16X  (4U)
// #define TMAG_MAG_CONV_AVG_32X  (5U)

// /* 
//  * TMAG5170 SENSOR_CONFIG Register (Offset = 1h)
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t x_range    : 2;
//         uint16_t y_range    : 2;
//         uint16_t z_range    : 2;
//         uint16_t mag_ch_en  : 4;
//         uint16_t sleep_time : 4;
//         uint16_t angle_en   : 2; 
//     }field;
// }Tmag_RegSensorConfig_t;

// #define TMAG_X_RANGE_50_MT   (0U)
// #define TMAG_X_RANGE_25_MT   (1U)
// #define TMAG_X_RANGE_100_MT  (2U)

// #define TMAG_Y_RANGE_50_MT   (0U)
// #define TMAG_Y_RANGE_25_MT   (1U)
// #define TMAG_Y_RANGE_100_MT  (2U)

// #define TMAG_Z_RANGE_50_MT   (0U)
// #define TMAG_Z_RANGE_25_MT   (1U)
// #define TMAG_Z_RANGE_100_MT  (2U)

// #define TMAG_MAG_CH_EN_OFF     (0U)
// #define TMAG_MAG_CH_EN_X       (1U)
// #define TMAG_MAG_CH_EN_Y       (2U)
// #define TMAG_MAG_CH_EN_XY      (3U)
// #define TMAG_MAG_CH_EN_Z       (4U)
// #define TMAG_MAG_CH_EN_ZX      (5U)
// #define TMAG_MAG_CH_EN_YZ      (6U)
// #define TMAG_MAG_CH_EN_XYZ     (7U)
// #define TMAG_MAG_CH_EN_XYX     (8U)
// #define TMAG_MAG_CH_EN_YXY     (9U)
// #define TMAG_MAG_CH_EN_YZY     (10U)
// #define TMAG_MAG_CH_EN_ZYZ     (11U)
// #define TMAG_MAG_CH_EN_ZXZ     (12U)
// #define TMAG_MAG_CH_EN_XZX     (13U)
// #define TMAG_MAG_CH_EN_XYZYX   (14U)
// #define TMAG_MAG_CH_EN_XYZZYX  (15U)

// #define TMAG_SLEEP_TIME_1MS     (0U)
// #define TMAG_SLEEP_TIME_5MS     (1U)
// #define TMAG_SLEEP_TIME_10MS    (2U)
// #define TMAG_SLEEP_TIME_15MS    (3U)
// #define TMAG_SLEEP_TIME_20MS    (4U)
// #define TMAG_SLEEP_TIME_30MS    (5U)
// #define TMAG_SLEEP_TIME_50MS    (6U)
// #define TMAG_SLEEP_TIME_100MS   (7U)
// #define TMAG_SLEEP_TIME_500MS   (8U)
// #define TMAG_SLEEP_TIME_1000MS  (9U)

// #define TMAG_DATA_ANGLE_EN_NO  (0U)
// #define TMAG_DATA_ANGLE_EN_XY  (1U)
// #define TMAG_DATA_ANGLE_EN_YZ  (2U)
// #define TMAG_DATA_ANGLE_EN_XZ  (3U)

// /* 
//  * TMAG5170 SYSTEM_CONFIG Register (Offset = 2h)
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t x_hlt_en     : 1;
//         uint16_t y_hlt_en     : 1;
//         uint16_t z_hlt_en     : 1;
//         uint16_t res0         : 2;
//         uint16_t diag_en      : 1;
//         uint16_t data_type    : 3; 
//         uint16_t trigger_mode : 2; 
//         uint16_t res1         : 2; 
//         uint16_t diag_sel     : 2; 
//         uint16_t res2         : 2; 
//     }field;
// }Tmag_RegSystemConfig_t;

// #define TMAG_X_HLT_EN_OFF  (0U)
// #define TMAG_X_HLT_EN_ON   (1U)

// #define TMAG_Y_HLT_EN_OFF  (0U)
// #define TMAG_Y_HLT_EN_ON   (1U)

// #define TMAG_Z_HLT_EN_OFF  (0U)
// #define TMAG_Z_HLT_EN_ON   (1U)

// #define TMAG_DIAG_EN_DISABLED  (0U)
// #define TMAG_DIAG_EN_ENABLED   (1U)

// #define TMAG_DATA_TYPE_DEFAULT   (0U)
// #define TMAG_DATA_TYPE_12BIT_XY  (1U)
// #define TMAG_DATA_TYPE_12BIT_XZ  (2U)
// #define TMAG_DATA_TYPE_12BIT_ZY  (3U)
// #define TMAG_DATA_TYPE_12BIT_XT  (4U)
// #define TMAG_DATA_TYPE_12BIT_YT  (5U)
// #define TMAG_DATA_TYPE_12BIT_ZT  (6U)
// #define TMAG_DATA_TYPE_12BIT_AM  (7U)

// #define TMAG_TRIGGER_MODE_SPI    (0U)
// #define TMAG_TRIGGER_MODE_CS     (1U)
// #define TMAG_TRIGGER_MODE_ALERT  (2U)

// #define TMAG_DIAG_SEL_ALL_TOGETHER              (0U)
// #define TMAG_DIAG_SEL_ONLY_ENABLED              (1U)
// #define TMAG_DIAG_SEL_ALL_IN_SEQUENCE           (2U)
// #define TMAG_DIAG_SEL_ONLY_ENABLED_IN_SEQUENCE  (3U)

// /* 
//  * TMAG5170 ALERT_CONFIG Register (Offset = 3h)
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t x_thrx_alrt : 1;
//         uint16_t y_thrx_alrt : 1;
//         uint16_t z_thrx_alrt : 1;
//         uint16_t t_thrx_alrt : 1;
//         uint16_t thrx_count  : 2;
//         uint16_t res0        : 2; 
//         uint16_t rslt_alrt   : 1; 
//         uint16_t res1        : 2; 
//         uint16_t status_alrt : 1; 
//         uint16_t alert_mode  : 1; 
//         uint16_t alert_latch : 1; 
//         uint16_t res2        : 2; 
//     }field;
// }Tmag_RegAlertConfig_t;

// #define TMAG_X_THRX_ALRT_NOT_USED  (0U)
// #define TMAG_X_THRX_ALRT_ASSERTED  (1U)

// #define TMAG_Y_THRX_ALRT_NOT_USED  (0U)
// #define TMAG_Y_THRX_ALRT_ASSERTED  (1U)

// #define TMAG_Z_THRX_ALRT_NOT_USED  (0U)
// #define TMAG_Z_THRX_ALRT_ASSERTED  (1U)

// #define TMAG_T_THRX_ALRT_NOT_USED  (0U)
// #define TMAG_T_THRX_ALRT_ASSERTED  (1U)

// #define TMAG_THRX_COUNT_1_CONV  (0U)
// #define TMAG_THRX_COUNT_2_CONV  (1U)
// #define TMAG_THRX_COUNT_3_CONV  (2U)
// #define TMAG_THRX_COUNT_4_CONV  (3U)

// #define TMAG_RSLT_ALRT_NOT_USED  (0U)
// #define TMAG_RSLT_ALRT_ASSERTED  (1U)

// #define TMAG_STATUS_ALRT_NOT_USED  (0U)
// #define TMAG_STATUS_ALRT_ASSERTED  (1U)

// #define TMAG_ALERT_MODE_INTERRUPT  (0U)
// #define TMAG_ALERT_MODE_SWITCH     (1U)

// #define TMAG_ALERT_LATCH_NOT_USED  (0U)
// #define TMAG_ALERT_LATCH_ASSERTED  (1U)

// /* 
//  * TMAG5170 X_THRX_CONFIG Register (Offset = 4h)
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t x_lo_threshold : 8;
//         uint16_t x_hi_threshold : 8;
//     }field;
// }Tmag_RegXThrxConfig_t;

// /* 
//  * TMAG5170 Y_THRX_CONFIG Register (Offset = 5h)
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t y_lo_threshold : 8;
//         uint16_t y_hi_threshold : 8;
//     }field;
// }Tmag_RegYThrxConfig_t;

// /* 
//  * TMAG5170 Z_THRX_CONFIG Register (Offset = 6h)
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t z_lo_threshold : 8;
//         uint16_t z_hi_threshold : 8;
//     }field;
// }Tmag_RegZThrxConfig_t;

// /* 
//  * TMAG5170 T_THRX_CONFIG Register (Offset = 7h)
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t t_lo_threshold : 8;
//         uint16_t t_hi_threshold : 8;
//     }field;
// }Tmag_RegTThrxConfig_t;

// /* 
//  * TMAG5170 CONV_STATUS Register (Offset = 8h)
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t alrt_status : 2;
//         uint16_t res0        : 2;
//         uint16_t set_count   : 3;
//         uint16_t res1        : 1;
//         uint16_t x           : 1;
//         uint16_t y           : 1;
//         uint16_t z           : 1;
//         uint16_t t           : 1;
//         uint16_t a           : 1;
//         uint16_t rdy         : 1;
//         uint16_t res2        : 2;

//     }field;
// }Tmag_RegConvStatus_t;

// #define TMAG_ALRT_STATUS_NO    (0U)
// #define TMAG_ALRT_STATUS_AFE   (1U)
// #define TMAG_ALRT_STATUS_SYS   (2U)
// #define TMAG_ALRT_STATUS_BOTH  (3U)

// #define TMAG_ALRT_X_NOT_CURRENT  (0U)
// #define TMAG_ALRT_X_IS_CURRENT   (1U)

// #define TMAG_ALRT_Y_NOT_CURRENT  (0U)
// #define TMAG_ALRT_Y_IS_CURRENT   (1U)

// #define TMAG_ALRT_Z_NOT_CURRENT  (0U)
// #define TMAG_ALRT_Z_IS_CURRENT   (1U)

// #define TMAG_ALRT_T_NOT_CURRENT  (0U)
// #define TMAG_ALRT_T_IS_CURRENT   (1U)

// #define TMAG_ALRT_A_NOT_CURRENT  (0U)
// #define TMAG_ALRT_A_IS_CURRENT   (1U)

// #define TMAG_ALRT_RDY_NOT_VALID   (0U)
// #define TMAG_ALRT_RDY_DATA_VALID  (1U)

// /* 
//  * TMAG5170 X_CH_RESULT Register (Offset = 9h) 
//  */
// typedef uint16_t Tmag_RegXChResult_t;

// /* 
//  * TMAG5170 Y_CH_RESULT Register (Offset = Ah)
//  */
// typedef uint16_t Tmag_RegYChResult_t;

// /* 
//  * TMAG5170 Z_CH_RESULT Register (Offset = Bh) 
//  */
// typedef uint16_t Tmag_RegZChResult_t;

// /* 
//  * TMAG5170 TEMP_RESULT Register (Offset = Ch) 
//  */
// typedef uint16_t Tmag_RegTempResult_t;

// /* 
//  * TMAG5170 AFE_STATUS Register (Offset = Dh)
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t ldo_stat  : 1;
//         uint16_t trim_stat : 1;
//         uint16_t res0      : 6;
//         uint16_t xhs_stat  : 1;
//         uint16_t yhs_stat  : 1;
//         uint16_t zhs_stat  : 1;
//         uint16_t temp_stat : 1;
//         uint16_t sens_stat : 1;
//         uint16_t res1      : 2;
//         uint16_t cfg_reset : 1;
//     }field;
// }Tmag_RegAfeStatus_t;

// #define TMAG_LDO_STAT_NO_ERROR  (0U)
// #define TMAG_LDO_STAT_ERROR      (1U)

// #define TMAG_TRIM_STAT_NO_ERROR  (0U)
// #define TMAG_TRIM_STAT_ERROR     (1U)

// #define TMAG_XHS_STAT_NO_ERROR  (0U)
// #define TMAG_XHS_STAT_ERROR     (1U)

// #define TMAG_YHS_STAT_NO_ERROR  (0U)
// #define TMAG_THS_STAT_ERROR     (1U)

// #define TMAG_ZHS_STAT_NO_ERROR  (0U)
// #define TMAG_ZHS_STAT_ERROR     (1U)

// #define TMAG_TEMP_STAT_NO_ERROR  (0U)
// #define TMAG_TEMP_STAT_ERROR     (1U)

// #define TMAG_SENS_STAT_NO_ERROR  (0U)
// #define TMAG_SENS_STAT_ERROR     (1U)

// #define TMAG_CFG_RESET_NO_ERROR  (0U)
// #define TMAG_CFG_RESET_ERROR     (1U)

// /* 
//  * TMAG5170 SYS_STATUS Register (Offset = Eh)
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t xch_thx        : 1;
//         uint16_t ych_thx        : 1;
//         uint16_t zch_thx        : 1;
//         uint16_t temp_thx       : 1;
//         uint16_t vcc_uv         : 1;
//         uint16_t vcc_ov         : 1;
//         uint16_t res0           : 2;
//         uint16_t uperating_stat : 3;
//         uint16_t frame_stat     : 1;
//         uint16_t crc_stat       : 1;
//         uint16_t sdo_drv        : 1;
//         uint16_t alrt_drv       : 1;
//         uint16_t alrt_lvl       : 1;
//     }field;
// }Tmag_RegSysStatus_t;

// #define TMAG_XCH_THX_NOT_DETECTED  (0U)
// #define TMAG_XCH_THX_DETECTED      (1U)

// #define TMAG_YCH_THX_NOT_DETECTED  (0U)
// #define TMAG_TCH_THX_DETECTED      (1U)

// #define TMAG_ZCH_THX_NOT_DETECTED  (0U)
// #define TMAG_ZCH_THX_DETECTED      (1U)

// #define TMAG_TEMP_THX_NOT_DETECTED  (0U)
// #define TMAG_TEMP_THX_DETECTED      (1U)

// #define TMAG_VCC_UV_NOT_DETECTED  (0U)
// #define TMAG_VCC_UV_DETECTED      (1U)

// #define TMAG_VCC_OV_NOT_DETECTED  (0U)
// #define TMAG_VCC_OV_DETECTED      (1U)

// #define TMAG_OPERATING_STAT_CONFIG          (0U)
// #define TMAG_OPERATING_STAT_STANDBY         (1U)
// #define TMAG_OPERATING_STAT_ACTIVE_MEASURE  (2U)
// #define TMAG_OPERATING_STAT_ACTIVE_TRIGGER  (3U)
// #define TMAG_OPERATING_STAT_DCM_ACTIVE      (4U)
// #define TMAG_OPERATING_STAT_DCM_SLEEP       (5U)
// #define TMAG_OPERATING_STAT_SLEEP           (6U)

// #define TMAG_FRAME_STAT_NO_ERROR  (0U)
// #define TMAG_FRAME_STAT_ERROR     (1U)

// #define TMAG_CRC_STAT_NO_ERROR  (0U)
// #define TMAG_CRC_STAT_ERROR     (1U)

// #define TMAG_SDO_DRV_NO_ERROR  (0U)
// #define TMAG_SDO_DRV_ERROR     (1U)

// #define TMAG_ALRT_DRV_NO_ERROR  (0U)
// #define TMAG_ALRT_DRV_ERROR     (1U)

// #define TMAG_ALRT_LVL_LOW   (0U)
// #define TMAG_ALRT_LVL_HIGH  (1U)

// /* 
//  * TMAG5170 TEMP_RESULT Register (Offset = Ch) 
//  */
// typedef uint16_t Tmag_RegAngleResult_t;

// /* 
//  * TMAG5170 MAG_GAIN_CONFIG Register (Offset = 11h)
//  */
// typedef union 
// {
//     uint16_t value;
//     struct
//     {
//         uint16_t gain_value     : 11;
//         uint16_t res            : 3;
//         uint16_t gain_selection : 2;

//     }field;
// }Tmag_RegMagGainConfig_t;


// #define TMAG_GAIN_SELECTION_NO  (0U)
// #define TMAG_GAIN_SELECTION_X   (1U)
// #define TMAG_GAIN_SELECTION_Y   (2U)
// #define TMAG_GAIN_SELECTION_Z   (3U)

// #endif  /* _TMAG_REG_H_ */