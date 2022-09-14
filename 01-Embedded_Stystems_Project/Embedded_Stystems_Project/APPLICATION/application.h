/*
 * application.h
 *
 * Created: 8/29/2022 12:56:03 PM
 *  Author: ADEL
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_


/********************************************************************************************/
/*                                         Includes                                         */
/********************************************************************************************/
#include "../ECUAL/LED/led.h"
#include "../MCAL/Timer0/timer0.h"
#include "../MCAL/Interrupt/interrupts.h"
#include "../MCAL/Interrupt/EXTI.h"

/********************************************************************************************/
/*                                    Macros Declarations                                   */
/********************************************************************************************/
#define  NORMAL_MODE      0
#define  PEDESTRIAN_MODE  1
/********************************************************************************************/
/*                                Macro Functions Declarations                              */
/********************************************************************************************/

/********************************************************************************************/
/*                                  Data Type Declarations                                  */
/********************************************************************************************/

/********************************************************************************************/
/*                             Software Interface Declarations "APIs"                       */
/********************************************************************************************/
void App_init();
void App_start();

void pedestrian_Mode();
void blink_carsYellowLED_for_5sec(uint8_t counterStartValue);
void blink_bothYellowLEDs_for_5sec(uint8_t counterStartValue);

/** Function to test DIO driver functions **/
void test_DIO_functions_return_value(En_DIO_Error_t dio_error);
/** Function to test Timer0 driver functions **/
void test_t0_functions_return_value(En_Timer0_Error_t timer0_error);
/** Function to test External Interrupt driver functions **/
void test_INTx_functions_return_value(En_INTx_Error_t intx_error);
/** Function to test LED driver functions **/
void test_LED_functions_return_value(En_LED_Error_t led_error);


#endif /* APPLICATION_H_ */