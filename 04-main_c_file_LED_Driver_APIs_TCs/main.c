/*
 * Embedded_Stystems_Project.c
 *
 * Created: 9/10/2022 1:59:08 AM
 * Author : ADEL
 */ 

#include "APPLICATION/application.h"

En_DIO_Error_t dio_retValue;
En_Timer0_Error_t timer0_retValue;
En_INTx_Error_t intx_retValue;
En_LED_Error_t led_retValue;

St_led_t errorIndicationLED = {
	.port = PORTD_INDEX,
	.pin = PIN7,
	.state = LED_OFF
};
St_led_t test_led = {
	.port = PORTD_INDEX,
	.pin = PIN0,
	.state = LED_ON
};


int main(void)
{	
	LED_init(&errorIndicationLED);
	/*==== Test case #1 correct values ====*/
	test_led.port = PORTD_INDEX;
	test_led.pin = PIN0;
	test_led.state = LED_ON;
	led_retValue = LED_init(&test_led);
	test_LED_functions_return_value(led_retValue);
	trun_led_off(&errorIndicationLED);
	/*==== Test case #2 NULL pointer ====*/
	led_retValue = LED_init(NULL);
	test_LED_functions_return_value(led_retValue);
	trun_led_off(&errorIndicationLED);
	/*==== Test case #3 wrong port index ====*/
	test_led.port = 9;
	led_retValue = LED_init(&test_led);
	test_LED_functions_return_value(led_retValue);
	trun_led_off(&errorIndicationLED);
	/*==== Test case #4 wrong pin index ====*/
	test_led.port = PORTD_INDEX;
	test_led.pin = 10;
	led_retValue = LED_init(&test_led);
	test_LED_functions_return_value(led_retValue);
	trun_led_off(&errorIndicationLED);
	/*==== Test case #5 wrong LED state ====*/
	test_led.pin = PIN0;
	test_led.state = 3;
	led_retValue = LED_init(&test_led);
	test_LED_functions_return_value(led_retValue);
	trun_led_off(&errorIndicationLED);
	//App_init();
    while (1) 
    {
		//App_start();
    }
}

/** Function to test DIO driver functions **/
void test_DIO_functions_return_value(En_DIO_Error_t dio_error){
	if(DIO_OK != dio_error){
		turn_led_on(&errorIndicationLED);
	}
	else{
		/* Nothing */
	}
}

/** Function to test Timer0 driver functions **/
void test_t0_functions_return_value(En_Timer0_Error_t timer0_error){
	if(TIEMR0_OK != timer0_error){
		turn_led_on(&errorIndicationLED);
	}
	else{
		/* Nothing */
	}
}
/** Function to test External Interrupt driver functions **/
void test_INTx_functions_return_value(En_INTx_Error_t intx_error){
	if(INTx_OK != intx_error){
		turn_led_on(&errorIndicationLED);
	}
	else{
		/* Nothing */
	}
}
/** Function to test LED driver functions **/
void test_LED_functions_return_value(En_LED_Error_t led_error){
	if(LED_OK != led_error){
		turn_led_on(&errorIndicationLED);
	}
	else{
		/* Nothing */
	}
}
