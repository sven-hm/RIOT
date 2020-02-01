/**
 * @ingroup     odroid-go
 * @brief       Peripheral MCU configuration for ODROID-GO
 * @{
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H

#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @name    ADC and DAC channel configuration
 * @{
 */

/**
 * @brief   Declaration of GPIOs that can be used as ADC channels
 *
 * @note As long as the GPIOs listed in ADC_GPIOS are not initialized as ADC
 * channels with the ```adc_init``` function, they can be used for other
 * purposes.
 */
#ifndef ADC_GPIOS
#define ADC_GPIOS   { GPIO4, GPIO12, GPIO15 }
#endif

/**
 * @brief   Declaration of GPIOs that can be used as DAC channels
 *
 * ESP-WROVER-KIT has no GPIOs left that might be used as DAC channels.
 */
#ifndef DAC_GPIOS
#define DAC_GPIOS   { }
#endif
/** @} */

/**
 * @name    SPI configuration
 *
 * @{
 */
#ifndef SPI0_CTRL
#define SPI0_CTRL   VSPI
#endif

#ifndef SPI0_SCK
#define SPI0_SCK    GPIO18
#endif
#ifndef SPI0_MOSI
#define SPI0_MOSI   GPIO23
#endif
#ifndef SPI0_MISO
#define SPI0_MISO   GPIO19
#endif
#ifndef SPI0_CS0
#define SPI0_CS0    GPIO5
#endif
#ifndef SPI0_CS1
#define SPI0_CS1    GPIO22
#endif
/** @} */

/**
 * @name   UART configuration
 *
 * ESP32 provides 3 UART interfaces at maximum:
 *
 * UART_DEV(0) uses fixed standard configuration.<br>
 * UART_DEV(1) is not available.<br>
 * UART_DEV(2) is not available.<br>
 * @{
 */
#define UART0_TXD   GPIO1  /**< direct I/O pin for UART_DEV(0) TxD, can't be changed */
#define UART0_RXD   GPIO3  /**< direct I/O pin for UART_DEV(0) RxD, can't be changed */
/** @} */


#ifdef __cplusplus
} /* end extern "C" */
#endif

/* include common board definitions as last step */
#include "periph_conf_common.h"

#endif /* PERIPH_CONF_H */
/** @} */
