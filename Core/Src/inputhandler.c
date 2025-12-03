#include "inputhandler.h"
#include "gpio.h"
#include "wavegener.h"

int CalcuRbKey(uint16_t inputkey)
{
	int RbKey = 0;
	
	switch(inputkey){
		case NK1_Pin: RbKey = 60;
			break;
		case NK2_Pin: RbKey = 61;							//C4#
			break;
		case NK3_Pin: RbKey = 62;							//D4
			break;
		case NK4_Pin: RbKey = 63;							//D4#
			break;
		case NK5_Pin: RbKey = 64;							//E4
			break;
		case NK6_Pin: RbKey = 65;							//F4
			break;
		case NK7_Pin: RbKey = 66;							//F4#
			break;
		case NK8_Pin: RbKey = 67;							//G4
			break;
		case NK9_Pin: RbKey = 68;							//G4#
			break;
		case NK10_Pin: RbKey = 69;							//A4
			break;
		case NK11_Pin: RbKey = 70;							//A4#
			break;
		case NK12_Pin: RbKey = 71;							//B4
			break;
	}
	
	return RbKey;
}

void ChangeInNote(uint16_t inputkey, int* LEVEL)
{
	int AbKey = 0;
	int RbKey = 0;
	
	if(inputkey == FK1_Pin)
	{
		*LEVEL += 1;
	}
	else if(inputkey == FK2_Pin)
	{
		*LEVEL = 0;
	}
	else if(inputkey == FK3_Pin)
	{
		*LEVEL -= 1;
	}
	else
	{
		RbKey = CalcuRbKey(inputkey);
	}
	
	AbKey = (*LEVEL) * 12 + RbKey;
	
	NoteOn(AbKey);
}
