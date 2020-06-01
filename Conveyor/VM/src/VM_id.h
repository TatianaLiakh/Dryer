
	#define AlgorithmDelay /* C_0 - AlgorithmDelay */ 10 
	#define RemovingDelay /* C_1 - RemovingDelay */ 10
	#define Error /* C_2 - Error */ 0
	#define Norm /* C_3 - Norm */ 1
	
	
	enum EN0 {
		CA2GUI_PRESENCE_SENSOR_ERROR /* CA2GUI_PRESENCE_SENSOR_ERROR */,
		CA2GUI_COLOR_SENSORS_ERROR /* CA2GUI_COLOR_SENSORS_ERROR */
	
	};

	
	enum EN1 {
		SCM2VM_TEST_PUT_BOXES_ON_CONVEYOR /* SCM2VM_TEST_PUT_BOXES_ON_CONVEYOR */,
		SCM2VM_TEST_BROKEN_PRESENCE_SENSOR /* SCM2VM_TEST_BROKEN_PRESENCE_SENSOR */,
		SCM2VM_TEST_BROKEN_COLOR_SENSORS /* SCM2VM_TEST_BROKEN_COLOR_SENSORS */,
		SCM2VM_TEST_COMPLETED /* SCM2VM_TEST_COMPLETED */,
		SCM2VM_FINISH_VERIFICATION /* SCM2VM_FINISH_VERIFICATION */
	
	};

	
	enum EN2 {
		VM2SCM_START_VERIFICATION /* VM2SCM_START_VERIFICATION */
	
	};

	
	enum EN3 {
		VM2GUI_TEST_PASSED_WRONG_PRESENCE_SENSOR /* VM2GUI_TEST_PASSED_WRONG_PRESENCE_SENSOR */,
		VM2GUI_TEST_PASSED_WRONG_COLOR_SENSORS /* VM2GUI_TEST_PASSED_WRONG_COLOR_SENSORS */,
		VM2GUI_TEST_FAILED_WRONG_PRESENCE_SENSOR /* VM2GUI_TEST_FAILED_WRONG_PRESENCE_SENSOR */,
		VM2GUI_TEST_FAILED_WRONG_COLOR_SENSORS /* VM2GUI_TEST_FAILED_WRONG_COLOR_SENSORS */,
		VM2GUI_TEST_PASSED_GREEN_BOXES_CONTROL /* VM2GUI_TEST_PASSED_GREEN_BOXES_CONTROL */,
		VM2GUI_TEST_FAILED_GREEN_BOXES_CONTROL /* VM2GUI_TEST_FAILED_GREEN_BOXES_CONTROL */,		
		VM2GUI_TEST_PASSED_RED_BOXES_CONTROL /* VM2GUI_TEST_PASSED_RED_BOXES_CONTROL */,
		VM2GUI_TEST_FAILED_RED_BOXES_CONTROL /* VM2GUI_TEST_FAILED_RED_BOXES_CONTROL */,
		VM2GUI_TEST_PASSED_BLUE_BOXES_CONTROL /* VM2GUI_TEST_PASSED_BLUE_BOXES_CONTROL */,
		VM2GUI_TEST_FAILED_BLUE_BOXES_CONTROL /* VM2GUI_TEST_FAILED_BLUE_BOXES_CONTROL */,
		VM2GUI_TEST_PASSED_MAIN_CONVEYOR_CONTROL /* VM2GUI_TEST_PASSED_MAIN_CONVEYOR_CONTROL */,
		VM2GUI_TEST_FAILED_MAIN_CONVEYOR_CONTROL /* VM2GUI_TEST_FAILED_MAIN_CONVEYOR_CONTROL */,
		VM2GUI_START_TEST_RANDOM_BOXES /* VM2GUI_START_TEST_RANDOM_BOXES */,
		VM2GUI_START_TEST_WRONG_PRESENCE_SENSOR /* VM2GUI_START_TEST_WRONG_PRESENCE_SENSOR */,
		VM2GUI_START_TEST_WRONG_COLOR_SENSORS /* VM2GUI_START_TEST_WRONG_COLOR_SENSORS */,
		VM2GUI_END_VERIFICATION /* VM2GUI_END_VERIFICATION */
	
	};