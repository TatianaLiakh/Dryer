/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "SCMext.h" /* Common files for all generated c-files */
#include "SCMxvar.h"  /* Var-images */

void P0 (void) /* �������: INIT */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - ���������: InitialSetup */

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
				case C_5:
					Set_Start(2);
					break;
				case C_6:
					P1V0 = C_3;
					break;
			};
		}
		
			break;
		default:
			break;
	}
}

void P2 (void) /* �������: TestTankControl */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - ���������: RunTestNormalDesiredLevelControl */

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
		case 2:    /*  P2S2() - ���������: RunTestMinimumDesiredLevelControl */

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
		case 4:    /*  P2S4() - ���������: RunTestMaximumDesiredLevelControl */

		Set_Start(5);
		Set_State(2, 5);
			break;
		case 5:    /*  P2S5() - ���������: IdilingTest3 */

		if (P1V0 == C_3)
		{
			Set_Stop(5);
			Set_State(2, 6);
		}
			break;
		case 6:    /*  P2S6() - ���������: Finish */

		SendMsgToVerificationModuleCode(C_9);
		Set_Stop(2);
			break;
		default:
			break;
	}
}

void P3 (void) /* �������: TestNormalDesiredLevelControl */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - ���������: InitialSetup */

		P0V0 = (C_0+C_1)/2; 
		SendMsgFloatParamToControlAlgorythm(C_7, P0V0);
		SendMsgFloatParamToVerificationModule(C_8, P0V0);
		Set_State(3, 1);
			break;
		case 1:    /*  P3S1() - ���������: Idiling */

		
			break;
		default:
			break;
	}
}

void P4 (void) /* �������: TestMinimumDesiredLevelControl */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - ���������: InitialSetup */

		SendMsgFloatParamToControlAlgorythm(C_7, 0);
		SendMsgFloatParamToVerificationModule(C_8, 0);
		Set_State(4, 1);
			break;
		case 1:    /*  P4S1() - ���������: Idiling */

		
			break;
		default:
			break;
	}
}

void P5 (void) /* �������: TestMaximumDesiredLevelControl */
{
	switch (Check_State(5)) {

		case 0:    /*  P5S0() - ���������: InitialSetup */

		SendMsgFloatParamToControlAlgorythm(C_7, C_4);
		SendMsgFloatParamToVerificationModule(C_8, C_4);
		Set_State(5, 1);
			break;
		case 1:    /*  P5S1() - ���������: Idiling */

		
			break;
		default:
			break;
	}
}
