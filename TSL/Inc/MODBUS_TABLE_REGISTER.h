/**
  ******************************************************************************
  * File Name          	: MODBUS_TABLE_REGISTER.h
  * Description        	: This file modbus table register.
  * Date				: 12/12/2019
  * Author				: R&D
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MODBUS_TABLE_REGISTER_H_
#define MODBUS_TABLE_REGISTER_H_

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>

/* Exported constants --------------------------------------------------------*/
//#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
/* Exported types ------------------------------------------------------------*/
/**
  * @brief  Modbus table structure definition
  */
typedef struct
{
	int16_t *add_register;

	short int  max;
	short int  min;
}MOBUS_Table_struct;

enum Table1_Reg
{
	REG_MB_TIME=3,
	REG_MB_TYPEIN,
	REG_MB_SPC_MSB,
	REG_MB_SPC_LSB,
	REG_MB_CNT_MSB,
	REG_MB_CNT_LSB,
	REG_MB_ENC_MSB,
	REG_MB_ENC_LSB,
	REG_MB_ENCSET_MSB,
	REG_MB_ENCSET_LSB,
	REG_MB_ENCSETLOW_MSB,
	REG_MB_ENCSETLOW_LSB,
	REG_MB_ENCMUL_MSB,
	REG_MB_ENCMUL_LSB,
	REG_MB_ENCDIV_MSB,
	REG_MB_ENCDIV_LSB,
};

/* Exported functions prototypes ---------------------------------------------*/
extern short int *table_register[];
extern short int *table_cal_mode_register[];
extern  short int *table_cal_data_register[];
extern MOBUS_Table_struct modbus_table_reg[];
extern MOBUS_Table_struct modbus_table_cal_mode_register[];
extern MOBUS_Table_struct modbus_table_cal_data_register[];
extern MOBUS_Table_struct modbus_table_Hardware_Interface[];

extern uint16_t get_size_Table();
extern uint16_t get_size_Table_Reg();
extern void set_register(uint16_t address , uint16_t index  );
extern int* get_address(uint16_t index);
extern int16_t get_Value(int index);

#endif /* MODBUS_TABLE_REGISTER_H_ */
/************************ (C) COPYRIGHT PRIMUS *****END OF FILE****/
