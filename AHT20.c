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


/*  ----------------* Includes *-----------------  */
#include "AHT20.h"


/*  ----------------* Variables *-----------------  */
	uint8_t  DATA_State;
	uint8_t  DATA_CRCreg;
	uint32_t DATA_Temp;
	uint32_t DATA_Humi;
	I2C_HandleTypeDef *_aht20_ui2c;


/*  ----------------* Functions *-----------------  */
void AHT20_Init(I2C_HandleTypeDef *hi2c){
	_aht20_ui2c = hi2c;
}

void AHT20_SoftReset(void){
	uint8_t cmd = AHT20_SOFT_RESET;
	HAL_I2C_Master_Transmit(_aht20_ui2c, AHT20_ADDRESS << 1, &cmd, 1, AHT20_TIMEOUT);
}


void AHT20_Measure(void)
{
	HAL_Delay(50);
	uint8_t ahtTData[3];
	uint8_t ahtRData[7];
	ahtTData[0]=0xAC;
	ahtTData[1]=0x33;
	ahtTData[2]=0x00;

	HAL_I2C_Master_Transmit(_aht20_ui2c, AHT20_ADDRESS<<1, ahtTData, 3, AHT20_TIMEOUT);
	HAL_Delay(100);
    while(1){
    	HAL_I2C_Master_Receive(_aht20_ui2c, AHT20_ADDRESS<<1, ahtRData, 7, AHT20_TIMEOUT);
    	DATA_State=ahtRData[0];
    	if((DATA_State&(1<<7))==0)
    		{
    	    DATA_Humi=ahtRData[1];
    	    DATA_Humi=(DATA_Humi<<8)|ahtRData[2];
    	    DATA_Humi=(DATA_Humi<<4)|(ahtRData[3]>>4);
    	    DATA_Temp=ahtRData[3]&0x0F;
    	    DATA_Temp=(DATA_Temp<<8)|ahtRData[4];
    	    DATA_Temp=(DATA_Temp<<8)|ahtRData[5];
    	    DATA_CRCreg= ahtRData[6];
    		break;
    		}
    	else HAL_Delay(10);
    }
}


double AHT20_Temp(void)
{
	double TEMP_CALC;
	TEMP_CALC= (((DATA_Temp/1024.0)/1024.0) * 200.0) -50.0;
	return TEMP_CALC;
}

double AHT20_Humid(void)
{
	double HUMID_CALC;
	HUMID_CALC = ((DATA_Humi/1024.0)/1024.0)*100;
	return HUMID_CALC;
}


//__________________________________________________________________________________________

/*  END OF CODE ----(Thanks for your Supports)---- AMIR SHARIF  */



