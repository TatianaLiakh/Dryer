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

			P1V0 = C_0;
			if (GetNextMsgFromVM()) 
			{
				P1V1 = GetMsgCodeFromVM();
				switch (P1V1)
				{
				case C_7:
					Set_Start(2);
					break;
				case C_8:
					P1V0 = C_1;
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

		case 0:    /*  P2S0() - ���������: RunTestNormCar */

			Set_Start(3);
			Set_State(2, 1);
			break;
		case 1:    /*  P2S1() - ���������: IdilingTest1 */

			if (P1V0 == C_1)
			{
				Set_Stop(3);
				Set_State(2, 2);
			}
			break;
		case 2:    /*  P2S2() - ���������: RunTestWrongCar */

			Set_Start(4);
			Set_State(2, 3);
			break;
		case 3:    /*  P2S3() - ���������: IdilingTest2 */

			if (P1V0 == C_1)
			{
				Set_Stop(4);
				Set_State(2, 4);
			}
			break;
		case 4:    /*  P2S4() - ���������: RunTestTwoCars */

			Set_Start(5);
			Set_State(2, 5);
			break;
		case 5:    /*  P2S5() - ���������: IdilingTest3 */

			if (P1V0 == C_1)
			{
				Set_Stop(5);
				Set_State(2, 6);
			}
			break;
		case 6:    /*  P2S6() - ���������: Finish */

			SendMsgToVerificationModuleCode(C_6);
			Set_Stop(2);
			break;
		default:
			break;
	}
}

void P3 (void) /* �������: TestNormCar */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - ���������: Start */

			SendMsgToVirtualPlantCode(C_2);
			SendMsgToVerificationModuleCode(C_5);
			Set_State(3, 1);
			break;
		case 1:    /*  P3S1() - ���������: Idiling */

			
			break;
		default:
			break;
	}
}

void P4 (void) /* �������: TestWrongCar */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - ���������: Start */

			SendMsgToVirtualPlantCode(C_3);
			SendMsgToVerificationModuleCode(C_5);
			Set_State(4, 1);
			break;
		case 1:    /*  P4S1() - ���������: Idiling */

			
			break;
		default:
			break;
	}
}

void P5 (void) /* �������: TestTwoCars */
{
	switch (Check_State(5)) {

		case 0:    /*  P5S0() - ���������: Start */

			SendMsgToVirtualPlantCode(C_4);
			SendMsgToVerificationModuleCode(C_5);
			Set_State(5, 1);
			break;
		case 1:    /*  P5S1() - ���������: Idiling */

			
			break;
		default:
			break;
	}
}
