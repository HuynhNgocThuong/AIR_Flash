/*
	 HUYNH NGOC THUONG
	 DA NANG UNIVERSITY OF SCIENCE AND TECHNOLOGY
	 Last modified: 1/05/2018 - Version 2
	 **Describe: 
	 +FLASH - STM32F103C8T6
 *Facebook: ngocthuong0208 - huynhngocthuong0208@gmail.com - 01216911759
*/

#ifndef FLASH_H_
#define FLASH_H_
//--------------------------------------------------
#include "stm32f1xx_hal.h"
#define EEPROM_START_ADDRESS ((uint32_t) 0x0801F800)



uint64_t Flash_read(uint32_t Flash_Address);
void Flash_write(uint32_t Flash_Address, uint64_t Flash_data);
void Flash_Erase(uint32_t adrr);
void FLASH_PageErase(uint32_t PageAddress);
#endif /* FLASH_H_ */
