#include "flash.h"
void FLASH_PageErase(uint32_t PageAddress)
{
    SET_BIT(FLASH->CR, FLASH_CR_PER);
    WRITE_REG(FLASH->AR, PageAddress);
    SET_BIT(FLASH->CR, FLASH_CR_STRT);
		while(FLASH->SR & FLASH_CR_PER_Pos);
		CLEAR_BIT(FLASH->CR, FLASH_CR_STRT|FLASH_CR_PER);
}

void Flash_write(uint32_t Flash_Address, uint64_t Flash_data){
	HAL_FLASH_Unlock();
	FLASH_PageErase(EEPROM_START_ADDRESS);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Flash_Address, Flash_data);
	HAL_FLASH_Lock();
	
}
uint64_t Flash_read(uint32_t Flash_Address){
	uint64_t Flash_data;
	Flash_data = *(uint32_t *)Flash_Address;
	return Flash_data;
}
