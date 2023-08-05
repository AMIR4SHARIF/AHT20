//__________________________________________________________________________________________

/*
 *               @ AHT20 Temperature & Humidity sensor @
 *
 *   @Author: Written By AMIR SHARIF
 *
 *   @Copyright (C) AMIR SHARIF , 2022 Winter
 *
 *
 *   This program is free software that all student and users can use it
 *   and develop their programs, the program is developed for STM32 micros
 *   and based on HAL functions, tested on STM32F1xx series.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY;
 *
 *   Telegram contact: @amir4sharif
 */

//__________________________________________________________________________________________

/* ----------------* HOW To USE *----------------- */
/*
 *      1: before "while" loop Initialize Sensor using AHT20_Init(*hi2c)
 *
 *      2: use AHT20_Measure() function to sensor start measuring and transmit and receive data
 *
 *      3: after measuring use AHT20_Temp() or AHT20_Humid() to get Temperature & Humidity
 *         these functions will return a float value
 *         for Temperature it returns a number between -50 to 90 C (Celsius)
 *         for Humidity it returns a number between 0 to 100 %  (Percent)
 *
 *      4': you can use AHT20_SoftReset() to reset sensor but it's NOT necessary
 *          we recommend that use this function where happens a bug for measuring
 *
 *      **: every time you want to know temperature changes you must use AHT20_Measure() again
 *          and then use AHT20_Temp() or AHT20_Humid() again and get new values
 *
 *      **: after reseting sensor you must Initialize Sensor again (using AHT20_Init(*hi2c))
 *
 */
//__________________________________________________________________________________________

/* ----------------* Example *----------------- */
/*
 *          float T,H;
 *          int main(){
 *              sys_init();
 *              AHT20_Init(&hi2c1);
 *               while(1){
 *                  AHT20_Measure();
 *                  T=AHT20_Temp();
 *                  H=AHT20_Humid();
 *               }
 *          }
 */
//__________________________________________________________________________________________



#ifndef AHT20_H
#define AHT20_H 24


/* ----------------* C++ detection *----------------- */

#ifdef __cplusplus
extern "C"{
#endif


/*  ----------------* Includes *-----------------  */

#include "main.h"


/*  ----------------* Defines *-----------------  */

#define AHT20_ADDRESS           0x38
#define AHT20_SOFT_RESET		0xBA
#define AHT20_TIMEOUT			1000
extern I2C_HandleTypeDef *_aht20_ui2c;


/*  ----------------* Function Prototypes *-----------------  */

void   AHT20_Init(I2C_HandleTypeDef *hi2c);    // Initializes sensor address
void   AHT20_SoftReset(void);                  // Resets sensor and measurement
void   AHT20_Measure(void);                    // Measures Temp&humid and receives data
double AHT20_Temp(void);                       // Extract temperature from data and return value (Celsius)
double AHT20_Humid(void);                      // Extract Humidity from data and return value (Percent)
#endif


//__________________________________________________________________________________________

/*  END OF CODE ----(Thanks for your Supports)---- AMIR SHARIF  */


