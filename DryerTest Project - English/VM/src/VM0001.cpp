/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "VMext.h" /* Common files for all generated c-files */
#include "VMxvar.h"  /* Var-images */

void P0 (void) /* �������: Init */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - ���������: Start */

		SendMsgToSCM(C_8);
		Set_Start(1);
		Set_Start(4);
		Set_Start(5);
		Set_Stop(0);
			break;
		default:
			break;
	}
}

void P1 (void) /* �������: ReceiveSCMOutputMsg */
{
	switch (Check_State(1)) {

		case 0:    /*  P1S0() - ���������: Start */

    
    if (GetNextMsgFromSCM()) 
	{
		P1V0 = GetMsgCodeFromSCM();
		switch (P1V0) 
		{
			case C_5:
				Set_Start(2);				
				break;
			case C_6: 
				Set_Start(3);
				break;
			case C_7:
				SendMsgGUICode(C_15);
				Set_Stop(1);
				break;
		}
	}
	
			break;
		default:
			break;
	}
}

void P2 (void) /* �������: DryerNormalTurnOnControl */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - ���������: WaitingOfHands */

		if(P0V0 == C_0) 
			Set_State(2, 1);
		if (Timeout(2, C_3))  Set_State(2, 2);
			break;
		case 1:    /*  P2S1() - ���������: WaitingOnLaunch */

		if (P0V1 == C_0)
		{
			SendMsgGUICode(C_10);
			Set_State(2, 3);			
		}
		if (Timeout(2, C_2))  Set_State(2, 2);
			break;
		case 2:    /*  P2S2() - ���������: DryerError */

			SendMsgGUICode(C_12);
			Set_State(2, 3);
			break;
		case 3:    /*  P2S3() - ���������: StopTest */

		SendMsgToSCM(C_9);
		Set_Stop(2);
			break;
		default:
			break;
	}
}

void P3 (void) /* �������: DryerNormalTurnOffControl */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - ���������: WaitingOfHands */

		if(P0V0 == C_1) Set_State(3, 1);
		if (Timeout(3, C_3))  Set_State(3, 2);
			break;
		case 1:    /*  P3S1() - ���������: WaitingOff */

		if (P0V1 == C_1)
		{
			SendMsgGUICode(C_11);
			Set_State(3, 3);			
		}
		if (Timeout(3, C_2))  Set_State(3, 2);
			break;
		case 2:    /*  P3S2() - ���������: DryerError */

			SendMsgGUICode(C_13);
			Set_State(3, 3);
			break;
		case 3:    /*  P3S3() - ���������: StopTest */

		SendMsgToSCM(C_9);
		Set_Stop(3);
			break;
		default:
			break;
	}
}

void P4 (void) /* �������: DryerStateControl */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - ���������: Init */

		P4V1 = P0V1;
		Set_State(4, 1);
			break;
		case 1:    /*  P4S1() - ���������: UpdateState */

		P4V2 = C_1; 
		if (P4V1 != P0V1)
		{
			P4V1 = P0V1;
			P4V2 = C_0;
		}
		
			break;
		default:
			break;
	}
}

void P5 (void) /* �������: InvariantFrequencyControl */
{
	switch (Check_State(5)) {

		case 0:    /*  P5S0() - ���������: Normal */

		if (P4V2 == C_0) 
		{			
			Set_State(5, 1);
		}
			break;
		case 1:    /*  P5S1() - ���������: ControlFreqency */

		if (P4V2 == C_0) 
		{
			SendMsgGUICode(C_14);
			Set_State(5, 0);
		}
		if (Timeout(5, C_4))  Set_State(5, 0);
			break;
		default:
			break;
	}
}
