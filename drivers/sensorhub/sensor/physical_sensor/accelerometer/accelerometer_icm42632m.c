/*
 *  Copyright (C) 2020, Samsung Electronics Co. Ltd. All Rights Reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 */

#include "../../accelerometer.h"
#include "../../../sensormanager/shub_sensor_manager.h"
#include "../../../sensormanager/shub_sensor_type.h"
#include "../../../sensormanager/shub_sensor.h"
#include "../../../utility/shub_utility.h"

#include <linux/device.h>
#include <linux/of_gpio.h>

#define ICM42632M_NAME		"ICM42632M"
static void parse_dt_accelerometer_icm42632m(struct device *dev)
{
	struct accelerometer_data *data = get_sensor(SENSOR_TYPE_ACCELEROMETER)->data;
	struct device_node *np = dev->of_node;

	if (of_property_read_u32(np, "acc-icm42632m-position", &data->position))
		data->position = 0;
	shub_infof("position[%d]", data->position);
}

struct accelerometer_chipset_funcs accel_icm42632m_ops = {
	.parse_dt = parse_dt_accelerometer_icm42632m,
};

struct accelerometer_chipset_funcs *get_accelometer_icm42632m_function_pointer(char *name)
{
	if (strcmp(name, ICM42632M_NAME) != 0)
		return NULL;

	return &accel_icm42632m_ops;
}