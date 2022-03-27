/*
 * Copyright (c) 2021 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef ZEPHYR_DRIVERS_SENSOR_TRACKBALL_PIM447_H_
#define ZEPHYR_DRIVERS_SENSOR_TRACKBALL_PIM447_H_

#include <drivers/i2c.h>
#include <drivers/gpio.h>
#include <drivers/sensor.h>
#include <logging/log.h>

#define LOG_LEVEL CONFIG_SENSOR_LOG_LEVEL

#define TRACKBALL_PIM447_REG_LEFT   0x04
#define TRACKBALL_PIM447_REG_RIGHT  0x05
#define TRACKBALL_PIM447_REG_UP     0x06
#define TRACKBALL_PIM447_REG_DOWN   0x07
#define TRACKBALL_PIM447_REG_SWITCH 0x08

#define TRACKBALL_PIM447_REG_MIN    TRACKBALL_PIM447_REG_LEFT
#define TRACKBALL_PIM447_REG_MAX    TRACKBALL_PIM447_REG_SWITCH

struct trackball_pim447_data {
    const struct device *i2c_dev;
    int32_t dx;
    int32_t dy;
    int32_t dz;
#if CONFIG_ZMK_TRACKBALL_PIM447_INTERRUPT
    const struct device *gpio;
    struct gpio_callback gpio_cb;
#endif /* CONFIG_ZMK_TRACKBALL_PIM447_INTERRUPT */
};

#if CONFIG_ZMK_TRACKBALL_PIM447_INTERRUPT
int trackball_pim447_init_interrupt(struct trackball_pim447_data *drv_data);
#endif /* CONFIG_ZMK_TRACKBALL_PIM447_INTERRUPT */

#endif /* ZEPHYR_DRIVERS_SENSOR_TRACKBALL_PIM447_H_ */
