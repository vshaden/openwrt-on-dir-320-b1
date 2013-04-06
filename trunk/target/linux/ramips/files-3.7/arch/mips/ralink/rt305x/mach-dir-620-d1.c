/*
 *  D-Link DIR-620 D1
 *
 *  Copyright (C) 2012 Mikko Hissa <mikko.hissa@uta.fi>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/spi/spi.h>
#include <linux/spi/flash.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/mtd/physmap.h>

#include <asm/mach-ralink/machine.h>
#include <asm/mach-ralink/dev-gpio-buttons.h>
#include <asm/mach-ralink/dev-gpio-leds.h>
#include <asm/mach-ralink/rt305x.h>
#include <asm/mach-ralink/rt305x_regs.h>

#include "devices.h"

#define DIR_620_D1_GPIO_LED_STATUS_GREEN	9
#define DIR_620_D1_GPIO_LED_STATUS_AMBER	17

#define DIR_620_D1_GPIO_BUTTON_RESET_WPS	7

#define DIR_620_D1_KEYS_POLL_INTERVAL	20
#define DIR_620_D1_KEYS_DEBOUNCE_INTERVAL (3 * DIR_620_D1_KEYS_POLL_INTERVAL)

static struct gpio_led dir_620_d1_leds_gpio[] __initdata = {
	{
		.name		= "d-link:green:status",
		.gpio		= DIR_620_D1_GPIO_LED_STATUS_GREEN,
	}, {
		.name		= "d-link:amber:status",
		.gpio		= DIR_620_D1_GPIO_LED_STATUS_AMBER,
		.active_low	= 1,
	}
};

static struct gpio_keys_button dir_620_d1_gpio_buttons[] __initdata = {
	{
		.desc		= "reset",
		.type		= EV_KEY,
		.code		= KEY_RESTART,
		.debounce_interval = DIR_620_D1_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= DIR_620_D1_GPIO_BUTTON_RESET_WPS,
		.active_low	= 1,
	}
};

const struct flash_platform_data dir620d1_flash = {
	.type		= "mx25l6405d",
};

struct spi_board_info dir620d1_spi_slave_info[] __initdata = {
	{
		.modalias	= "m25p80",
		.platform_data	= &dir620d1_flash,
		.irq		= -1,
		.max_speed_hz	= 10000000,
		.bus_num	= 0,
		.chip_select	= 0,
	},
};

static void __init dir620d1_init(void)
{
	rt305x_gpio_init(RT305X_GPIO_MODE_GPIO << RT305X_GPIO_MODE_UART0_SHIFT);
	rt305x_register_spi(dir620d1_spi_slave_info,
			    ARRAY_SIZE(dir620d1_spi_slave_info));
	rt305x_esw_data.vlan_config = RT305X_ESW_VLAN_CONFIG_LLLLW;
	rt305x_register_ethernet();
	ramips_register_gpio_leds(-1, ARRAY_SIZE(dir_620_d1_leds_gpio),
				  dir_620_d1_leds_gpio);
	ramips_register_gpio_buttons(-1, DIR_620_D1_KEYS_POLL_INTERVAL,
				     ARRAY_SIZE(dir_620_d1_gpio_buttons),
				     dir_620_d1_gpio_buttons);
	rt305x_register_wifi();
	rt305x_register_wdt();
	rt305x_register_usb();
}

MIPS_MACHINE(RAMIPS_MACH_DIR_620_D1, "DIR-620-D1", "D-Link DIR-620 D1",
	     dir620d1_init);
