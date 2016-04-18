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
#include "backlight.h"

void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output high
        DDRC  |= (1<<6);
        PORTC |= (1<<6);
    } else {
        // output low
        DDRC  &= ~(1<<6);
        PORTC &= ~(1<<6);
    }

    #ifndef BACKLIGHT_ENABLE
        if (usb_led & (1<<USB_LED_NUM_LOCK)) {
            // output high
            DDRB |= (1<<6);
            PORTB |= (1<<6);
        } else {
            // output low
            DDRB &= ~(1<<6);
            PORTB &= ~(1<<6);
        }
    #endif
}

#ifdef BACKLIGHT_ENABLE
    void init_backlight_pin(void) {
        DDRB |= (1<<6);
        ICR1 = 0xFFFF;
        TCCR1A = 0b00100010; // COM1B1 and WGM11, datasheet page 131
        TCCR1B = 0b00011001; // WGM13, WGM12, and CS10, datasheet page 133

        OCR1B = 0x0000;
    }

    void backlight_set(uint8_t level)
    {
        switch (level)
        {
            case 0:
                // Turn off underlighting
                PORTB &= ~(_BV(PORTB7));
                OCR1B = 0x0000;
                break;
            case 1:
                // Turn underlighting back on at low level
                PORTB |= (_BV(PORTB7));
                OCR1B = 0x0FFF;
                break;
            case 2:
                OCR1B = 0x87FF;
                break;
            case 3:
                OCR1B = 0xFFFF;
                break;
            default:
                xprintf("Unknown level: %d\n", level);
        }
    }
#endif
