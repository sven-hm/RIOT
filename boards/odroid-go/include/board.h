/*
 * Copyright (C) 2018 Gunar Schorcht
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_esp32_esp-wrover-kit
 * @brief       Board specific definitions for Espressif ESP-WROVER-KIT V3
 * @{
 *
 * The Espressif ESP-WROVER-KIT is a development board that uses the
 * ESP32-WROVER module which includes a built-in 4 MByte SPI RAM. Most
 * important features of the board are
 *
 * - Micro-SD card interface
 * - OV7670 camera interface
 * - 3.2" SPI LCD panel
 * - RGB LED
 *
 * Furthermore, many GPIOs are broken out for extension. The USB bridge
 * based on FDI FT2232HL provides a JTAG interface for debugging through
 * the USB interface.
 *
 * When the camera module is connected, add
 * ```
 * USEMODULE += esp32_wrover_kit_camera
 * ```
 * to the makefile of the application to use the according default board
 * configuration.
 *
 * For detailed information about the configuration of ESP32 boards, see
 * section \ref esp32_comm_periph "Common Peripherals".
 *
 * @note
 * Most definitions can be overridden by an \ref esp32_app_spec_conf
 * "application-specific board configuration".
 *
 * @file
 * @author      Gunar Schorcht <gunar@schorcht.net>
 */

#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @name    LED (on-board) configuration
 * @{
 */

#define LED0_PIN        GPIO2
#define LED0_ACTIVE     (1)
/** @} */

/**
 * @name    Button configuration
 * @{
 */

#define BUTTON_UPDOWN       GPIO35
#define BUTTON_LEFTRIGHT    GPIO34
#define BUTTON_A            GPIO32
#define BUTTON_B            GPIO33
#define BUTTON_MENU         GPIO13
#define BUTTON_VOLUME       GPIO0
#define BUTTON_SELECT       GPIO27
#define BUTTON_START        GPIO39
/** @} */


/**
 * @name   SD-Card interface configuration
 *
 * @{
 */

#define LCD_SPI_PARAM_SPI       SPI_DEV(0)
#define LCD_SPI_PARAM_CLK       SPI0_SCK
#define LCD_SPI_PARAM_MOSI      SPI0_MOSI
#define LCD_SPI_PARAM_MISO      SPI0_MISO
#define LCD_SPI_PARAM_CS        SPI0_CS0
#define LCD_SPI_PARAM_POWER     GPIO_UNDEF
#define LCD_SPI_PARAM_BACKLIGHT GPIO14
/** @} */

/**
 * @name   SD-Card interface configuration
 *
 * @{
 */
#define SDCARD_SPI_PARAM_SPI    SPI_DEV(0)
#define SDCARD_SPI_PARAM_CLK    SPI0_SCK
#define SDCARD_SPI_PARAM_MOSI   SPI0_MOSI
#define SDCARD_SPI_PARAM_MISO   SPI0_MISO
#define SDCARD_SPI_PARAM_CS     SPI0_CS1
#define SDCARD_SPI_PARAM_POWER  GPIO_UNDEF
/** @} */

#ifdef __cplusplus
} /* end extern "C" */
#endif

/* include common board definitions as last step */
#include "board_common.h"

#endif /* BOARD_H */
/** @} */
