/**
  ******************************************************************************
  * File Name          	: initial_parameter.c
  * Description        	: This file initialize paramter.
  * Date				: 4/11/2019
  * Author				: R&D
  ******************************************************************************
  */
#include "initial_parameter.h"

#include "main.h"
#include "MODBUS_TABLE_REGISTER.h"

uint8_t index_chanal = 0;
uint16_t count_index = 0;

uint32_t EncBuffer;
uint32_t EncResult;
uint32_t ENCLast;					// Encoder Last

Hardware_Option_Type Hardware_value;
NORMAL_Parameter_Typedef nValue;

/**
 * @brief	Read normal config from memory.
 * @param 	address - Index of address
 * @param 	value - normal config typedef
 * @retval  none
 */
void Read_frame_nValue(int16_t address, NORMAL_Parameter_Typedef *value)
{
//	READ_PARAMETER(EEP_TIME		* 2,	(uint8_t *)&value->TIME, 		2);
//	READ_PARAMETER(EEP_TYPEIN	* 2,	(uint8_t *)&value->TYPEIN,		2);
//	READ_PARAMETER(EEP_SPC		* 2, 	(uint8_t *)&value->SPC,			4);
//	READ_PARAMETER(EEP_CNT		* 2, 	(uint8_t *)&value->CNT,			4);
//	READ_PARAMETER(EEP_PASS1	* 2, 	(uint8_t *)&value->PASSWORD[0], 2);
//	READ_PARAMETER(EEP_PASS2	* 2, 	(uint8_t *)&value->PASSWORD[1], 2);
//	READ_PARAMETER(EEP_PASS3	* 2, 	(uint8_t *)&value->PASSWORD[2], 2);
//	READ_PARAMETER(EEP_PASS4	* 2, 	(uint8_t *)&value->PASSWORD[3], 2);
//
//	READ_PARAMETER(EEP_ENC		* 2, 	(uint8_t *)&value->ENC,			4);
//	READ_PARAMETER(EEP_ENCSET	* 2, 	(uint8_t *)&value->ENCset,		4);
//	READ_PARAMETER(EEP_ENCSETLOW	* 2, 	(uint8_t *)&value->ENCsetLow,		4);
//	READ_PARAMETER(EEP_ENCMUL	* 2, 	(uint8_t *)&value->ENCmul,		4);
//	READ_PARAMETER(EEP_ENCDIV	* 2, 	(uint8_t *)&value->ENCdiv,		4);
//
//	READ_PARAMETER(EEP_ADDRESS	* 2,	(uint8_t *)&value->Address, 	2);
//	READ_PARAMETER(EEP_BAUDRATE	* 2,	(uint8_t *)&value->Bandrate,	2);
//	READ_PARAMETER(EEP_TYPECOM	* 2,	(uint8_t *)&value->TypeCom,		2);
//
//	value->ENCbuffer.Word = (value->ENC.Word * value->ENCdiv.Word) / value->ENCmul.Word;
}

/**
 * @brief	Read single value from memory.
 * @param 	address - Index of address
 * @param 	var - pointer value
 * @retval  none
 */
void Read_single_value(int16_t address, int16_t *var)
{
	READ_PARAMETER((address+10) * 2, (uint8_t *)var, 2);
}

/**
 * @brief	Save normal config to memory.
 * @param 	address - Index of address
 * @param 	value - normal config typedef
 * @retval  none
 */
void Save_frame_nValue(int16_t address, NORMAL_Parameter_Typedef *value)
{
//	WRITE_PARAMETER(EEP_TIME	* 2,	(uint8_t *)&value->TIME, 		2);
//	WRITE_PARAMETER(EEP_TYPEIN	* 2,	(uint8_t *)&value->TYPEIN,		2);
//	WRITE_PARAMETER(EEP_SPC		* 2, 	(uint8_t *)&value->SPC.Word,	4);
//	WRITE_PARAMETER(EEP_CNT		* 2, 	(uint8_t *)&value->CNT.Word,	4);
//	WRITE_PARAMETER(EEP_PASS1	* 2, 	(uint8_t *)&value->PASSWORD[0], 2);
//	WRITE_PARAMETER(EEP_PASS2	* 2, 	(uint8_t *)&value->PASSWORD[1], 2);
//	WRITE_PARAMETER(EEP_PASS3	* 2, 	(uint8_t *)&value->PASSWORD[2], 2);
//	WRITE_PARAMETER(EEP_PASS4	* 2, 	(uint8_t *)&value->PASSWORD[3], 2);
//
//	WRITE_PARAMETER(EEP_ENC		* 2, 	(uint8_t *)&value->ENC.Word,	4);
//	WRITE_PARAMETER(EEP_ENCSET	* 2, 	(uint8_t *)&value->ENCset.Word,	4);
//	WRITE_PARAMETER(EEP_ENCSETLOW	* 2, 	(uint8_t *)&value->ENCsetLow.Word,	4);
//	WRITE_PARAMETER(EEP_ENCMUL	* 2, 	(uint8_t *)&value->ENCmul.Word,	4);
//	WRITE_PARAMETER(EEP_ENCDIV	* 2, 	(uint8_t *)&value->ENCdiv.Word,	4);
//
//	WRITE_PARAMETER(EEP_ADDRESS	* 2,	(uint8_t *)&value->Address, 	2);
//	WRITE_PARAMETER(EEP_BAUDRATE* 2,	(uint8_t *)&value->Bandrate,	2);
//	WRITE_PARAMETER(EEP_TYPECOM	* 2,	(uint8_t *)&value->TypeCom,		2);
}

/**
 * @brief	Save single value to memory.
 * @param 	address - Index of address
 * @param 	value - pointer value
 * @retval  none
 */
void Save_single_value(int16_t address, uint16_t *value)
{
	WRITE_PARAMETER(address*2, (uint8_t *)value, 2);
}

/**
 * @brief	Save single value to memory.
 * @param 	address - Index of address
 * @param 	value - pointer value
 * @retval  none
 */
void Save_single_value_byReg(uint16_t reg)
{
//	switch(reg)
//	{
//	case REG_MB_SPC_MSB:
//	case REG_MB_SPC_LSB:
//		if(nValue.SPC.Word > LIMIT_MAX_SPC) nValue.SPC.Word = LIMIT_MAX_SPC;
//		else if(nValue.SPC.Word < LIMIT_MIN_SPC) nValue.SPC.Word = LIMIT_MIN_SPC;
//		WRITE_PARAMETER(EEP_SPC	* 2, (uint8_t *)&nValue.SPC.Word,	4);
//		break;
//	case REG_MB_CNT_MSB:
//	case REG_MB_CNT_LSB:
//		if(nValue.CNT.Word > LIMIT_MAX_CNT) nValue.CNT.Word = LIMIT_MAX_CNT;
//		else if(nValue.CNT.Word < LIMIT_MIN_CNT) nValue.CNT.Word = LIMIT_MIN_CNT;
//		WRITE_PARAMETER(EEP_CNT	* 2, (uint8_t *)&nValue.CNT.Word,	4);
//		break;
//	case REG_MB_ENC_MSB:
//	case REG_MB_ENC_LSB:
//		if(nValue.ENC.Word > LIMIT_MAX_ENC) nValue.ENC.Word = LIMIT_MAX_ENC;
//		else if(nValue.ENC.Word < LIMIT_MIN_ENC) nValue.ENC.Word = LIMIT_MIN_ENC;
//		nValue.ENCbuffer.Word = (nValue.ENC.Word * nValue.ENCdiv.Word) / nValue.ENCmul.Word;
//		WRITE_PARAMETER(EEP_ENC	* 2, (uint8_t *)&nValue.ENC.Word,	4);
//		break;
//	case REG_MB_ENCSET_MSB:
//	case REG_MB_ENCSET_LSB:
//		if(nValue.ENCset.Word > LIMIT_MAX_ENC_SET) nValue.ENCset.Word = LIMIT_MAX_ENC_SET;
//		else if(nValue.ENCset.Word < nValue.ENCsetLow.Word) nValue.ENCset.Word = nValue.ENCsetLow.Word + 1;
//		WRITE_PARAMETER(EEP_ENCSET * 2, (uint8_t *)&nValue.ENCset.Word,	4);
//		break;
//	case REG_MB_ENCSETLOW_MSB:
//	case REG_MB_ENCSETLOW_LSB:
//		if(nValue.ENCsetLow.Word > nValue.ENCset.Word) nValue.ENCsetLow.Word = nValue.ENCset.Word - 1;
//		else if(nValue.ENCsetLow.Word < LIMIT_MIN_ENC_SET) nValue.ENCsetLow.Word = LIMIT_MIN_ENC_SET;
//		WRITE_PARAMETER(EEP_ENCSETLOW * 2, (uint8_t *)&nValue.ENCsetLow.Word,	4);
//		break;
//	case REG_MB_ENCMUL_MSB:
//	case REG_MB_ENCMUL_LSB:
//		if(nValue.ENCmul.Word > LIMIT_MAX_ENC_MUL) nValue.ENCmul.Word = LIMIT_MAX_ENC_MUL;
//		else if(nValue.ENCmul.Word < LIMIT_MIN_ENC_MUL) nValue.ENCmul.Word = LIMIT_MIN_ENC_MUL;
//		WRITE_PARAMETER(EEP_ENCMUL	* 2, (uint8_t *)&nValue.ENCmul.Word,	4);
//		break;
//	case REG_MB_ENCDIV_MSB:
//	case REG_MB_ENCDIV_LSB:
//		if(nValue.ENCdiv.Word > LIMIT_MAX_ENC_DIV) nValue.ENCdiv.Word = LIMIT_MAX_ENC_DIV;
//		else if(nValue.ENCdiv.Word < LIMIT_MIN_ENC_DIV) nValue.ENCdiv.Word = LIMIT_MIN_ENC_DIV;
//		WRITE_PARAMETER(EEP_ENCDIV	* 2, (uint8_t *)&nValue.ENCdiv.Word,	4);
//		break;
//	}
}

/**
 * @brief	Initialize Parameter.
 * @param 	var - typedef parameter
 * @retval  none
 */
void Set_Initial_nValue(NORMAL_Parameter_Typedef *var)
{
	var->Address = 1;
	var->Bandrate = 4;
	var->TypeCom = 0;
}

/**
 * @brief	Load Parameter from memory and initialize.
 * @param 	none
 * @retval  none
 */
void Load_parameter()
{
	uint8_t eep_check = 0;
	uint8_t eep_check_end = 0;

	for( int i=0; i<=20; i++)
	{
		READ_PARAMETER(EEP_START, (uint8_t * ) &eep_check, 1);
		READ_PARAMETER(EEP_END*2, (uint8_t * ) &eep_check_end, 1);

		if (eep_check != 'T' || eep_check_end != 's')
		{
			if( i>=20 )
			{
				eep_check = 'T';
				WRITE_PARAMETER(EEP_START, &eep_check, 1);

				Set_Initial_nValue(&nValue);
				Save_frame_nValue(EEP_TIME, &nValue);

				/** ------------------------------------------------**/
				eep_check_end = 's';
				WRITE_PARAMETER(EEP_END*2, &eep_check_end, 1);
			}
		}
		else
			break;

		HAL_Delay(10);
	}

	Read_frame_nValue(EEP_TIME, &nValue);
}
