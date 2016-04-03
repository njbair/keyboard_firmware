#include "action_layer.h"
#include "layer.h"
#include "print.h"
#include "timer.h"
#include "led.h"

bool my_led_status = 0;
uint16_t my_led_timer;

void hook_keyboard_init(void)
{
    layer_on(L_FN_SPACEFN);
    layer_on(L_OVERLAY_CTRL_REMAP);
    layer_on(L_FN_PRIMARY);
}

void hook_matrix_change(keyevent_t event)
{
	// only flash LED for key press events, not key release events.
	if (event.pressed)
	{
		if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))
		{
			led_set(host_keyboard_leds() & (0<<USB_LED_CAPS_LOCK));
		}
		else {
			led_set(host_keyboard_leds() | (1<<USB_LED_CAPS_LOCK));
		}

	    my_led_status = 1;
		my_led_timer = timer_read();
	}
}

void hook_keyboard_loop(void)
{
	if (my_led_status)
	{
	    // check if we've reached 20 milliseconds yet...
	    if (timer_elapsed(my_led_timer) > 20)
	    {
	    	keyboard_set_leds(host_keyboard_leds());

            my_led_status = 0;
	    }
	}
}
