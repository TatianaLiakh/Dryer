/* MAIN FILE OF THE PROJECT */
#include "VMext.h" /* Common files for all generated c-files */
#include "VMproc.h"  /* Process-functions desription */
#include "VMgvar.h"  /* Project variables images */
#include "VMio.h"    /* Scan-input/output functions */
void Control_Loop(void);  /* for r_main.h */
#include "r_main.h"  /* Codes of the main-function that calls Control_Loop */

void Control_Loop (void)    /* ����������� �������� */
{
	Input();
	P0();  /* Process INIT */
	P1();  /* Process READ_ADC */
	P2();  /* Process Info */
	P3();  /* Process ReceiveSCMOutputMsg */
	P4();  /* Process XValueRestrictionsInvariant */
	P5();  /* Process UValueRestrictionsInvariant */
	P6();  /* Process VoltageDerivativeRestrictionsInvariant */
	P7();  /* Process XLevelTendsToDesired */
	Output();
	Prepare_PSW((INT16S)(PROCESS_N1), (INT16S)PROCESS_Nn);
}