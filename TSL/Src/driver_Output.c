#include "main.h"
#include "global.h"
//#include "driver_Button.h"
#include "driver_Input.h"
#include "driver_Output.h"
//#include "driver_display.h"

void run_Output(sOutput_sType *Out) {

//	Out->bit.Out_SEL1 = 1;
//	Out->bit.Out_SEL2 = 1;

	OUTPUT_A1(Out->bit.Out_A1);
	OUTPUT_B1(Out->bit.Out_B1);
//	OUTPUT_SEL1(Out->bit.Out_SEL1);

	OUTPUT_A2(Out->bit.Out_A2);
	OUTPUT_B2(Out->bit.Out_B2);
//	OUTPUT_SEL2(Out->bit.Out_SEL2);
}
