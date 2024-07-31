/*
 * ultrasonic_sensor_2.h
 *
 *  Created on: Jun 2, 2023
 *      Author: Korisnik
 */

#ifndef INC_ULTRASONIC_SENSOR_2_H_
#define INC_ULTRASONIC_SENSOR_2_H_

#include "main.h"

#define TRIG_PIN_2 GPIO_PIN_9
#define TRIG_PORT_2 GPIOE
#define ECHO_PIN_2 GPIO_PIN_10
#define ECHO_PORT_2 GPIOE


extern uint16_t Distance_2;

void uss_init2();
void uss_dist2();


#endif /* INC_ULTRASONIC_SENSOR_2_H_ */
