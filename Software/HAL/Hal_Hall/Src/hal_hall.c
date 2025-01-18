// /***********************************************************************************************************
//  ********************************************* Included files **********************************************
//  ***********************************************************************************************************/

// #ifdef 0

// #include "hal_hall.h"
// #include "hal_hall_cfg.h"
// #include "tmag.h"

// /***********************************************************************************************************
//  ************************************************* Defines *************************************************
//  ***********************************************************************************************************/

// /***********************************************************************************************************
//  *********************************************** Data types ************************************************
//  ***********************************************************************************************************/

// typedef enum
// {
//     HAL_HALL_MODE_UNINIT = 0U,
//     HAL_HALL_MODE_INIT
// }Hal_Hall_Mode_t;

// typedef enum
// {
//     HAL_HALL_STATE_SENSOR0_X = 0U,
//     HAL_HALL_STATE_SENSOR0_Y,
//     HAL_HALL_STATE_SENSOR0_Z,
//     HAL_HALL_STATE_SENSOR0_ANG,
//     HAL_HALL_STATE_SENSOR1_X,
//     HAL_HALL_STATE_SENSOR1_Y,
//     HAL_HALL_STATE_SENSOR1_Z,
//     HAL_HALL_STATE_SENSOR1_ANG,
//     HAL_HALL_STATE_PROCESS_DATA
// }Hal_Hall_StateMachine_t;

// /***********************************************************************************************************
//  **************************************** Local function prototypes ****************************************
//  ***********************************************************************************************************/

// static void Hal_Hall_ProcessState(void);
// static void Hal_Hall_ProcessData(void);

// /***********************************************************************************************************
//  ******************************************** Exported objects *********************************************
//  ***********************************************************************************************************/

// Hal_Hall_Results_t Hal_Hall_Results[HAL_HALL_SENSOR_NBR_MAX];

// /***********************************************************************************************************
//  ********************************************* Local objects ***********************************************
//  ***********************************************************************************************************/

// static Hal_Hall_StateMachine_t Hal_Hall_StateMachine = 0U;
// static Hal_Hall_Mode_t Hal_Hall_Mode = HAL_HALL_MODE_UNINIT;

// /***********************************************************************************************************
//  ******************************************* Exported functions ********************************************
//  ***********************************************************************************************************/

// void Hal_Hall_Init(void)
// {
//     Hal_Hall_Mode = HAL_HALL_MODE_INIT;
// }

// void Hal_Hall_TransmissionCompletedCallback(void)
// {
//     // Do nothing
// }

// /***********************************************************************************************************
//  ******************************************** Local functions **********************************************
//  ***********************************************************************************************************/

// void Hal_Hall_Task(void)
// {
//     static uint32_t counter;

//     if((((counter % 10) == 0U) && (Hal_Hall_StateMachine == HAL_HALL_STATE_SENSOR0_X)) ||
//         (Hal_Hall_StateMachine != HAL_HALL_STATE_SENSOR0_X))
//     {
//         Hal_Hall_ProcessState();
//     }

//     counter++;
// }


// static void Hal_Hall_ProcessState(void)
// {
//     if(HAL_HALL_MODE_INIT == Hal_Hall_Mode)
//     {
//         switch (Hal_Hall_StateMachine)
//         {
//         case HAL_HALL_STATE_SENSOR0_X:
//             Tmag_TransferStart(TMAG_SENSOR_NBR_0, TMAG_DATA_MAG_FIELD_X);
//             break;
//         case HAL_HALL_STATE_SENSOR0_Y:
//             Tmag_TransferStart(TMAG_SENSOR_NBR_0, TMAG_DATA_MAG_FIELD_Y);
//             break;
//         case HAL_HALL_STATE_SENSOR0_Z:
//             Tmag_TransferStart(TMAG_SENSOR_NBR_0, TMAG_DATA_MAG_FIELD_Z);
//             break;
//         case HAL_HALL_STATE_SENSOR0_ANG:
//             Tmag_TransferStart(TMAG_SENSOR_NBR_0, TMAG_DATA_ANGLE);
//             break;
//         case HAL_HALL_STATE_SENSOR1_X:
//             Tmag_TransferStart(TMAG_SENSOR_NBR_1, TMAG_DATA_MAG_FIELD_X);
//             break;
//         case HAL_HALL_STATE_SENSOR1_Y:
//             Tmag_TransferStart(TMAG_SENSOR_NBR_1, TMAG_DATA_MAG_FIELD_Y);
//             break;
//         case HAL_HALL_STATE_SENSOR1_Z:
//             Tmag_TransferStart(TMAG_SENSOR_NBR_1, TMAG_DATA_MAG_FIELD_Z);
//             break;
//         case HAL_HALL_STATE_SENSOR1_ANG:
//             Tmag_TransferStart(TMAG_SENSOR_NBR_1, TMAG_DATA_ANGLE);
//             break;
//         case HAL_HALL_STATE_PROCESS_DATA:
//             Hal_Hall_ProcessData();
//             break;
//         default:
//             break;
//         }

//         if(Hal_Hall_StateMachine < HAL_HALL_STATE_PROCESS_DATA)
//         {
//             Hal_Hall_StateMachine++;
//         }
//         else
//         {
//             Hal_Hall_StateMachine = HAL_HALL_STATE_SENSOR0_X;
//         }
//     }
// }

// static void Hal_Hall_ProcessData(void)
// {
//     for(uint8_t i = TMAG_SENSOR_NBR_0; i < TMAG_SENSOR_NBR_MAX; i++)
//     {
//         Hal_Hall_Results[i].x = (int16_t)Tmag_GetData(i, TMAG_DATA_MAG_FIELD_X);
//         Hal_Hall_Results[i].y = (int16_t)Tmag_GetData(i, TMAG_DATA_MAG_FIELD_Y);
//         Hal_Hall_Results[i].z = (int16_t)Tmag_GetData(i, TMAG_DATA_MAG_FIELD_Z);
//         Hal_Hall_Results[i].angle = Tmag_GetData(i, TMAG_DATA_ANGLE);
//     }
// }

// #endif
