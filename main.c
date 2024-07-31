
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "peripheral_init.h"
#include "ultrasonic_sensor_1.h"
#include "ultrasonic_sensor_2.h"
#include "ultrasonic_sensor_3.h"
#include "step_motor.h"
#include "lcd_i2c.h"


#define DISTANCE_FROM_FLOOR 9
#define DISTANCE_FROM_GATE 5
#define MAX_NUMBER_OF_CARS 2


int main(void)
{


  /* Initialize all configured peripherals */

  peripheral_init();



  uss_init1();
  uss_init2();
  uss_init3();

  HD44780_Init(2);
  HD44780_Clear();
  HD44780_SetCursor(0,0);

  HAL_TIM_Base_Start(&htim2);

char num[5];               /* Helper variable for turning numbers into strings using the itoa function */
uint16_t number_of_cars=0; /* Variable to keep track of number of cars in parking lot */
uint16_t state_changed=1;  /* Variable to keep track of changes so that the LCD only clears when something new happens */


// If you want to start it with cars already inside:
/*

  	  uss_dist1();
	  uss_dist2();
	  uss_dist3();

 	      if(Distance_2 < DISTANCE_FROM_FLOOR-2)
number_of_cars=number_of_cars+1;
 		  if(Distance_3 < DISTANCE_FROM_FLOOR-2)
number_of_cars=number_of_cars+1;

*/


/* Infinite loop */
  while (1)
  {


    /* CALCULATE ALL DISTANCES */
	  uss_dist1();
	  uss_dist2();
	  uss_dist3();


/*  FOR VISUAL DEBUGGING
 *
  	  HD44780_SetCursor(0,0);
  	  HAL_Delay(500);
  	  HD44780_PrintStr("G:");
  	  itoa(Distance_1,num,10);
  	  HD44780_PrintStr(num);

  	  itoa(Distance_2,num,10);
  	  HD44780_PrintStr("s1:");
  	  HD44780_PrintStr(num);

  	  itoa(Distance_3,num,10);
  	  HD44780_PrintStr("s2:");
  	  HD44780_PrintStr(num);

  	  HD44780_SetCursor(0,1);
  	  itoa(number_of_cars,snum,10);
  	  HD44780_PrintStr("Cars:");
  	  HD44780_PrintStr(snum);
*/

	     /* If car is there turn off red light and turn on green light
	        if car is not there turn off green light and turn on red light */

 	      /*CHECK SPOT 1*/

 	      if(Distance_2 < DISTANCE_FROM_FLOOR-1)
 		  {
 			  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7 , 0);
 			  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6 , 1);
 		  }
 		  else
 		  {
 			  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6 , 0);
 			  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7 , 1);
 		  }



 		  /*CHECK SPOT 2*/

 		  if(Distance_3 < DISTANCE_FROM_FLOOR-1)
 		  {
 			  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9 , 0);
 			  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8 , 1);
 		  }
 		  else
 		  {
 			  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8 , 0);
 			  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9 , 1);
 		  }

/* Update LCD display with message about how many available spots there are */
 if(state_changed)
 {
		 HD44780_Clear();
		 HD44780_SetCursor(0,0);

 		  if(number_of_cars == MAX_NUMBER_OF_CARS)
 		  {
 		  	  HD44780_PrintStr("Nema slobodnih");
 		  	  HD44780_SetCursor(0,1);
 		  	  HD44780_PrintStr("mjesta!");
          }
 		  else
 		  {

 		  	 itoa((MAX_NUMBER_OF_CARS-number_of_cars),num,10);
 		  	 HD44780_PrintStr(num);
 		  	 HD44780_PrintStr(" mjesta ");
 		  	 HD44780_SetCursor(0,1);
 		  	 HD44780_PrintStr("su slobodna");
 		  }

 state_changed=0;
 }

/* Check if car is outside or inside gate. If inside it is leaving , if outside it is coming in.
   Tell LCD display to update. Open gate, wait 5 seconds, close gate wait 3 seconds.
   If parking is full don't open gate to car coming in. */

             	/*CHECK GATE*/
  		  if(Distance_1 < DISTANCE_FROM_GATE + 10)
  		  {


  			  if(Distance_1 <= DISTANCE_FROM_GATE)
  			  {
  				  if(number_of_cars != 0)
  			      number_of_cars=number_of_cars-1;

  			  }
  			  else
  			  {
  				  if(number_of_cars == MAX_NUMBER_OF_CARS)
  					  continue;

  				  number_of_cars=number_of_cars+1;
  			  }
  			    state_changed=1;
	  			open_gate();
	  			HAL_Delay(5000);
	  			close_gate();
	  			HAL_Delay(3000);

  		  }


  			HAL_Delay(500);

   }
}


/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
