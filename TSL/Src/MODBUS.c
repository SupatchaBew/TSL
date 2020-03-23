/**
  ******************************************************************************
  * File Name          	: MODBUS.c
  * Description        	: This file modbus.
  * Date				: 12/12/2019
  * Author				: R&D
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include <initial_parameter.h>
#include <MODBUS.h>
#include "global.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t rxBuffer_modbus1;

uint16_t TIME_MODBUS = 10;							// 20ms

const uint8_t CRCTableHigh[] =
{ 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01,
		0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
		0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
		0xC1, 0x81, 0x40 };

const uint8_t CRCTableLow[] =
{ 0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7, 0x05,
		0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A,
		0xCA, 0xCB, 0x0B, 0xC9, 0x09, 0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B,
		0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14,
		0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3, 0x11,
		0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32, 0x36,
		0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D, 0xFF,
		0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28,
		0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D,
		0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26, 0x22,
		0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1, 0x63,
		0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4, 0x6C,
		0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69,
		0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE,
		0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5, 0x77,
		0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0, 0x50,
		0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55,
		0x95, 0x94, 0x54, 0x9C, 0x5C, 0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A,
		0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B,
		0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C, 0x44,
		0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83, 0x41,
		0x81, 0x80, 0x40 };

MB_sType modbus1;
MB_sType modbus3;
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void tx1_en(void)
{
	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_12, GPIO_PIN_SET );
	HAL_UART_Transmit_IT(&huart1, modbus1.RspBuf, modbus1.ByteRsp);
	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_12, GPIO_PIN_RESET );
}
void rx1_en(void)
{
	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_12, GPIO_PIN_RESET );
}

uint8_t register_address_rw(int16_t  address,uint16_t index_start,uint16_t length)
{
	if(address >= index_start && address  < index_start+length )
	{
		return 1;
	}
	return 0;
}

uint8_t MODBUS_Nregs_Support_Write(int16_t  address,uint16_t index_start, uint16_t n, uint16_t length)
{
	if(address >= index_start && address+n  < index_start+length )
	{
		return 1;
	}
	return 0;
}

uint8_t register_value_in_range(int16_t  address, int16_t value, MOBUS_Table_struct *mb_table)
{
	uint8_t boolean;

	switch( address )
	{
//		case REG_CH1_INP:
//		case REG_CH2_INP:
//		case REG_CH3_INP:
//		case REG_CH4_INP:
//		case REG_CH5_INP:
//		case REG_CH6_INP:
//			boolean = (value>=TC_TYPE_K&&value<=PT100)||(value>=AN_0_20mA&&value<=AN_4_20mA)||(value>=AN_0_75mV&&value<=AN_N10_10VDC) ? 1 : 0;
//			break;
//
//		case REG_CH1_ALF:
//		case REG_CH2_ALF:
//		case REG_CH3_ALF:
//		case REG_CH4_ALF:
//		case REG_CH5_ALF:
//		case REG_CH6_ALF:
//			boolean=alarm_function_support(value) ? 1 : 0;
//			break;
//
//		case REG_CH1_DP:
//			boolean=(value>=0&&value<=(analog_input(Value[0].INP) ? 3 : thermocouple_input_nodp(Value[0].INP) ? 0:1)) ? 1 : 0;
//			break;
//		case REG_CH2_DP:
//			boolean=(value>=0&&value<=(analog_input(Value[1].INP) ? 3 : thermocouple_input_nodp(Value[1].INP) ? 0:1)) ? 1 : 0;
//			break;
//		case REG_CH3_DP:
//			boolean=(value>=0&&value<=(analog_input(Value[2].INP) ? 3 : thermocouple_input_nodp(Value[2].INP) ? 0:1)) ? 1 : 0;
//			break;
//		case REG_CH4_DP:
//			boolean=(value>=0&&value<=(analog_input(Value[3].INP) ? 3 : thermocouple_input_nodp(Value[3].INP) ? 0:1)) ? 1 : 0;
//			break;
//		case REG_CH5_DP:
//			boolean=(value>=0&&value<=(analog_input(Value[4].INP) ? 3 : thermocouple_input_nodp(Value[4].INP) ? 0:1)) ? 1 : 0;
//			break;
//		case REG_CH6_DP:
//			boolean=(value>=0&&value<=(analog_input(Value[5].INP) ? 3 : thermocouple_input_nodp(Value[5].INP) ? 0:1)) ? 1 : 0;
//			break;

		default:
			boolean = (value > (mb_table[address].max) || value < (mb_table[address].min)) ? 0 : 1;
			break;
	}
	return boolean;
}
void crc16(MB_sType *modbus, uint8_t *dptr, uint8_t n)
{
	uint8_t i, j;
	modbus->CrcHi = modbus->CrcLo = 0xFF;
	for (i = 0; i < n; i++, dptr++)
	{
		j = modbus->CrcHi ^ *dptr;
		modbus->CrcHi = modbus->CrcLo ^ CRCTableHigh[j];
		modbus->CrcLo = CRCTableLow[j];
	}
}
void exeption_response(uint8_t slave_address, uint8_t ExeptionCode,
		MB_sType *modbus, void (*tx_enable)(void))
{
	uint16_t i;

	if (modbus->ReqBuf[0] == slave_address)
	{
		modbus->RspBuf[0] = modbus->ReqBuf[0];
		modbus->RspBuf[1] = 0x80 | modbus->ReqBuf[1];
		modbus->RspBuf[2] = ExeptionCode;
		crc16(modbus, modbus->RspBuf, 3);
		modbus->RspBuf[3] = modbus->CrcHi;
		modbus->RspBuf[4] = modbus->CrcLo;
		for (i = 0; i < 8; i++)
			modbus->ReqBuf[i] = 0x00;
		modbus->ByteReq = 0;
		modbus->MBdptr = modbus->RspBuf;
		modbus->ByteRsp = 5;
		modbus->FTX = 1;
		modbus->TxTimeOut = 0;

		tx_enable();
	}
}
void loop_back_diagnostic(uint8_t slave_address, MB_sType *modbus,
		void (*tx_enable)(void))
{
	uint8_t i;
	if (modbus->ReqBuf[0] != slave_address)
		return;
	if (modbus->ByteReq != 8)
		return;
	crc16(modbus, modbus->ReqBuf, 6);
	if (modbus->CrcHi != modbus->ReqBuf[6]
			|| modbus->CrcLo != modbus->ReqBuf[7])
		return;
	for (i = 0; i < modbus->ByteReq; i++)
	{
		modbus->RspBuf[i] = modbus->ReqBuf[i];
	}
	/// clear Modbus //
	for (i = 0; i < 8; i++)
	{
		modbus->ReqBuf[i] = 0x00;
	}
	modbus->MBdptr = modbus->RspBuf;
	modbus->ByteRsp = 8;
	modbus->FTX = 1;
	modbus->TxTimeOut = 0;
	tx_enable();

}
int address ;
void preset_a_single_register(uint8_t slave_address, MB_sType *modbus,void (*tx_enable)(void))
{
	typedef union
	{
		uint16_t Word;
		struct
		{
			uint8_t L;
			uint8_t H;
		};
	} u16_Type;

	uint16_t DATA_BUFFER;
	u16_Type REGISTER_ADDR, REGISTER_VALUE;
	uint8_t *dptr, i;

	if (modbus->ReqBuf[0] == slave_address) //<< slave address
	{
		if (modbus->ByteReq != 8)
			return;
		crc16(modbus, modbus->ReqBuf, 6);
		if (modbus->CrcHi != modbus->ReqBuf[6]|| modbus->CrcLo != modbus->ReqBuf[7])
			return;
		REGISTER_ADDR.H = modbus->ReqBuf[2];
		REGISTER_ADDR.L = modbus->ReqBuf[3];

		if (register_address_rw(REGISTER_ADDR.Word,0,get_size_Table()))
		{
			REGISTER_VALUE.H = modbus->ReqBuf[4];
			REGISTER_VALUE.L = modbus->ReqBuf[5];
			if (register_value_in_range(REGISTER_ADDR.Word,REGISTER_VALUE.Word,modbus_table_reg))
			{
			//	*table_register[REGISTER_ADDR.Word] = REGISTER_VALUE.Word;
				*(modbus_table_reg[REGISTER_ADDR.Word].add_register) = REGISTER_VALUE.Word;
				Save_single_value(REGISTER_ADDR.Word-4,&(REGISTER_VALUE.Word));
				if (modbus->ReqBuf[0])
				{
					modbus->ByteRsp = 0;
					for (i = 0; i < 6; i++)
					{
						modbus->RspBuf[modbus->ByteRsp++] = modbus->ReqBuf[i];
					}
					crc16(modbus, modbus->RspBuf, modbus->ByteRsp);
					modbus->RspBuf[modbus->ByteRsp++] = modbus->CrcHi;
					modbus->RspBuf[modbus->ByteRsp++] = modbus->CrcLo;
					modbus->MBdptr = modbus->RspBuf;
					modbus->FTX = 1;
					modbus->TxTimeOut = 0;

					tx_enable();
				}
			}
			else
			{
				if (modbus->ReqBuf[0])
				{
					exeption_response(slave_address, ILLEGAL_DATA_VALUE, modbus,
							tx_enable);
				}
			}
		}
		else
		{
			if (modbus->ReqBuf[0])
			{
				exeption_response(slave_address, ILLEGAL_DATA_ADDRESS, modbus,
						tx_enable);
			}
		}
	}
}


void preset_multiple_register(uint8_t slave_address, MB_sType *modbus,void (*tx_enable)(void))
{
	typedef union
	{
		int16_t Word;
		struct
		{
			int8_t L;
			int8_t H;
		};
	} i16_Type;

	uint16_t DATA_BUFFER;
	i16_Type REGISTER_ADDR, REGISTER_VALUE, NDATA;
	uint8_t *dptr, i,j, BYTE_COUNT;

	if (modbus->ReqBuf[0] == slave_address) //<< slave address
	{
		if (modbus->ByteReq < 11)
			return;
		crc16(modbus, modbus->ReqBuf, modbus->ByteReq-2);
		if (modbus->CrcHi != modbus->ReqBuf[modbus->ByteReq-2]|| modbus->CrcLo != modbus->ReqBuf[modbus->ByteReq-1])
			return;

		REGISTER_ADDR.H = modbus->ReqBuf[2];
		REGISTER_ADDR.L = modbus->ReqBuf[3];

		NDATA.H = modbus->ReqBuf[4];
		NDATA.L = modbus->ReqBuf[5];

		BYTE_COUNT = modbus->ReqBuf[6];

		if (MODBUS_Nregs_Support_Write(REGISTER_ADDR.Word,0, NDATA.Word,get_size_Table()))
		{
			FlagSetting = 1;
			for(i = 0,j=0; i < BYTE_COUNT; i=i+2, j++)
			{
				REGISTER_VALUE.H = modbus->ReqBuf[i+7];
				REGISTER_VALUE.L = modbus->ReqBuf[i+8];
				*(modbus_table_reg[REGISTER_ADDR.Word+j].add_register) = REGISTER_VALUE.Word;
			}
			Save_single_value_byReg(REGISTER_ADDR.Word);
			FlagSetting = 0;

			if (modbus->ReqBuf[0])
			{
				modbus->ByteRsp = 0;
				for (i = 0; i < 6; i++)
				{
					modbus->RspBuf[modbus->ByteRsp++] = modbus->ReqBuf[i];
				}
				crc16(modbus, modbus->RspBuf, modbus->ByteRsp);
				modbus->RspBuf[modbus->ByteRsp++] = modbus->CrcHi;
				modbus->RspBuf[modbus->ByteRsp++] = modbus->CrcLo;
				modbus->MBdptr = modbus->RspBuf;
				modbus->FTX = 1;
				modbus->TxTimeOut = 0;

				tx_enable();
			}
		}
		else
		{
			if (modbus->ReqBuf[0])
			{
				exeption_response(slave_address, ILLEGAL_DATA_ADDRESS, modbus,
						tx_enable);
			}
		}
	}
}
/**
 *
 * @param slave_add  slave address of  MODBUS PROTOCAL
 * @param modbus
 * @param tx_enable
 */
MOBUS_Table_struct mod_A;
void read_multi_registers(uint8_t slave_add, MB_sType *modbus, void (*tx_enable)(void))
{
	typedef union
	{
		uint16_t Word;
		struct
		{
			uint8_t L;
			uint8_t H;
		};
	} u16_Type;
	uint16_t i;
	u16_Type REGISTER_ADDR, NRegs;
	uint8_t *dptr;

	if (modbus->ReqBuf[0] == slave_add)
	{
//		if (modbus->ByteReq != 8)
//			return;
		crc16(modbus, modbus->ReqBuf, 6);
		if (modbus->CrcHi != modbus->ReqBuf[6]
				|| modbus->CrcLo != modbus->ReqBuf[7])
			return;
		NRegs.H = modbus->ReqBuf[4];
		NRegs.L = modbus->ReqBuf[5];
		REGISTER_ADDR.H = modbus->ReqBuf[2];
		REGISTER_ADDR.L = modbus->ReqBuf[3];

		if (NRegs.Word >= 1
			&& NRegs.Word <= get_size_Table()
			&& REGISTER_ADDR.Word <= get_size_Table()
			&& (REGISTER_ADDR.Word + NRegs.Word) >= 1
			&& (REGISTER_ADDR.Word + NRegs.Word) <= get_size_Table()
		   )
		{
			modbus->ByteRsp = 0;
			modbus->RspBuf[modbus->ByteRsp++] = (uint8_t) slave_add;
			modbus->RspBuf[modbus->ByteRsp++] = modbus->ReqBuf[1];
			modbus->RspBuf[modbus->ByteRsp++] = NRegs.Word << 1;

			for (i = 0; i < (NRegs.Word); i++)
			{
					// int16_t format  register format //
					/*
					dptr = table_register[i+REGISTER_ADDR.Word];
					dptr++;
					modbus->RspBuf[modbus->ByteRsp++] = *dptr--;
					modbus->RspBuf[modbus->ByteRsp++] = *dptr--;
					*/
					// mod_A = *table_reg[i+REGISTER_ADDR.Word];
					dptr = (modbus_table_reg[i+REGISTER_ADDR.Word].add_register);
					dptr++;
					modbus->RspBuf[modbus->ByteRsp++] = *dptr--;
					modbus->RspBuf[modbus->ByteRsp++] = *dptr--;
			}

			crc16(modbus, modbus->RspBuf, modbus->ByteRsp);
			modbus->RspBuf[modbus->ByteRsp++] = modbus->CrcHi;
			modbus->RspBuf[modbus->ByteRsp++] = modbus->CrcLo;
			modbus->MBdptr = modbus->RspBuf;
			modbus->FTX = 1;
			modbus->TxTimeOut = 0;

			tx_enable();
		}
		else
		{
//			if(modbus == &modbus1)
//			{
//			modbus->ByteRsp++;
//			}
			exeption_response(slave_add, ILLEGAL_DATA_ADDRESS, modbus,
					tx_enable);
		}
	}

}

/**
 *
 */
void run_modbus()
{
	if(Tick.Modbus < TIME_MODBUS) return;
	Tick.Modbus = 0;

	static int16_t bundrate = 0;
	static int16_t type_com = 0;
	if(nValue.Bandrate != bundrate || nValue.TypeCom != type_com )
	{
		bundrate = nValue.Bandrate;
		type_com = nValue.TypeCom;
		Uart1_Init(nValue.Bandrate,nValue.TypeCom);

		/* Enable USART */
		__HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
		if (HAL_UART_Receive_IT(&huart1, (uint8_t *)&rxBuffer_modbus1, 1)!= HAL_OK)
		{
			Error_Handler();
		}
	}

	modbus(nValue.Address, &modbus1, &tx1_en,modbus_table_reg
		  ,modbus_table_reg
		  ,modbus_table_reg
		  ,modbus_table_reg);
}


void clear_modbus_buffer(MB_sType *modbus)
{
	int j = 0;
	for (j = 0; j < 64; j++)
	{
		modbus->ReqBuf[j] = 0;
	}

}
int16_t status_cal_mode =0;
void modbus(uint8_t slave_add, MB_sType *modbus,void (*tx_enable)(void)
			,MOBUS_Table_struct table_reg[],MOBUS_Table_struct table_cal_mode[]
			,MOBUS_Table_struct table_cal_data[]
			,MOBUS_Table_struct table_hardware_interface[])
{
	if (modbus->RxTimeOut >= 5 && modbus->ByteReq != 0)
	{
			switch (modbus->ReqBuf[1])
			{
			case READ_HOLDING_REGISTERS:
			case READ_INPUT_REGISTERS:
				read_multi_registers(slave_add, modbus, tx_enable);
				break;
			case DIAGNOSTICS:
				loop_back_diagnostic(slave_add, modbus, tx_enable);
				break;
			case WRITE_SINGLE_REGISTER:
				preset_a_single_register(slave_add, modbus, tx_enable);
				break;
			case WRITE_MULTIPLE_REGISTER:
				preset_multiple_register(slave_add, modbus, tx_enable);
				break;
			default:
				crc16(modbus, modbus->ReqBuf, modbus->ByteReq - 2);
				if (modbus->CrcHi != modbus->ReqBuf[modbus->ByteReq - 2]
						|| modbus->CrcLo != modbus->ReqBuf[modbus->ByteReq - 1])
					break;
				exeption_response(slave_add, ILLEGAL_FUNCTION, modbus,
						tx_enable);
				break;
			}
		modbus->ByteReq = 0;
		rx1_en();
		//	clear_modbus_buffer(modbus);

	}
	else
	{
		modbus->RxTimeOut++;
	}
}

void MODBUS1_IT(void){
	if(!modbus1.FRX)
	{
		modbus1.FRX=1;
		modbus1.ByteReq=0;
	}
	modbus1.RxTimeOut=0;
	modbus1.ReqBuf[modbus1.ByteReq++]=rxBuffer_modbus1;
	if(modbus1.ByteReq>=247)
	{
		modbus1.ByteReq=0;
	}
}
