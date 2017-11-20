/**
 * Author Wojciech Domski <Wojciech.Domski@gmail.com>
 * www: www.Domski.pl
 */

#ifndef U8G_COM_ARM_STM32_SSD_I2C_HEADER
#define U8G_COM_ARM_STM32_SSD_I2C_HEADER

#include "u8g.h"

#define SSD1306_I2C_ADDRESS 0x78

uint8_t u8g_com_arm_stm32_ssd_i2c_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);

#endif
