# SSD1603
STM32 HAL driver for for I2C OLED SSD1603 display with U8glib

This is a driver for I2C OLED display -- SSD1603.

# About the driver

It is a hardware abstraction layer for I2C OLED SSD1603 display.
It is suitable for u8glib library and it is using STM32 HAL 
calling HAL_I2C_Mem_Write() for efficient bufferless I2C 
transmission. 

# Example

There is also an example available at [SSD1603-example repository](https://github.com/wdomski/SSD1603-example). 
The example project was prepared for STM32F1 MCU in SW4STM32.

# Final remarks

You can visit [my blog](http://blog.domski.pl) to read more about the SSD1603 display or my other projects.

