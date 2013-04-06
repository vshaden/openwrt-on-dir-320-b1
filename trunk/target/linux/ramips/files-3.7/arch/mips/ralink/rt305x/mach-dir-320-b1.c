/*
 *  D-Link DIR-320 B1
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

#define DIR_320_B1_GPIO_LED_STATUS_GREEN 9
#define DIR_320_B1_GPIO_LED_WPS_GREEN	13
#define DIR_320_B1_GPIO_LED_USB_GREEN	14

#define DIR_320_B1_GPIO_BUTTON_RESET	10
#define DIR_320_B1_GPIO_BUTTON_WPS	0

#define DIR_320_B1_KEYS_POLL_INTERVAL	20
#define DIR_320_B1_KEYS_DEBOUNCE_INTERVAL (3 * DIR_320_B1_KEYS_POLL_INTERVAL)

static struct gpio_led dir_320_b1_leds_gpio[] __initdata = {
	{
		.name		= "d-link:green:status",
		.gpio		= DIR_320_B1_GPIO_LED_STATUS_GREEN,
		.active_low	= 1,
	}, {
		.name		= "d-link:green:usb",
		.gpio		= DIR_320_B1_GPIO_LED_USB_GREEN,
		.active_low	= 1,
	}, {
		.name		= "d-link:green:wps",
		.gpio		= DIR_320_B1_GPIO_LED_WPS_GREEN,
		.active_low	= 1,
	}
};

static struct gpio_keys_button dir_320_b1_gpio_buttons[] __initdata = {
	{
		.desc		= "reset",
		.type		= EV_KEY,
		.code		= KEY_RESTART,
		.debounce_interval = DIR_320_B1_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= DIR_320_B1_GPIO_BUTTON_RESET,
		.active_low	= 1,
	}, {
		.desc		= "wps",
		.type		= EV_KEY,
		.code		= KEY_WPS_BUTTON,
		.debounce_interval = DIR_320_B1_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= DIR_320_B1_GPIO_BUTTON_WPS,
		.active_low	= 1,
	}
};

const struct flash_platform_data dir320b1_flash = {
	.type		= "s25fl064k",
};

struct spi_board_info dir320b1_spi_slave_info[] __initdata = {
	{
		.modalias	= "m25p80",
		.platform_data	= &dir320b1_flash,
		.irq		= -1,
		.max_speed_hz	= 10000000,
		.bus_num	= 0,
		.chip_select	= 0,
	},
};

static void __init dir320b1_init(void)
{
	rt305x_gpio_init(RT305X_GPIO_MODE_GPIO << RT305X_GPIO_MODE_UART0_SHIFT);
	rt305x_register_spi(dir320b1_spi_slave_info,
			    ARRAY_SIZE(dir320b1_spi_slave_info));
	rt305x_esw_data.vlan_config = RT305X_ESW_VLAN_CONFIG_LLLLW;
	rt305x_register_ethernet();
	ramips_register_gpio_leds(-1, ARRAY_SIZE(dir_320_b1_leds_gpio),
				  dir_320_b1_leds_gpio);
	ramips_register_gpio_buttons(-1, DIR_320_B1_KEYS_POLL_INTERVAL,
				     ARRAY_SIZE(dir_320_b1_gpio_buttons),
				     dir_320_b1_gpio_buttons);
	rt305x_register_wifi();
	rt305x_register_wdt();
	rt305x_register_usb();
}

MIPS_MACHINE(RAMIPS_MACH_DIR_320_B1, "DIR-320-B1", "D-Link DIR-320 B1",
	     dir320b1_init);
