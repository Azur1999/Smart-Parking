/*
 * ultrasonic_sensor_3.c
 *
 *  Created on: Jun 2, 2023
 *      Author: Korisnik
 */

#include "ultrasonic_sensor_3.h"

extern TIM_HandleTypeDef htim1;


uint16_t Distance_3  = 0;  // cm

void uss_init3()
{
	HAL_TIM_Base_Start(&htim1);
	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_RESET);
}
void uss_dist3()
{
	uint32_t pMillis;
	uint32_t Value1 = 0;
	uint32_t Value2 = 0;

	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_SET);  // pull the TRIG pin HIGH
    __HAL_TIM_SET_COUNTER(&htim1, 0);
    while (__HAL_TIM_GET_COUNTER (&htim1) < 10);  // wait for 10 us
    HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_RESET);  // pull the TRIG pin low

    pMillis = HAL_GetTick(); // used this to avoid infinite while loop  (for timeout)
    // wait for the echo pin to go high
    while (!(HAL_GPIO_ReadPin (ECHO_PORT_3, ECHO_PIN_3)) && pMillis + 10 >  HAL_GetTick());
    Value1 = __HAL_TIM_GET_COUNTER (&htim1);

    pMillis = HAL_GetTick(); // used this to avoid infinite while loop (for timeout)
    // wait for the echo pin to go low
    while ((HAL_GPIO_ReadPin (ECHO_PORT_3, ECHO_PIN_3)) && pMillis + 50 > HAL_GetTick());
    Value2 = __HAL_TIM_GET_COUNTER (&htim1);

    Distance_3 = (Value2-Value1)* 0.034/2;
    HAL_Delay(50);



}

