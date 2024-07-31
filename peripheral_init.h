/*
 * peripheral_init.h
 *
 *  Created on: 3. jun 2023.
 *      Author: Korisnik
 */

#ifndef INC_PERIPHERAL_INIT_H_
#define INC_PERIPHERAL_INIT_H_
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;

void peripheral_init();



#endif /* INC_PERIPHERAL_INIT_H_ */
