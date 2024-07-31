#ifndef INC_STEP_MOTOR_H_
#define INC_STEP_MOTOR_H_

#include "main.h"

#define IN1_PIN GPIO_PIN_15
#define IN1_PORT GPIOB
#define IN2_PIN GPIO_PIN_14
#define IN2_PORT GPIOB
#define IN3_PIN GPIO_PIN_13
#define IN3_PORT GPIOB
#define IN4_PIN GPIO_PIN_12
#define IN4_PORT GPIOB


void microDelay (uint16_t delay);
void stepCCW (int steps, uint16_t delay);
void stepCW (int steps, uint16_t delay);

void open_gate();
void close_gate();
#endif /* INC_STEP_MOTOR_H_ */
