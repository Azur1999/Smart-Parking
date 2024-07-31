

#ifndef INC_ULTRASONIC_SENSOR_1_H_
#define INC_ULTRASONIC_SENSOR_1_H_

#include "main.h"

#define TRIG_PIN_1 GPIO_PIN_7
#define TRIG_PORT_1 GPIOE
#define ECHO_PIN_1 GPIO_PIN_8
#define ECHO_PORT_1 GPIOE

extern uint16_t Distance_1;

void uss_init1();
void uss_dist1();


#endif /* INC_ULTRASONIC_SENSOR_1_H_ */
