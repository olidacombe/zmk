#define DT_DRV_COMPAT pimoroni_trackball_pim447

#include <drivers/gpio.h>
#include "trackball_pim447.h"

extern struct trackball_pim447_data trackball_pim447_data;

LOG_MODULE_DECLARE(trackball_pim447, LOG_LEVEL);

static inline void setup_int(struct trackball_pim447_data *drv_data,
			     bool enable)
{
	unsigned int flags = enable
		? GPIO_INT_EDGE_TO_ACTIVE
		: GPIO_INT_DISABLE;

	gpio_pin_interrupt_configure(drv_data->gpio,
				     DT_INST_GPIO_PIN(0, int_gpios),
				     flags);
}
