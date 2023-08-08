/*该库经过移植但由于的LCD触摸部分有问题无法判定该库是否正确
 * 还需要再加测试*/


#ifndef __TOUCH_H__
#define __TOUCH_H__

#include "main.h"
#include <stdbool.h>


#define ILI9341_TOUCH_SPI_PORT hspi2
extern SPI_HandleTypeDef ILI9341_TOUCH_SPI_PORT;

#define ILI9341_TOUCH_IRQ_Pin       TOUCH_IRQ_Pin
#define ILI9341_TOUCH_IRQ_GPIO_Port TOUCH_IRQ_GPIO_Port
#define ILI9341_TOUCH_CS_Pin        TOUCH_CS_Pin
#define ILI9341_TOUCH_CS_GPIO_Port  TOUCH_IRQ_GPIO_Port

// change depending on screen orientation
#define ILI9341_TOUCH_SCALE_X 240
#define ILI9341_TOUCH_SCALE_Y 320

// to calibrate uncomment UART_Printf line in ili9341_touch.c
#define ILI9341_TOUCH_MIN_RAW_X 1500
#define ILI9341_TOUCH_MAX_RAW_X 31000
#define ILI9341_TOUCH_MIN_RAW_Y 3276
#define ILI9341_TOUCH_MAX_RAW_Y 30110

// call before initializing any SPI devices
void ILI9341_TouchUnselect();

bool ILI9341_TouchPressed();
bool ILI9341_TouchGetCoordinates(uint16_t* x, uint16_t* y);

#endif // __ILI9341_TOUCH_H__
