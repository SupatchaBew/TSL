/*
 * MODBUS_TABLE_REGISTER.c
 *
 *  Created on: 12 ธ.ค. 2560
 *      Author: Administrator
 */
#include "MODBUS_TABLE_REGISTER.h"
#include "global.h"
#include "initial_parameter.h"
//#include "driver_display.h"
#include "driver_Input.h"
#include "driver_Output.h"

#include <stdio.h>

#define MAX_INH  2000
#define MIN_INH -2000

#define MAX_INL  2000
#define MIN_INL -2000

MOBUS_Table_struct modbus_table_reg[] = {
		{.add_register = &trig_H1[2].Counter, .max = 9999, 	.min = -1999}
//{.add_register = &sInput.status, .max = 9999, 	.min = -1999},
//{.add_register = &sInput.Event, .max = 9999, 	.min = -1999},
//{.add_register = &sOutput.Byte, .max = 9999, 	.min = -1999},
//
//{.add_register = &nValue.TIME,		.max = LIMIT_MAX_TIME,			.min = LIMIT_MIN_TIME},
//{.add_register = &nValue.TYPEIN, 		.max = LIMIT_MAX_TYPEIN, 	 	.min = LIMIT_MIN_TYPEIN},
//{.add_register = &nValue.SPC.H,		.max = LIMIT_MAX_SPC, 			.min = LIMIT_MIN_SPC},
//{.add_register = &nValue.SPC.L,		.max = LIMIT_MAX_SPC, 			.min = LIMIT_MIN_SPC},
//{.add_register = &nValue.CNT.H, 		.max = LIMIT_MAX_CNT,			.min = LIMIT_MIN_CNT},
//{.add_register = &nValue.CNT.L, 		.max = LIMIT_MAX_CNT,			.min = LIMIT_MIN_CNT},
//{.add_register = &nValue.ENC.H, 		.max = LIMIT_MAX_ENC, 			.min = LIMIT_MIN_ENC},
//{.add_register = &nValue.ENC.L, 		.max = LIMIT_MAX_ENC, 			.min = LIMIT_MIN_ENC},
//{.add_register = &nValue.ENCset.H, 	.max = LIMIT_MAX_ENC_SET, 		.min = LIMIT_MIN_ENC_SET},
//{.add_register = &nValue.ENCset.L, 	.max = LIMIT_MAX_ENC_SET, 		.min = LIMIT_MIN_ENC_SET},
//{.add_register = &nValue.ENCsetLow.H, .max = LIMIT_MAX_ENC_SET, 		.min = LIMIT_MIN_ENC_SET},
//{.add_register = &nValue.ENCsetLow.L, .max = LIMIT_MAX_ENC_SET, 		.min = LIMIT_MIN_ENC_SET},
//{.add_register = &nValue.ENCmul.H, 	.max = LIMIT_MAX_ENC_MUL, 		.min = LIMIT_MIN_ENC_MUL},
//{.add_register = &nValue.ENCmul.L, 	.max = LIMIT_MAX_ENC_MUL, 		.min = LIMIT_MIN_ENC_MUL},
//{.add_register = &nValue.ENCdiv.H,	.max = LIMIT_MAX_ENC_DIV, 		.min = LIMIT_MIN_ENC_DIV}, //
//{.add_register = &nValue.ENCdiv.L,	.max = LIMIT_MAX_ENC_DIV, 		.min = LIMIT_MIN_ENC_DIV}, //
//{.add_register = &nValue.ENCbuffer.H,	.max = 999999, 					.min = 0}, //
//{.add_register = &nValue.ENCbuffer.L,	.max = 999999, 					.min = 0}, //
//{.add_register = &nValue.Bandrate,	.max = LIMIT_MAX_BAUNDRATE, 	.min = LIMIT_MIN_BAUNDRATE}, ///>> 1200,2400,4800,9600,19200,38400,57600
//{.add_register = &nValue.Address, 	.max = LIMIT_MAX_ADDRESS,		.min = LIMIT_MIN_ADDRESS},
//{.add_register = &nValue.TypeCom, 	.max = LIMIT_MAX_TYPECOM, 		.min = LIMIT_MIN_TYPECOM}, ///>> 8n1 , 8n2 , 8e1 , 8e2 , 8o1, 8o2
//
//{.add_register = &Value[0].INP, .max = LIMIT_MAX_INP, 		.min = LIMIT_MIN_INP},
//{.add_register = &Value[0].PVS, .max = 9999, 	.min = -1999},
//{.add_register = &Value[0].PVG, .max = LIMIT_MAX_PVG, 		.min = LIMIT_MIN_PVG},
//{.add_register = &Value[0].PVF, .max = LIMIT_MAX_PVF, 		.min = LIMIT_MIN_PVF},
//{.add_register = &Value[0].DP, 	.max = 3, 		.min = 0},
//{.add_register = &Value[0].C_F, .max = 1, 		.min = 0},
//{.add_register = &Value[0].ABS, .max = 1, 		.min = 0},
//{.add_register = &Value[0].INV, .max = 1, 		.min = 0},
//{.add_register = &Value[0].INH, .max = MAX_INH, 	.min = MIN_INH},
//{.add_register = &Value[0].INL, .max = MAX_INL, 	.min = MIN_INL},
//{.add_register = &Value[0].SLH, .max = 9999,	.min = -1999},
//{.add_register = &Value[0].SLL, .max = 9999, 	.min = -1999},
//{.add_register = &Value[0].ALF, .max = LIMIT_MAX_ALF, 		.min = LIMIT_MIN_ALF},
//{.add_register = &Value[0].ALH, .max = 9999, 	.min = -1999},
//{.add_register = &Value[0].ALL, .max = 9999,	.min = -1999},
//{.add_register = &Value[0].HYS, .max = 9999,	.min = -1999},
//{.add_register = &Value[0].TON, .max = LIMIT_MAX_TON, 		.min = LIMIT_MIN_TON},
//{.add_register = &Value[0].TOFF,.max = LIMIT_MAX_TOFF, 		.min = LIMIT_MIN_TOFF},
//{.add_register = &Value[0].OPR, .max = LIMIT_MAX_OPR, 		.min = LIMIT_MIN_OPR}, ///>> None , Sum , DiFF ,Avg
//
//{.add_register = &Value[1].INP, .max = LIMIT_MAX_INP, 		.min = LIMIT_MIN_INP},
//{.add_register = &Value[1].PVS, .max = 9999, 	.min = -1999},
//{.add_register = &Value[1].PVG, .max = LIMIT_MAX_PVG, 	.min = LIMIT_MIN_PVG},
//{.add_register = &Value[1].PVF, .max = LIMIT_MAX_PVF, 	.min = LIMIT_MIN_PVF},
//{.add_register = &Value[1].DP, 	.max = 3, 		.min = 0},
//{.add_register = &Value[1].C_F, .max = 1, 		.min = 0},
//{.add_register = &Value[1].ABS, .max = 1, 		.min = 0},
//{.add_register = &Value[1].INV, .max = 1, 		.min = 0},
//{.add_register = &Value[1].INH, .max = MAX_INH, 	.min = MIN_INH},
//{.add_register = &Value[1].INL, .max = MAX_INL, 	.min = MIN_INL},
//{.add_register = &Value[1].SLH, .max = 9999,	.min = -1999},
//{.add_register = &Value[1].SLL, .max = 9999, 	.min = -1999},
//{.add_register = &Value[1].ALF, .max = LIMIT_MAX_ALF, 		.min = LIMIT_MIN_PVF},
//{.add_register = &Value[1].ALH, .max = 9999, 	.min = -1999},
//{.add_register = &Value[1].ALL, .max = 9999,	.min = -1999},
//{.add_register = &Value[1].HYS, .max = 9999,	.min = -1999},
//{.add_register = &Value[1].TON, .max = LIMIT_MAX_TON, 		.min = LIMIT_MIN_TON},
//{.add_register = &Value[1].TOFF,.max = LIMIT_MAX_TOFF, 		.min = LIMIT_MIN_TOFF},
//{.add_register = &Value[1].OPR, .max = LIMIT_MAX_OPR, 		.min = LIMIT_MIN_OPR}, ///>> None , Sum , DiFF ,Avg
//
//{.add_register = &Value[2].INP, .max = LIMIT_MAX_INP, 		.min = LIMIT_MIN_INP},
//{.add_register = &Value[2].PVS, .max = 9999, 	.min = -1999},
//{.add_register = &Value[2].PVG, .max = LIMIT_MAX_PVG, 	.min = LIMIT_MIN_PVG},
//{.add_register = &Value[2].PVF, .max = LIMIT_MAX_PVF, 	.min = LIMIT_MIN_PVF},
//{.add_register = &Value[2].DP, 	.max = 3, 		.min = 0},
//{.add_register = &Value[2].C_F, .max = 1, 		.min = 0},
//{.add_register = &Value[2].ABS, .max = 1, 		.min = 0},
//{.add_register = &Value[2].INV, .max = 1, 		.min = 0},
//{.add_register = &Value[2].INH, .max = MAX_INH, 	.min = MIN_INH},
//{.add_register = &Value[2].INL, .max = MAX_INL, 	.min = MIN_INL},
//{.add_register = &Value[2].SLH, .max = 9999,	.min = -1999},
//{.add_register = &Value[2].SLL, .max = 9999, 	.min = -1999},
//{.add_register = &Value[2].ALF, .max = LIMIT_MAX_ALF, 		.min = LIMIT_MIN_ALF},
//{.add_register = &Value[2].ALH, .max = 9999, 	.min = -1999},
//{.add_register = &Value[2].ALL, .max = 9999,	.min = -1999},
//{.add_register = &Value[2].HYS, .max = 9999,	.min = -1999},
//{.add_register = &Value[2].TON, .max = LIMIT_MAX_TON, 		.min = LIMIT_MIN_TON},
//{.add_register = &Value[2].TOFF,.max = LIMIT_MAX_TOFF, 		.min = LIMIT_MIN_TOFF},
//{.add_register = &Value[2].OPR, .max = LIMIT_MAX_OPR, 		.min = LIMIT_MIN_OPR}, ///>> None , Sum , DiFF ,Avg
//
//{.add_register = &Value[3].INP, .max = LIMIT_MAX_INP, 		.min = LIMIT_MIN_INP},
//{.add_register = &Value[3].PVS, .max = 9999, 	.min = -1999},
//{.add_register = &Value[3].PVG, .max = LIMIT_MAX_PVG, 	.min = LIMIT_MIN_PVG},
//{.add_register = &Value[3].PVF, .max = LIMIT_MAX_PVF, 	.min = LIMIT_MIN_PVF},
//{.add_register = &Value[3].DP, 	.max = 3, 		.min = 0},
//{.add_register = &Value[3].C_F, .max = 1, 		.min = 0},
//{.add_register = &Value[3].ABS, .max = 1, 		.min = 0},
//{.add_register = &Value[3].INV, .max = 1, 		.min = 0},
//{.add_register = &Value[3].INH, .max = MAX_INH, 	.min = MIN_INH},
//{.add_register = &Value[3].INL, .max = MAX_INL, 	.min = MIN_INL},
//{.add_register = &Value[3].SLH, .max = 9999,	.min = -1999},
//{.add_register = &Value[3].SLL, .max = 9999, 	.min = -1999},
//{.add_register = &Value[3].ALF, .max = LIMIT_MAX_ALF, 		.min = LIMIT_MIN_ALF},
//{.add_register = &Value[3].ALH, .max = 9999, 	.min = -1999},
//{.add_register = &Value[3].ALL, .max = 9999,	.min = -1999},
//{.add_register = &Value[3].HYS, .max = 9999,	.min = -1999},
//{.add_register = &Value[3].TON, .max = LIMIT_MAX_TON, 		.min = LIMIT_MIN_TON},
//{.add_register = &Value[3].TOFF,.max = LIMIT_MAX_TOFF, 		.min = LIMIT_MIN_TOFF},
//{.add_register = &Value[3].OPR, .max = LIMIT_MAX_OPR, 		.min = LIMIT_MIN_OPR}, ///>> None , Sum , DiFF ,Avg
//
//{.add_register = &Value[4].INP, .max = LIMIT_MAX_INP, 		.min = LIMIT_MIN_INP},
//{.add_register = &Value[4].PVS, .max = 9999, 	.min = -1999},
//{.add_register = &Value[4].PVG, .max = LIMIT_MAX_PVG, 	.min = LIMIT_MIN_PVG},
//{.add_register = &Value[4].PVF, .max = LIMIT_MAX_PVF, 		.min = LIMIT_MIN_PVF},
//{.add_register = &Value[4].DP, 	.max = 3, 		.min = 0},
//{.add_register = &Value[4].C_F, .max = 1, 		.min = 0},
//{.add_register = &Value[4].ABS, .max = 1, 		.min = 0},
//{.add_register = &Value[4].INV, .max = 1, 		.min = 0},
//{.add_register = &Value[4].INH, .max = MAX_INH, 	.min = MIN_INH},
//{.add_register = &Value[4].INL, .max = MAX_INL, 	.min = MIN_INL},
//{.add_register = &Value[4].SLH, .max = 9999,	.min = -1999},
//{.add_register = &Value[4].SLL, .max = 9999, 	.min = -1999},
//{.add_register = &Value[4].ALF, .max = LIMIT_MAX_ALF, 		.min = LIMIT_MIN_ALF},
//{.add_register = &Value[4].ALH, .max = 9999, 	.min = -1999},
//{.add_register = &Value[4].ALL, .max = 9999,	.min = -1999},
//{.add_register = &Value[4].HYS, .max = 9999,	.min = -1999},
//{.add_register = &Value[4].TON, .max = LIMIT_MAX_TON, 		.min = LIMIT_MIN_TON},
//{.add_register = &Value[4].TOFF,.max = LIMIT_MAX_TOFF, 		.min = LIMIT_MIN_TOFF},
//{.add_register = &Value[4].OPR, .max = LIMIT_MAX_OPR, 		.min = LIMIT_MIN_OPR}, ///>> None , Sum , DiFF ,Avg
//
//{.add_register = &Value[5].INP, .max = LIMIT_MAX_INP, 		.min = LIMIT_MIN_INP},
//{.add_register = &Value[5].PVS, .max = 9999, 	.min = -1999},
//{.add_register = &Value[5].PVG, .max = LIMIT_MAX_PVG, 	.min = LIMIT_MIN_PVG},
//{.add_register = &Value[5].PVF, .max = LIMIT_MAX_PVF, 	.min = LIMIT_MIN_PVF},
//{.add_register = &Value[5].DP, 	.max = 3, 		.min = 0},
//{.add_register = &Value[5].C_F, .max = 1, 		.min = 0},
//{.add_register = &Value[5].ABS, .max = 1, 		.min = 0},
//{.add_register = &Value[5].INV, .max = 1, 		.min = 0},
//{.add_register = &Value[5].INH, .max = MAX_INH, 	.min = MIN_INH},
//{.add_register = &Value[5].INL, .max = MAX_INL, 	.min = MIN_INL},
//{.add_register = &Value[5].SLH, .max = 9999,	.min = -1999},
//{.add_register = &Value[5].SLL, .max = 9999, 	.min = -1999},
//{.add_register = &Value[5].ALF, .max = LIMIT_MAX_ALF, 		.min = LIMIT_MIN_ALF},
//{.add_register = &Value[5].ALH, .max = 9999, 	.min = -1999},
//{.add_register = &Value[5].ALL, .max = 9999,	.min = -1999},
//{.add_register = &Value[5].HYS, .max = 9999,	.min = -1999},
//{.add_register = &Value[5].TON, .max = LIMIT_MAX_TON, 		.min = LIMIT_MIN_TON},
//{.add_register = &Value[5].TOFF,.max = LIMIT_MAX_TOFF, 		.min = LIMIT_MIN_TOFF},
//{.add_register = &Value[5].OPR, .max = LIMIT_MAX_OPR, 		.min = LIMIT_MIN_OPR} ///>> None , Sum , DiFF ,Avg
};

//MOBUS_Table_struct modbus_table_Hardware_Interface[] =
//{
//	{.add_register = &DigitData[0],						.max = 255, 	.min = 0}, //>> [ digit 1],[Alarm 1-6 ,com]
//	{.add_register = &DigitData[2],						.max = 255, 	.min = 0}, //>> [digit 3] ,[digit 2]
//	{.add_register = &DigitData[4],						.max = 255, 	.min = 0}, //>> [digit 5] ,[digit 4]
//	{.add_register = &DigitData[6],						.max = 255, 	.min = 0}, //>> Blank ,  [C , F ,Pk]
//};

/**  Address  Calibrate Register storage **/

uint16_t get_size_Table()
{
	return (sizeof(modbus_table_reg) / sizeof((modbus_table_reg)[0]));
}
uint16_t get_size_Table_Hardware_interface()
{
//	return NELEMS(modbus_table_Hardware_Interface);
}
void set_register(uint16_t address , uint16_t index  )
{
	table_register[index] = address;
}
int* get_address(uint16_t index)
{
	return table_register[index];
}
int16_t get_Value(int index)
{
	return *table_register[index];
}
