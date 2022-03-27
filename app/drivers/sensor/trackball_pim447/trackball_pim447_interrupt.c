#define DT_DRV_COMPAT pimoroni_trackball_pim447

#include "trackball_pim447.h"

extern struct trackball_pim447_data trackball_pim447_data;

LOG_MODULE_DECLARE(trackball_pim447, LOG_LEVEL);

static void trackball_pim447_gpio_callback(const struct device *dev,
				   struct gpio_callback *cb, uint32_t pins)
{
	struct trackball_pim447_data *drv_data =
		CONTAINER_OF(cb, struct trackball_pim447_data, gpio_cb);

	// TODO
	/*trackball_pim447_handle_cb(drv_data);*/
}

int trackball_pim447_init_interrupt(struct trackball_pim447_data *drv_data)
{
	const unsigned int gpio_pin = DT_INST_GPIO_PIN(0, int_gpios);
	gpio_pin_configure(drv_data->gpio, gpio_pin,
			GPIO_INPUT | DT_INST_GPIO_FLAGS(0, int_gpios));

	gpio_init_callback(&drv_data->gpio_cb,
			   trackball_pim447_gpio_callback,
			   BIT(gpio_pin));

	if (gpio_add_callback(drv_data->gpio, &drv_data->gpio_cb) < 0) {
		LOG_DBG("Failed to set gpio callback!");
		return -EIO;
	}

	return 0;
}
