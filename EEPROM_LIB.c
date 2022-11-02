/********************************************/
/*	CREATED BY: Samuel Lüthi				*/
/*											*/
/*											*/
/********************************************/

#include "EEPROM_LIB.h"

void EEPROM_write(unsigned int uiAddress, unsigned char ucData)
{
	while(EECR & (1<<EEPE));	//wait for completion of previous operation
	
	EEAR = uiAddress;			//set up address register
	EEDR = ucData;				//set up data register
	
	EECR |= (1<<EEMPE);			//sett master start to one
	
	EECR |= (1<<EEPE);			//start write
}

unsigned char EEPROM_read(unsigned int uiAddress)
{
	
	while(EECR & (1<<EEPE));	//wait for completion of previous operation
	
	EEAR = uiAddress;			//set up address register
	
	EECR |= (1<<EERE);			//start read
	
	return EEDR;				//return read data
}