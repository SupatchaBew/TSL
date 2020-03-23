/**
  ******************************************************************************
  * File Name          	: fm25lxx.c
  * Description        	: This file FRAM for deriver FM25LXX.
  * Date				: 4/11/2019
  * Author				: R&D
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include <fm25lxx.h>

/* Private user code ---------------------------------------------------------*/
void FM25LXX_WriteByteSPI( uint8_t data )
{
	HAL_SPI_Transmit( &FM25LXX_SPI, ( uint8_t * ) &data, 1, HAL_MAX_DELAY );
}

uint8_t FM25LXX_ReadByteSPI( void )
{
	uint8_t rxData ;
	HAL_SPI_Receive( &FM25LXX_SPI, ( uint8_t* ) &rxData, 1, HAL_MAX_DELAY );
	return rxData;
}

/**
 * @brief	brief Enable write latch register.
 * @param 	none
 * @retval 	none
 */
void FM25LXX_EnableWrite( void )
{
  FM25LXX_CS_Lo;
  FM25LXX_WriteByteSPI( FM25LXX_OPCODE_WR_ENABLE );
  FM25LXX_CS_Hi;
}


/**
 * @brief	@brief Disable write latch register.
 * @param 	none
 * @retval 	none
 */
void FM25LXX_DisableWrite(void)
{
  FM25LXX_CS_Lo;
  FM25LXX_WriteByteSPI( FM25LXX_OPCODE_WR_DISABLE );
  FM25LXX_CS_Hi;
}

/**
 * @brief	Read status register of chip.
 * @param 	none
 * @retval  Status register
 */
unsigned char FM25LXX_ReadStatusReg(void)
{
	unsigned char result = 0xFF;

	FM25LXX_CS_Lo;
	HAL_Delay(5);
	FM25LXX_WriteByteSPI( FM25LXX_OPCODE_RD_STATUS_REG );
	HAL_Delay(5);
	result = FM25LXX_ReadByteSPI();
	FM25LXX_CS_Hi;

	return result;
}


/**
 * @brief	Write one byte to specified address.
 * @param 	address - Index of address to be write (0-511) for 512 bytes memory
 * @param 	data - Data to be written
 * @retval  none
 */
void FM25LXX_WriteMemory( unsigned short address, unsigned char data )
{  
  unsigned short opcode = FM25LXX_OPCODE_WR_MEMORY_DATA;
  
  FM25LXX_CS_Lo;
  HAL_Delay(5);
  FM25LXX_WriteByteSPI((unsigned char) opcode);
  FM25LXX_WriteByteSPI((unsigned char) (address >> 8) &0x07);
  FM25LXX_WriteByteSPI((unsigned char) (address ));
  FM25LXX_WriteByteSPI(data);
  HAL_Delay(5);
  FM25LXX_CS_Hi;
}



/**
 * @brief 	Get data from specified address
 * @param 	address - index of address to be write (0-511) for 512 bytes memory
 * @retval 	data from memory
 */
unsigned char FM25LXX_ReadMemory(unsigned short address)
{
  unsigned short opcode = FM25LXX_OPCODE_RD_MEMORY_DATA;
  unsigned char result;

  FM25LXX_CS_Lo;
  HAL_Delay(5);
  FM25LXX_WriteByteSPI((unsigned char) opcode);
  FM25LXX_WriteByteSPI((unsigned char) (address >> 8) & 0x07);
  FM25LXX_WriteByteSPI((unsigned char) (address ));
  result = FM25LXX_ReadByteSPI( );
  HAL_Delay(5);
  FM25LXX_CS_Hi;

  return result;
}


/**
 * @brief	Write buffer of data to specified address.
 * @param 	address - Index of address to be write (0-511) for 512 bytes memory
 * @param 	data - Data to be written
 * @param 	length - Number of bytes to write
 * @retval  none
 */
void FM25LXX_SaveData(uint16_t address, uint8_t *data, uint8_t length)
{
	uint16_t i;
	for (i = 0; i < length; i++, data++)
	{
		FM25LXX_EnableWrite();
		FM25LXX_WriteMemory( address+i,*data );
	}
}

/**
 * @brief	Read a buffer of data from specified address.
 * @param 	address - Index of address to be write (0-511) for 512 bytes memory
 * @param 	data - Data to be written
 * @param 	length - Number of bytes to read
 * @retval  none
 */
void FM25LXX_LoadData(uint16_t address, uint8_t *data, size_t length)
{
	uint16_t i;
	for (i = 0; i < length; i++, data++)
	{
		*data = FM25LXX_ReadMemory( address+i );
	}
}

/************************ (C) COPYRIGHT PRIMUS *****END OF FILE****/
