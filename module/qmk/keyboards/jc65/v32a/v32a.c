/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "v32a.h"
#ifdef BACKLIGHT_ENABLE
#include "backlight.h"
#endif
#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

#include <avr/pgmspace.h>

#include "action_layer.h"
#include "i2c.h"
#include "quantum.h"

extern rgblight_config_t rgblight_config;

void rgblight_set(void) {
    if (!rgblight_config.enable) {
        for (uint8_t i = 0; i < RGBLED_NUM; i++) {
            led[i].r = 0;
            led[i].g = 0;
            led[i].b = 0;
        }
    }

    i2c_init();
    i2c_send(0xb0, (uint8_t*)led, 3 * RGBLED_NUM);
}

__attribute__ ((weak))
void matrix_scan_user(void) {
    rgblight_task();
}

void backlight_init_ports(void) {
	DDRD |= (1<<0 | 1<<1 | 1<<4 | 1<<6);
	PORTD &= ~(1<<0 | 1<<1 | 1<<4 | 1<<6);
}

void backlight_set(uint8_t level) {
	if (level == 0) {
		// Turn out the lights
		PORTD &= ~(1<<0 | 1<<1 | 1<<4 | 1<<6);
	} else {
		// Turn on the lights
		PORTD |= (1<<0 | 1<<1 | 1<<4 | 1<<6);
	}
}