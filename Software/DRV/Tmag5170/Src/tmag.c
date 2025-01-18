// /***********************************************************************************************************
//  ********************************************* Included files **********************************************
//  ***********************************************************************************************************/

// #include "tmag.h"
// #include "tmag_reg.h"
// #include "tmag_cfg.h"

// /***********************************************************************************************************
//  ************************************************* Defines *************************************************
//  ***********************************************************************************************************/

// #define TMAG_RW_COM_WRITE  (0U)
// #define TMAG_RW_COM_READ   (1U)

// #define TMAG_DISABLE_CRC_COMMAND  (0x0004)

// // comm
// #define TMAG_SWAP_BYTES(value)  (((value & 0x00FF) << 8U) | ((value & 0xFF00) >> 8U))

// // comm
// #define TMAG_CONCATENATE_BYTES(byte0, byte1)  ((uint16_t)(((uint16_t)byte0 << 8U) | (uint16_t)byte1))


// /***********************************************************************************************************
//  *********************************************** Data types ************************************************
//  ***********************************************************************************************************/

// typedef struct
// {
//     uint8_t tx_data[4];
//     union
//     {
//         uint32_t value;
//         struct __attribute__((packed))
//         {
//             uint8_t crc    : 4; /* CRC bits */
//             uint8_t cmd    : 4; /* Command bits */
//             uint16_t data     ; /* Sixteen bit data to be written */
//             uint8_t addr   : 7; /* Seven bit address to aaccess registers  */
//             uint8_t rw_com : 1; /* Read or write command */
//         }field;
//     }frame;
// }Tmag_TxFrame_t;


// typedef struct
// {
//     uint8_t rx_data[4];
//     union
//     {
//         uint32_t value;
//         struct __attribute__((packed))
//         {
//             uint8_t crc   : 4; /* CRC bits */
//             uint8_t stat1 : 4; /* First four status bits */
//             uint16_t data    ; /* Sixteen bit data */
//             uint8_t stat0    ; /* Last eight status bits */
//         }field;
//     }frame;
// }Tmag_RxFrame_t;

// /* 
//  * TMAG5170 results structure
//  */
// typedef struct 
// {
//     Tmag_RegXChResult_t x;
//     Tmag_RegYChResult_t y;
//     Tmag_RegZChResult_t z;
//     Tmag_RegTempResult_t temp;
//     Tmag_RegAngleResult_t angle;
//     Tmag_RegAfeStatus_t afe_status;
//     Tmag_RegSysStatus_t sys_status;
// }Tmag_Results_t;

// /***********************************************************************************************************
//  **************************************** Local function prototypes ****************************************
//  ***********************************************************************************************************/

// static void Tmag_FillTxFrame(const Tmag_SensorNbr_t sensor, const Tmag_Register_t reg, const Tmag_Data_t data, const uint8_t r_w);
// static void Tmag_UpdateRxFrame(const Tmag_SensorNbr_t sensor);
// static void Tmag_WriteData(const Tmag_SensorNbr_t sensor, const Tmag_Register_t reg, const Tmag_Data_t data);
// static void Tmag_TransferData(const Tmag_SensorNbr_t sensor, const Tmag_Register_t reg, const Tmag_Data_t data, const uint8_t r_w);
// static void Tmag_ReadData(const Tmag_SensorNbr_t sensor, const Tmag_Register_t reg);
// static void Tmag_DisableCrc(const Tmag_SensorNbr_t sensor);
// static uint8_t Tmag_CalculateCrc(const uint32_t data);

// // dodac consty ???

// /***********************************************************************************************************
//  ******************************************** Exported objects *********************************************
//  ***********************************************************************************************************/

// /***********************************************************************************************************
//  ********************************************* Local objects ***********************************************
//  ***********************************************************************************************************/

// static Tmag_Results_t Tmag_Results[TMAG_SENSOR_NBR_MAX];
// static Tmag_TxFrame_t Tmag_TxFrame[TMAG_SENSOR_NBR_MAX];
// static Tmag_TxFrame_t Tmag_LastTxFrame[TMAG_SENSOR_NBR_MAX];
// static Tmag_RxFrame_t Tmag_RxFrame[TMAG_SENSOR_NBR_MAX];
// static Tmag_SensorNbr_t Tmag_ActiveSensor;

// /***********************************************************************************************************
//  ******************************************* Exported functions ********************************************
//  ***********************************************************************************************************/

// void Tmag_Init(void)
// {
//     for(uint8_t sensor_nbr = TMAG_SENSOR_NBR_0; sensor_nbr < TMAG_SENSOR_NBR_MAX; sensor_nbr++)
//     {
//         Tmag_DisableCrc(sensor_nbr);
//         Tmag_WriteData(sensor_nbr, TMAG_DEVICE_CONFIG, 0x0000);
//         Tmag_ReadData(sensor_nbr, TMAG_AFE_STATUS);
//         Tmag_ReadData(sensor_nbr, TMAG_SYS_STATUS);
//         Tmag_WriteData(sensor_nbr, TMAG_SENSOR_CONFIG, Tmag_Config[sensor_nbr].sensor.value);
//         Tmag_WriteData(sensor_nbr, TMAG_SYSTEM_CONFIG, Tmag_Config[sensor_nbr].system.value);
//         Tmag_WriteData(sensor_nbr, TMAG_ALERT_CONFIG, Tmag_Config[sensor_nbr].alert.value);
//         Tmag_WriteData(sensor_nbr, TMAG_MAG_GAIN_CONFIG, Tmag_Config[sensor_nbr].mag_gain.value);
//         Tmag_WriteData(sensor_nbr, TMAG_DEVICE_CONFIG, Tmag_Config[sensor_nbr].device.value);
//     }
// }

// void Tmag_TransferStart(const Tmag_SensorNbr_t sensor, const Tmag_DataType_t data_type)
// {
//     switch (data_type)
//     {
//     case TMAG_DATA_MAG_FIELD_X:
//         Tmag_ReadData(sensor, TMAG_X_CH_RESULT);
//         break;
//     case TMAG_DATA_MAG_FIELD_Y:
//         Tmag_ReadData(sensor, TMAG_Y_CH_RESULT);
//         break;
//     case TMAG_DATA_MAG_FIELD_Z:
//         Tmag_ReadData(sensor, TMAG_Z_CH_RESULT);
//         break;
//     case TMAG_DATA_TEMPERATURE:
//         Tmag_ReadData(sensor, TMAG_TEMP_RESULT);
//         break;
//     case TMAG_DATA_ANGLE:
//         Tmag_ReadData(sensor, TMAG_DATA_ANGLE_RESULT);
//         break;
//     case TMAG_DATA_AFE_STATUS:
//         Tmag_ReadData(sensor, TMAG_AFE_STATUS);
//         break;
//     case TMAG_DATA_SYS_STATUS:
//         Tmag_ReadData(sensor, TMAG_SYS_STATUS);
//         break;
//     default:
//         /* Do nothing */
//         break;
//     }
// }

// void Tmag_TransferReady(void)
// {
//     Tmag_Config[Tmag_ActiveSensor].data_transfer_stop();

//     Tmag_UpdateRxFrame(Tmag_ActiveSensor);

//     if(TMAG_RW_COM_READ == Tmag_LastTxFrame[Tmag_ActiveSensor].frame.field.rw_com)
//     {
//         switch (Tmag_LastTxFrame[Tmag_ActiveSensor].frame.field.addr)
//         {
//             case TMAG_X_CH_RESULT:
//                 Tmag_Results[Tmag_ActiveSensor].x = Tmag_RxFrame[Tmag_ActiveSensor].frame.field.data;
//                 break;
//             case TMAG_Y_CH_RESULT:
//                 Tmag_Results[Tmag_ActiveSensor].y = Tmag_RxFrame[Tmag_ActiveSensor].frame.field.data;
//                 break;
//             case TMAG_Z_CH_RESULT:
//                 Tmag_Results[Tmag_ActiveSensor].z = Tmag_RxFrame[Tmag_ActiveSensor].frame.field.data;
//                 break;
//             case TMAG_TEMP_RESULT:
//                 Tmag_Results[Tmag_ActiveSensor].temp = Tmag_RxFrame[Tmag_ActiveSensor].frame.field.data;
//                 break;
//             case TMAG_DATA_ANGLE_RESULT:
//                 Tmag_Results[Tmag_ActiveSensor].angle = Tmag_RxFrame[Tmag_ActiveSensor].frame.field.data;
//                 break;
//             case TMAG_SYS_STATUS:
//                 Tmag_Results[Tmag_ActiveSensor].afe_status.value = Tmag_RxFrame[Tmag_ActiveSensor].frame.field.data;
//                 break;
//             case TMAG_AFE_STATUS:
//                 Tmag_Results[Tmag_ActiveSensor].sys_status.value = Tmag_RxFrame[Tmag_ActiveSensor].frame.field.data;
//                 break;
//             default:
//                 /* Do nothing */
//                 break;
//         }
//     }
    
//     Tmag_TransferComplete();
// }

// uint16_t Tmag_GetData(const Tmag_SensorNbr_t sensor, const Tmag_DataType_t data_type)
// {
//     uint16_t ret_val;

//     switch (data_type)
//     {
//     case TMAG_DATA_MAG_FIELD_X:
//         ret_val = Tmag_Results[sensor].x;
//         break;
//     case TMAG_DATA_MAG_FIELD_Y:
//         ret_val = Tmag_Results[sensor].y;
//         break;
//     case TMAG_DATA_MAG_FIELD_Z:
//         ret_val = Tmag_Results[sensor].z;
//         break;
//     case TMAG_DATA_TEMPERATURE:
//         ret_val = Tmag_Results[sensor].temp;
//         break;
//     case TMAG_DATA_ANGLE:
//         ret_val = Tmag_Results[sensor].angle;
//         break;
//     case TMAG_DATA_AFE_STATUS:
//         ret_val = Tmag_Results[sensor].afe_status.value;
//         break;
//     case TMAG_DATA_SYS_STATUS:
//         ret_val = Tmag_Results[sensor].sys_status.value;
//         break;
//     default:
//         /* Do nothing */
//         break;
//     }

//     return ret_val;
// }

// /***********************************************************************************************************
//  ******************************************** Local functions **********************************************
//  ***********************************************************************************************************/

// static void Tmag_FillTxFrame(const Tmag_SensorNbr_t sensor, const Tmag_Register_t reg, const Tmag_Data_t data, const uint8_t r_w)
// {
//     uint8_t* buff;

//     Tmag_TxFrame[sensor].frame.field.rw_com = r_w;
//     Tmag_TxFrame[sensor].frame.field.addr = reg;
//     Tmag_TxFrame[sensor].frame.field.data = data;
//     Tmag_TxFrame[sensor].frame.field.cmd = 0U;


//     Tmag_TxFrame[sensor].frame.field.crc = 0U;
//     // Tmag_TxFrame[sensor].frame.field.crc = Tmag_CalculateCrc(Tmag_TxFrame[sensor].frame.value);

//     buff = (uint8_t*)&Tmag_TxFrame[sensor].frame.value;

//     for(uint8_t i = 0; i < 4U; i++)
//     {
//         Tmag_TxFrame[sensor].tx_data[i] = buff[3U - i];
//     }
// }

// static void Tmag_UpdateRxFrame(const Tmag_SensorNbr_t sensor)
// {
//     Tmag_RxFrame[sensor].frame.field.stat0 = Tmag_RxFrame[sensor].rx_data[0];
//     Tmag_RxFrame[sensor].frame.field.data = TMAG_CONCATENATE_BYTES(Tmag_RxFrame[sensor].rx_data[1], Tmag_RxFrame[sensor].rx_data[2]);
//     Tmag_RxFrame[sensor].frame.field.stat1 = (Tmag_RxFrame[sensor].rx_data[3] >> 4U) & 0x0F;
//     Tmag_RxFrame[sensor].frame.field.crc = Tmag_RxFrame[sensor].rx_data[3] & 0x0F;

// }

// static void Tmag_WriteData(const Tmag_SensorNbr_t sensor, const Tmag_Register_t reg, const Tmag_Data_t data)
// {
//     Tmag_TransferData(sensor, reg, data, TMAG_RW_COM_WRITE);
// }

// static void Tmag_ReadData(const Tmag_SensorNbr_t sensor, const Tmag_Register_t reg)
// {
//     Tmag_TransferData(sensor, reg, 0U, TMAG_RW_COM_READ);
// }

// static void Tmag_TransferData(const Tmag_SensorNbr_t sensor, const Tmag_Register_t reg, const Tmag_Data_t data, const uint8_t r_w)
// {
//     Tmag_FillTxFrame(sensor, reg, data, r_w);

//     while(Tmag_Config[sensor].is_data_transfer_busy());

//     Tmag_ActiveSensor = sensor;

//     Tmag_Config[sensor].data_transfer_start(Tmag_TxFrame[sensor].tx_data, Tmag_RxFrame[sensor].rx_data);
    
//     Tmag_LastTxFrame[sensor] = Tmag_TxFrame[sensor];
// }

// static void Tmag_DisableCrc(const Tmag_SensorNbr_t sensor)
// {
//     Tmag_TxFrame[sensor].tx_data[0] = 0x0F;
//     Tmag_TxFrame[sensor].tx_data[1] = 0x00;
//     Tmag_TxFrame[sensor].tx_data[2] = 0x04;
//     Tmag_TxFrame[sensor].tx_data[3] = 0x07;

//     while(Tmag_Config[sensor].is_data_transfer_busy());

//     Tmag_Config[sensor].data_transfer_start(Tmag_TxFrame[sensor].tx_data, Tmag_RxFrame[sensor].rx_data);
// }

// static uint8_t Tmag_CalculateCrc(const uint32_t data)
// {
//     uint8_t crc_data[4] = {1, 1, 1, 1};
//     uint8_t result = 0U;
//     uint8_t inv;
    
//     for (uint8_t i = 0U; i < 32U; i++)
//     {
//         inv = crc_data[3] ^ ((data >> (31U - i)) & 1U);
//         crc_data[3] = crc_data[2];
//         crc_data[2] = crc_data[1];
//         crc_data[1] = crc_data[0] ^ inv;
//         crc_data[0] = inv;
//     }
    
//     for (uint8_t i = 0U; i < 4U; i++)
//     {
//         result |= (crc_data[i] << i);
//     }

//     return result;
// }



