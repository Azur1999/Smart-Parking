/*
 * ultrasonic_sensor_3.h
 *
 *  Created on: Jun 2, 2023
 *      Author: Korisnik
 */

#ifndef INC_ULTRASONIC_SENSOR_3_H_
#define INC_ULTRASONIC_SENSOR_3_H_

#include "main.h"

#define TRIG_PIN_3 GPIO_PIN_11
#define TRIG_PORT_3 GPIOE
#define ECHO_PIN_3 GPIO_PIN_12
#define ECHO_PORT_3 GPIOE


extern uint16_t Distance_3;

void uss_init3();
void uss_dist3();


#endif /* INC_ULTRASONIC_SENSOR_3_H_ */
