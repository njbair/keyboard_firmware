/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#include <avr/io.h>
#include "stdint.h"
#include "led.h"
#include "print.h"


int pwm_level;


void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output high
        DDRB  |= (1<<6);
        PORTB |= (1<<6);
    } else {
        // output low
        DDRB  &= ~(1<<6);
        PORTB &= ~(1<<6);
    }

    #ifndef BACKLIGHT_ENABLE
        if (usb_led & (1<<USB_LED_NUM_LOCK)) {
            // output high
            DDRC |= (1<<6);
            PORTC |= (1<<6);
        } else {
            // output low
            DDRC &= ~(1<<6);
            PORTC &= ~(1<<6);
        }
    #endif
}

#ifdef BACKLIGHT_ENABLE
    void init_backlight_pin(void)
    {
        DDRC |= (1<<6);
        TC4H = 0x03;
        OCR3C = 0xFF;
        TCCR3A = 0b10000010;
        TCCR3B = 0b00000001;
    }

    void backlight_set(uint8_t level)
    {
        switch (level)
        {
            case 0:
                pwm_level = 0x00;
                break;
            case 1:
                pwm_level = 0x0F;
                break;
            case 2:
                pwm_level = 0x80;
                break;
            case 3:
                pwm_level = 0xFF;
                break;
            default:
                xprintf("Unknown level: %d\n", level);
        }

        TC4H = pwm_level >> 8;
        OCR3A = 0xFF & pwm_level;
    }
#endif
