/*
 * hw_api.c
 *
 *  Created on: Mar 4, 2020
 *      Author: Ray
 */

#include "hw_api.h"
#include "main.h"
extern SPI_HandleTypeDef hspi1;

extern void MX_SPI1_Init();
void HAL_SPI_Enable(void)
{
	HAL_GPIO_WritePin(EVE_CS_GPIO_Port, EVE_CS_Pin, 0);
}

void HAL_SPI_Disable(void)
{
	HAL_GPIO_WritePin(EVE_CS_GPIO_Port, EVE_CS_Pin, 1);
}

volatile int LastResult = 0;
void HAL_SPI_WriteBuffer(uint8_t *Buffer, uint32_t Length)
{
	HAL_SPI_Enable();
	volatile int result = HAL_SPI_Transmit(&hspi1, Buffer, Length, 1000);
	HAL_SPI_Disable();
}

void HAL_SPI_ReadBuffer(uint8_t *Buffer, uint32_t Length)
{
	//EVE requires one dummy read/write before actual data can be read 
	Buffer[0] = 0;
	volatile int result = HAL_SPI_Transmit(&hspi1, Buffer, 1, 1000);
	HAL_SPI_Receive(&hspi1, Buffer, Length,1000);
}

uint8_t HAL_SPI_Write(uint8_t data)
{
	volatile int result = HAL_SPI_Transmit(&hspi1, &data, 1, 1000);
	return 0;
}

void HAL_Eve_Reset_HW(void)
{
	  HAL_GPIO_WritePin(EVE_PD_GPIO_Port, EVE_PD_Pin, 0);
	  HAL_GPIO_WritePin(EVE_CS_GPIO_Port, EVE_CS_Pin, 0);
	  HAL_Delay(50); 
	  HAL_GPIO_WritePin(EVE_PD_GPIO_Port, EVE_PD_Pin, 1);
	  HAL_GPIO_WritePin(EVE_CS_GPIO_Port, EVE_CS_Pin, 1);
	  HAL_Delay(100);
}


