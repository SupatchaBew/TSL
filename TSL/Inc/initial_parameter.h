/**
  * @file    initial_parameter.h
  * @author  Primus_R&D_Indicator (zung_zeny808@gmail.com)
  * @version V1.0.0
  * @date    21-November-2017
  * @brief   This Application in file Config_SPI build for be driver of SPI Module
  * 		 and help for it easy to use
  *
*/
#include "stdint-gcc.h"
#include "fm25lxx.h"

#ifndef INITIAL_PARAMETER_H_
#define INITIAL_PARAMETER_H_

typedef union
{
	uint32_t Word;
	struct
	{
		uint16_t L;
		uint16_t H;
	};
} u32_Type;

typedef union
{
	int32_t Word;
	struct
	{
		int16_t L;
		int16_t H;
	};
} i32_Type;

typedef union
{
	uint16_t Word;
	struct
	{
		uint16_t CH6 :1 ;
		uint16_t RS485 :1 ;
		uint16_t IGNOR :14 ;
	} Bit;
} Hardware_Option_Type;

typedef union
{
	uint16_t Word;
	struct
	{
		uint16_t IGNOR_1  : 1 ;
		uint16_t IGNOR_2  : 1 ;
		uint16_t IGNOR_3  : 1 ;
		uint16_t IGNOR   :13 ;
	}Bit;
}Error_Display_Type;

typedef struct
{
	int16_t Status[2];
	int16_t LastStatus[2];
	int16_t pwmValue[2];
	int16_t Step[2];
	uint16_t Bandrate;
	uint16_t Address;
	uint16_t TypeCom;

	uint16_t major_version;
	uint16_t minor_version;

	uint8_t rundowntoreset[2];
	uint8_t motor_id;

}NORMAL_Parameter_Typedef;

enum Direction{Move_up = 1, Move_down};

extern Hardware_Option_Type Hardware_value;

extern NORMAL_Parameter_Typedef nValue;

extern uint32_t EncBuffer;
extern uint32_t EncResult;
extern uint32_t ENCLast;					// Encoder Last

#define EEP_CHECK_BLANK_START		0x05FF
#define EEP_CHECK_BLANK_END			0x05FF-3

enum EEP_ADDRESS_MEMORY{
	EEP_START = 1,

	EEP_TIME = 2,
	EEP_TYPEIN,
	EEP_SPC,
	EEP_SPC1,
	EEP_CNT,
	EEP_CNT1,
	EEP_PASS1,
	EEP_PASS2,
	EEP_PASS3,
	EEP_PASS4,

	EEP_ENC,
	EEP_ENC1,
	EEP_ENCSET,
	EEP_ENCSET1,
	EEP_ENCSETLOW,
	EEP_ENCSETLOW1,
	EEP_ENCMUL,
	EEP_ENCMUL1,
	EEP_ENCDIV,
	EEP_ENCDIV1,

	EEP_ADDRESS,
	EEP_BAUDRATE,
	EEP_TYPECOM,
	EEP_END
};

#define WRITE_PARAMETER(a,b,c)				FM25LXX_SaveData(a,b,c)
#define READ_PARAMETER(a,b,c)				FM25LXX_LoadData(a,b,c)

extern void Load_parameter();

#define LIMIT_MAX_TIME		 	999
#define LIMIT_MIN_TIME		 	1
#define LIMIT_MAX_TYPEIN	 	2		//>> Limit 0 = 0, Limit 1 = 1, Encoder = 2
#define LIMIT_MIN_TYPEIN	 	0
#define LIMIT_MAX_SPC	 		999999
#define LIMIT_MIN_SPC	 		0
#define LIMIT_MAX_CNT	 		999999
#define LIMIT_MIN_CNT	 		0
#define LIMIT_MAX_ENC	 		999999
#define LIMIT_MIN_ENC	 		-199999
#define LIMIT_MAX_ENC_SET 		999999
#define LIMIT_MIN_ENC_SET  		-199999
#define LIMIT_MAX_ENC_MUL	 	999999
#define LIMIT_MIN_ENC_MUL 		1
#define LIMIT_MAX_ENC_DIV		999999
#define LIMIT_MIN_ENC_DIV  		1
#define LIMIT_MAX_BAUNDRATE 	6  //>> 1200 2400 4800 9600 19200 38400 57600
#define LIMIT_MIN_BAUNDRATE  	0
#define LIMIT_MAX_ADDRESS	 	255
#define LIMIT_MIN_ADDRESS	 	1
#define LIMIT_MAX_TYPECOM 		5	//>> 8n1 8n2 8o1 8o2 8e1 8e2
#define LIMIT_MIN_TYPECOM 		0

#endif /* INITIAL_PARAMETER_H_ */
