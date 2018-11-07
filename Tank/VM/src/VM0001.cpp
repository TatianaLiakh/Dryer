/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "VMext.h" /* Common files for all generated c-files */
#include "VMxvar.h"  /* Var-images */

void P0 (void) /* �������: INIT */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - ���������: InitialSetup */

		SendMsgSCMCode(C_7);
		Set_Start(1);
		Set_Start(3);
		Set_Start(4);
		Set_Start(5);
		Set_Start(6);
		
		Set_Start(2);
		Set_Stop(0);
			break;
		default:
			break;
	}
}

void P1 (void) /* �������: READ_ADC */
{
	switch (Check_State(1)) {

		case 0:    /*  P1S0() - ���������: READ */

		P0V9 = PortsToFloat(P0V0, P0V1, P0V2, P0V3);
		P0V10 = PortsToFloat(P0V4, P0V5, P0V6, P0V7);
		
			break;
		default:
			break;
	}
}

void P2 (void) /* �������: Info */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - ���������: Idiling */

		if (Timeout(2, 50))  
		{
		
			Set_State(2, 0);
		}
			break;
		default:
			break;
	}
}

void P3 (void) /* �������: ReceiveSCMOutputMsg */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - ���������: Start */

    if (GetNextMsgFromSCM()) 
	{
		P3V1 = GetMsgCodeFromSCM();
		switch (P3V1) 
		{
			case C_11:
				P0V8 = GetFloatParamFromSCM();
				Set_Start(7);
				break;
			case C_12:
				SendMsgGUICode(C_21);
				Set_Stop(3);
				break;
		}
	}
	
			break;
		default:
			break;
	}
}

void P4 (void) /* �������: XValueRestrictionsInvariant */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - ���������: Normal */

		if ( P0V9 > C_0)
		{
			SendMsgGUICode(C_15);
			Set_State(4, 1);
		}
		else if (P0V9 < 0)
		{			
			SendMsgGUICode(C_16);
			Set_State(4, 2);
		}
			break;
		case 1:    /*  P4S1() - ���������: OwerflowError */

		if (P0V9 <= C_0) Set_State(4, 0);
			break;
		case 2:    /*  P4S2() - ���������: UnderfillError */

		if (P0V9 >= 0) Set_State(4, 0);
			break;
		default:
			break;
	}
}

void P5 (void) /* �������: UValueRestrictionsInvariant */
{
	switch (Check_State(5)) {

		case 0:    /*  P5S0() - ���������: Normal */

		if ( P0V10 > C_2)
		{
			SendMsgGUICode(C_13);
			Set_State(5, 1);
		}
		else if (P0V10 < 0)
		{			
			SendMsgGUICode(C_14);
			Set_State(5, 2);
		}
			break;
		case 1:    /*  P5S1() - ���������: HighVoltage */

		if ( P0V10 <= C_2) Set_State(5, 0);
			break;
		case 2:    /*  P5S2() - ���������: LowVoltage */

		if ( P0V10 >= 0) Set_State(5, 0);
			break;
		default:
			break;
	}
}

void P6 (void) /* �������: VoltageDerivativeRestrictionsInvariant */
{
	switch (Check_State(6)) {

		case 0:    /*  P6S0() - ���������: Setup */

		P6V1 = P0V10; 
		Set_State(6, 1);
			break;
		case 1:    /*  P6S1() - ���������: Normal */

		if ( ABS(P6V1 - P0V10) >= C_3)
		{
			SendMsgGUICode(C_17);
		}
		P6V1 = P0V10;
		
			break;
		default:
			break;
	}
}

void P7 (void) /* �������: XLevelTendsToDesired */
{
	switch (Check_State(7)) {

		case 0:    /*  P7S0() - ���������: Idiling */
	
		if (Timeout(7, C_5))  Set_State(7, 1);
			break;
		case 1:    /*  P7S1() - ���������: LevelControl */

			if (ABS(P0V9 - P0V8) > C_4) Set_State(7, 2);
			if (Timeout(7, C_6))  
			{
				SendMsgGUICode(C_19);
				SendMsgSCMCode(C_8);
				Set_Stop(7);
			}
			break;
		case 2:    /*  P7S2() - ���������: ProgressError */

		SendMsgSCMCode(C_8);
		SendMsgGUICode(C_18);
		Set_Error(7);
			break;
		default:
			break;
	}
}
