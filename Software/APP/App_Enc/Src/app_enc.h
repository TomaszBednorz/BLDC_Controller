#ifndef _APP_ENC_H_
#define _APP_ENC_H_

/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include <stdint.h>

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

#define APP_ENC_TASK_PERIOD  (10)  /* 1 = 100us */
#define APP_ENC_TASK_OFFSET  (1)

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ********************************************* Exported objects ********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ************************************** Exported function prototypes ***************************************
 ***********************************************************************************************************/

void App_Enc_Init(void);
void App_Enc_Task(void);
float App_Enc_GetAngle(void);  /* deg */

#endif  /* _APP_ENC_H_ */
