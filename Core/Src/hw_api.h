#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>              
#include <stdbool.h>            

void HAL_SPI_Enable(void);
void HAL_SPI_Disable(void);
uint8_t HAL_SPI_Write(uint8_t data);
uint8_t HAL_SPI_WriteByte(uint8_t data);
void HAL_SPI_WriteBuffer(uint8_t *Buffer, uint32_t Length);
void HAL_SPI_ReadBuffer(uint8_t *Buffer, uint32_t Length);
void HAL_Delay(uint32_t milliSeconds);
void HAL_Eve_Reset_HW(void);
void HAL_Close(void);

#ifdef __cplusplus
}
#endif

