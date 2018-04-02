/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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

#ifndef CONFIG_H
#define CONFIG_H

#define PREVENT_STUCK_MODIFIERS

/* USB Device descriptor parameter */
#define VENDOR_ID       0x1c11
#define PRODUCT_ID      0xb04d
#define DEVICE_VER      673
/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define MANUFACTURER "Input Club"
#define USBSTR_MANUFACTURER    'I', '\x00', 'n', '\x00', 'p', '\x00', 'u', '\x00', 't', '\x00', ' ', '\x00', 'C', '\x00', 'l', '\x00', 'u', '\x00', 'b', '\x00'
#define PRODUCT "K-Type/QMK"
#define USBSTR_PRODUCT         'K', '\x00', '-', '\x00', 'T', '\x00', 'y', '\x00', 'p', '\x00', 'e', '\x00', '/', '\x00', 'Q', '\x00', 'M', '\x00', 'K', '\x00'
/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 10

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
