/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "VMext.h" /* Common files for all generated c-files */
#include "VMxvar.h"  /* Var-images */

void P0 (void) /* �������: Init */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - ���������: Start */
	
			SendMsgSCMCode(C_8); 	
			Set_Start(1);
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
				
					case C_6:
						SendMsgGUICode(C_14);
						SendMsgGUICode(C_15);		
						Set_Start(3);						
						Set_Start(4);
						Set_Start(2); 	
						break;
					case C_7:
						SendMsgGUICode(C_16);
						Set_Stop(2); 
						Set_Stop(1);
						break;
				}
			}
			
			break;
		default:
			break;
	}
}

void P2 (void) /* �������: Terminator */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - ���������: Idling */

			if (Timeout(2, C_5))  Set_State(2, 1);
			break;
		case 1:    /*  P2S1() - ���������: Report */
			
			
			if((!(Check_State(3) & MASK_OF_INACTIVITY)))
			{
				SendMsgGUICode(C_10);
			}
			if((Check_State(3) == STATE_OF_ERROR))
			{
				SendMsgGUICode(C_12);
			}

			Set_Stop(3);
			
					
			if((!(Check_State(4) & MASK_OF_INACTIVITY)))
			{
				SendMsgGUICode(C_11);
			}

			if((Check_State(4) == STATE_OF_ERROR))
			{
				SendMsgGUICode(C_13);
			}
			 
			Set_Stop(4); 			
			SendMsgSCMCode(C_9);
			Set_Stop(2);
			break;
		default:
			break;
	}
}

void P3 (void) /* �������: PausePCyclesControl */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - ���������: WaitingOfCar */

			if(P0V0 == C_0) 
				Set_State(3, 1);
			break;
		case 1:    /*  P3S1() - ���������: WaitingPCycles */

			if(P0V1 == C_0) 
				Set_Error(3);
			if (Timeout(3, C_2))  Set_State(3, 2);
			break;
		case 2:    /*  P3S2() - ���������: PCyclesControl */

			if(P0V1 == C_0) 
				Set_State(3, 3);
			if (Timeout(3, C_4))  Set_Error(3);
			break;
		case 3:    /*  P3S3() - ���������: Idiling */

			
			break;
		default:
			break;
	}
}

void P4 (void) /* �������: DisableMotionForKCyclesControl */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - ���������: Start */

			if(P0V1 == C_0) 
				Set_State(4, 1);
			break;
		case 1:    /*  P4S1() - ���������: WaitingKCycles */

			if(P0V1 == C_1) 
				Set_Error(4);
			if (Timeout(4, C_3))  Set_State(4, 2);
			break;
		case 2:    /*  P4S2() - ���������: KCyclesControl */

			if(P0V1 == C_1) Set_State(4, 3);
				if (Timeout(4, C_4))  Set_Error(4);
			break;
		case 3:    /*  P4S3() - ���������: Idiling */

			
			break;
		default:
			break;
	}
}
