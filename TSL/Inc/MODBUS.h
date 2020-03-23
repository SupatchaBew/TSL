/**
  ******************************************************************************
  * File Name          	: MODBUS.h
  * Description        	: This file modbus.
  * Date				: 12/12/2019
  * Author				: R&D
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MODBUS_H_
#define MODBUS_H_
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "MODBUS_TABLE_REGISTER.h"

 /* Exported types ------------------------------------------------------------*/
 enum MODBUS_FUNCTION{
 	READ_COILS=1,
 	READ_DISCRETE_INPUT,
 	READ_HOLDING_REGISTERS,
 	READ_INPUT_REGISTERS,
 	WRITE_SINGLE_COIL,
 	WRITE_SINGLE_REGISTER,
 	READ_EXCEPTION_STATUS,
 	DIAGNOSTICS,
 	RESERVED_COMMAND1,
 	RESERVED_COMMAND2,
 	GET_COMM_EVENT_COUNTER,
 	GET_COMM_EVENT_LOG,
 	RESERVED_COMMAND3,
 	RESERVED_COMMAND4,
 	WRITE_MULTIPLE_COIL,
 	WRITE_MULTIPLE_REGISTER,
 	ENABLE_CALIBRATION_MODE = 0x98,
 	DISABLE_CALIBRATION_MODE = 0x99
 };
 enum EXCEPTION_CODE{ILLEGAL_FUNCTION=1, ILLEGAL_DATA_ADDRESS, ILLEGAL_DATA_VALUE};

 typedef struct {
 	uint16_t ByteReq;
 	uint16_t ByteRsp;
 	uint8_t RxTimeOut;
 	uint8_t TxTimeOut;
 	uint8_t CrcHi;
 	uint8_t CrcLo;
 	uint8_t ReqBuf[247];
 	uint8_t RspBuf[300];
 	uint8_t FTX;
 	uint8_t FRX;
 	uint8_t *MBdptr;
 }MB_sType;

 /* Exported functions prototypes ---------------------------------------------*/
 extern int16_t status_cal_mode;

 extern MB_sType modbus1;
 extern MB_sType modbus3;
 extern int16_t status_cal_mode;

 extern uint8_t rxBuffer_modbus1;
 extern uint8_t rxBuffer_modbus3;

/* Exported functions prototypes ---------------------------------------------*/
void crc16(MB_sType *modbus, uint8_t *dptr, uint8_t n);
void loop_back_diagnostic(uint8_t slave_address,MB_sType *modbus,void (*tx_enable)(void));
void exeption_response(uint8_t slave_address,uint8_t ExeptionCode, MB_sType *modbus,
	void (*tx_enable)(void));

//void read_multi_registers(uint8_t slave_add, MB_sType *modbus,void (*tx_enable)(void)
//							,MOBUS_Table_struct table_reg[],MOBUS_Table_struct table_cal[]
//							,MOBUS_Table_struct table_cal_mode[],MOBUS_Table_struct table_hardware_interface[]);
void read_multi_registers(uint8_t slave_add, MB_sType *modbus, void (*tx_enable)(void));

void preset_a_single_register(uint8_t slave_address, MB_sType *modbus,void (*tx_enable)(void));
//extern void preset_a_single_register(uint8_t slave_address, MB_sType *modbus,void (*tx_enable)(void)
//	,MOBUS_Table_struct table_reg[],MOBUS_Table_struct table_cal_mode[],MOBUS_Table_struct table_cal_data[]);

extern void modbus(uint8_t slave_add, MB_sType *modbus,void (*tx_enable)(void)
	,MOBUS_Table_struct table_reg[],MOBUS_Table_struct table_cal_mode[]
	,MOBUS_Table_struct table_cal_data[],MOBUS_Table_struct table_hardware_interface[]);

extern void run_modbus();

extern void tx1_en(void);
extern void rx1_en(void);
extern void tx3_en(void);
extern void rx3_en(void);
extern void MODBUS1_IT(void);
extern void MODBUS3_IT(void);

#endif /* MODBUS_H_ */
/************************ (C) COPYRIGHT PRIMUS *****END OF FILE****/
