/**
 * Author Wojciech Domski <Wojciech.Domski@gmail.com>
 * www: www.Domski.pl
 */

#include "u8g_com_arm_stm32.h"

#include	"i2c.h"
#include "stm32f1xx_hal.h"

#define	STM32_HAL_I2C_HANDLER	hi2c1
#define	STM32_HAL_I2C_TIMEOUT	2000

uint8_t control = 0;
void u8g_Delay(uint16_t val) {
	HAL_Delay(val);
}
void u8g_xMicroDelay(uint16_t val) {
	static uint32_t i, j;
	static uint32_t freq;
	freq = HAL_RCC_GetSysClockFreq() / 1000000;

	for (i = 0; i < val;) {
		for (j = 0; j < freq; ++j) {
			++j;
		}
		++i;
	}
}
void u8g_MicroDelay(void) {
	u8g_xMicroDelay(1);
}
void u8g_10MicroDelay(void) {
	u8g_xMicroDelay(10);
}

uint8_t u8g_com_arm_stm32_ssd_i2c_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val,
		void *arg_ptr) {
	switch (msg) {
	case U8G_COM_MSG_STOP:
		break;

	case U8G_COM_MSG_INIT:
		u8g_MicroDelay();
		break;

	case U8G_COM_MSG_ADDRESS:
		if (arg_val == 0) {
			control = 0;
		} else {
			control = 0x40;
		}
		u8g_10MicroDelay();
		break;

	case U8G_COM_MSG_WRITE_BYTE: {
		HAL_I2C_Mem_Write(&STM32_HAL_I2C_HANDLER, SSD1306_I2C_ADDRESS, control,
				1, &arg_val, 1, STM32_HAL_I2C_TIMEOUT);
	}
		break;

	case U8G_COM_MSG_WRITE_SEQ:
	case U8G_COM_MSG_WRITE_SEQ_P: {
		HAL_I2C_Mem_Write(&STM32_HAL_I2C_HANDLER, SSD1306_I2C_ADDRESS, control,
				1, arg_ptr, arg_val, STM32_HAL_I2C_TIMEOUT);
	}

		break;
	}
	return 1;
}
