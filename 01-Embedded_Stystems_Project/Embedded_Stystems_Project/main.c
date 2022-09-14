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


int main(void)
{	
	App_init();
    while (1) 
    {
		App_start();
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
