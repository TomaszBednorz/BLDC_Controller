#ifndef _AM4096_CFG_H_
#define _AM4096_CFG_H_

/***********************************************************************************************************
 ********************************************* Included files **********************************************
 ***********************************************************************************************************/

#include <stdint.h>

/***********************************************************************************************************
 ************************************************* Defines *************************************************
 ***********************************************************************************************************/

#define AM4096_SLAVE_ID     (0x00)

/***********************************************************************************************************
 *********************************************** Data types ************************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ********************************************* Exported objects ********************************************
 ***********************************************************************************************************/

/***********************************************************************************************************
 ************************************** Exported function prototypes ***************************************
 ***********************************************************************************************************/

void Am4096_RegTx(uint8_t reg, uint16_t data);
uint16_t Am4096_RegRx(uint8_t reg);

#endif  /* _AM4096_CFG_H_ */
