/*
 * application.c
 *
 * Created: 8/29/2022 12:55:40 PM
 *  Author: ADEL
 */ 

#include "application.h"

volatile uint16_t T0_1millisecDelayCounter = 0;
volatile uint8_t T0_1SecDelayCounter = 0;
uint8_t LightsMode = NORMAL_MODE;

// Timer0 configuration to generate 1msec delay
st_timer0_config_t timer0_1msecDelay = {
	.mode = T0_CTC_MODE,
	.compareModeNonPWM = OC0_nonPWM_DISCONNECTED,
	.clockSource = T0_CLK_DIV_BY_8,
	.preloadValue = 124
};

// External Interrupt on pin INT0 port D pin 2
St_interrupt_INTx_t externalInterrupt0 = {
	.source = INT0_INTERRUPT_EXTERNAL,
	.edge = INTI_RISING_EDGE
};

St_led_t CarsGreenLED = {
	.port = PORTA_INDEX,
	.pin = PIN0,
	.state = LED_OFF
};
St_led_t CarsYellowLED = {
	.port = PORTA_INDEX,
	.pin = PIN1,
	.state = LED_OFF
};
St_led_t CarsRedLED = {
	.port = PORTA_INDEX,
	.pin = PIN2,
	.state = LED_OFF
};
St_led_t pedestrianGreenLED = {
	.port = PORTB_INDEX,
	.pin = PIN0,
	.state = LED_OFF
};
St_led_t pedestrianYellowLED = {
	.port = PORTB_INDEX,
	.pin = PIN1,
	.state = LED_OFF
};
St_led_t pedestrianRedLED = {
	.port = PORTB_INDEX,
	.pin = PIN2,
	.state = LED_ON
};

void App_init(){
	init_external_INTx(&externalInterrupt0);
	timer0_init(&timer0_1msecDelay);
	LED_init(&CarsGreenLED);
	LED_init(&CarsYellowLED);
	LED_init(&CarsRedLED);
	LED_init(&pedestrianGreenLED);
	LED_init(&pedestrianYellowLED);
	LED_init(&pedestrianRedLED);
}

void App_start(){
	if(NORMAL_MODE == LightsMode){
		/*===================   NORMAL MODE   ====================*/
		// Reset the timer delay counter
		T0_1SecDelayCounter = 0;
		// cars green LED ON for 5 seconds
		turn_led_on(&CarsGreenLED);
		while((NORMAL_MODE == LightsMode) && (T0_1SecDelayCounter < 5));
		turn_led_off(&CarsGreenLED);
		// cars yellow LED blink for 5 seconds
		blink_carsYellowLED_for_5sec(5);
		turn_led_off(&CarsYellowLED);
		// cars red LED ON for 5 seconds
		turn_led_on(&CarsRedLED);
		while(T0_1SecDelayCounter >= 10 && T0_1SecDelayCounter < 15);
		turn_led_off(&CarsRedLED);
		// cars yellow LED blink for 5 seconds
		blink_carsYellowLED_for_5sec(15);
		turn_led_off(&CarsYellowLED);
	}
	else if(PEDESTRIAN_MODE == LightsMode){
		pedestrian_Mode();
	}
}

void pedestrian_Mode(){
	/*===================   pedestrian MODE   ====================*/
	// Reset the timer delay counter
	T0_1SecDelayCounter = 0;
	if(LED_ON == CarsRedLED.state){
		turn_led_off(&pedestrianRedLED);
	}
	else{
		turn_led_off(&CarsGreenLED);
		// Both yellow LEDs blink for 5 seconds
		blink_bothYellowLEDs_for_5sec(0);
		turn_led_off(&CarsYellowLED);
		turn_led_off(&pedestrianYellowLED);
		turn_led_off(&pedestrianRedLED);
		// Reset the timer delay counter
		T0_1SecDelayCounter = 0;
	}
	// pedestrian green LED and Cars' red LED ON for 5 seconds
	turn_led_on(&pedestrianGreenLED);
	turn_led_on(&CarsRedLED);
	while(T0_1SecDelayCounter < 5);
	turn_led_off(&CarsRedLED);
	// Both yellow LEDs blink for 5 seconds
	blink_bothYellowLEDs_for_5sec(5);
	// Return to the Normal Mode
	turn_led_off(&pedestrianYellowLED);
	turn_led_off(&pedestrianGreenLED);
	turn_led_on(&pedestrianRedLED);
	turn_led_off(&CarsYellowLED);
	turn_led_on(&CarsGreenLED);
	LightsMode = NORMAL_MODE;
}

ISR(TIMER0_COMP){
	T0_1millisecDelayCounter++;
	if (T0_1millisecDelayCounter > 1000)
	{ // This code will be executed every 1000 mSec (1 Second)
		T0_1millisecDelayCounter = 0;
		T0_1SecDelayCounter++;
	}
	else{ /* Nothing */ }
}

ISR(EXT_INT_0){
	if(NORMAL_MODE == LightsMode){
		LightsMode = PEDESTRIAN_MODE;
		T0_1SecDelayCounter = 0;
	}
	else{ /* Nothing */ }
}


void blink_carsYellowLED_for_5sec(uint8_t counterStartValue){
	while(T0_1SecDelayCounter >= counterStartValue && T0_1SecDelayCounter < (counterStartValue + 5)){
		if(T0_1SecDelayCounter == counterStartValue)
		{
			turn_led_on(&CarsYellowLED);
		}
		else if(T0_1SecDelayCounter == (counterStartValue + 1)){
			turn_led_off(&CarsYellowLED);
		}
		else if(T0_1SecDelayCounter == (counterStartValue + 2)){
			turn_led_on(&CarsYellowLED);
		}
		else if(T0_1SecDelayCounter == (counterStartValue + 3)){
			turn_led_off(&CarsYellowLED);
		}
		else if(T0_1SecDelayCounter == (counterStartValue + 4)){
			turn_led_on(&CarsYellowLED);
		}
		else{ /* Nothing */ }
	}
}

void blink_bothYellowLEDs_for_5sec(uint8_t counterStartValue){
	while(T0_1SecDelayCounter >= counterStartValue && T0_1SecDelayCounter < (counterStartValue + 5)){
		if(T0_1SecDelayCounter == counterStartValue)
		{
			turn_led_on(&CarsYellowLED);
			turn_led_on(&pedestrianYellowLED);
		}
		else if(T0_1SecDelayCounter == (counterStartValue + 1)){
			turn_led_off(&CarsYellowLED);
			turn_led_off(&pedestrianYellowLED);
		}
		else if(T0_1SecDelayCounter == (counterStartValue + 2)){
			turn_led_on(&CarsYellowLED);
			turn_led_on(&pedestrianYellowLED);
		}
		else if(T0_1SecDelayCounter == (counterStartValue + 3)){
			turn_led_off(&CarsYellowLED);
			turn_led_off(&pedestrianYellowLED);
		}
		else if(T0_1SecDelayCounter == (counterStartValue + 4)){
			turn_led_on(&CarsYellowLED);
			turn_led_on(&pedestrianYellowLED);
		}
		else{ /* Nothing */ }
	}
}
