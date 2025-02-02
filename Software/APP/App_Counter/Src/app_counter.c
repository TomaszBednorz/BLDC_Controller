/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

#include "app_counter.h"

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 **************************************** Local function prototypes ****************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ******************************************** Exported objects *********************************************
 ***********************************************************************************************************/

uint32_t volatile App_Counter_GlobalTime;
bool volatile App_Counter_GlobalFlag;

/***********************************************************************************************************
 ********************************************* Local objects ***********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ******************************************* Exported functions ********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ******************************************** Local functions **********************************************
 ***********************************************************************************************************/

void App_Counter_Tick(void)
{
	App_Counter_GlobalTime++;
	App_Counter_GlobalFlag = true;
}

uint32_t App_Counter_GetTickNbr(void)
{
	return App_Counter_GlobalTime;
}