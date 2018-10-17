/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "SCMext.h" /* Common files for all generated c-files */
#include "SCMxvar.h"  /* Var-images */

void P0 (void) /* �������: Init */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - ���������: Start */
  
	Set_Start(1); 
	Set_Stop(0);
			break;
		default:
			break;
	}
}

void P1 (void) /* �������: ReceiveVMOutputMsg */
{
	switch (Check_State(1)) {

		case 0:    /*  P1S0() - ���������: Start */

		P1V0 = C_2;
		if (GetNextMsgFromVM()) 
		{
			P1V1 = GetMsgCodeFromVM();
			switch (P1V1)
			{
				case C_9:
					Set_Start(2);
					break;
				case C_10:
					P1V0 = C_3;
					break;
			}
		}
		
			break;
		default:
			break;
	}
}

void P2 (void) /* �������: TestDriver */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - ���������: RunTestHandsUnderDryer */

		Set_Start(3);
		Set_State(2, 1);
			break;
		case 1:    /*  P2S1() - ���������: IdilingTest1 */

		if (P1V0 == C_3)
		{
			Set_Stop(3);
			Set_State(2, 2);
		}
			break;
		case 2:    /*  P2S2() - ���������: RunTestRemoveHands */

		Set_Start(4);
		Set_State(2, 3);
			break;
		case 3:    /*  P2S3() - ���������: IdilingTest2 */

		if (P1V0 == C_3)
		{
			Set_Stop(4);
			Set_State(2, 4);
		}
			break;
		case 4:    /*  P2S4() - ���������: Finish */

		SendMsgToVerificationModuleCode(C_8);
		Set_Stop(2);
			break;
		default:
			break;
	}
}

void P3 (void) /* �������: TestHandsUnderDryer */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - ���������: Start */

		SendMsgToVirtualPlantCode(C_4);
		SendMsgToVerificationModuleCode(C_6);
		Set_State(3, 1);
			break;
		case 1:    /*  P3S1() - ���������: Idiling */

		
			break;
		default:
			break;
	}
}

void P4 (void) /* �������: TestRemoveHands */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - ���������: Start */

		SendMsgToVirtualPlantCode(C_5);
		SendMsgToVerificationModuleCode(C_7);
		Set_State(4, 1);
			break;
		case 1:    /*  P4S1() - ���������: Idiling */

		
			break;
		default:
			break;
	}
}
