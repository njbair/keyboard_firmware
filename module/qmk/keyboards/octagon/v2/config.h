/*
Copyright 2017 MechMerlin <mechmerlin@gmail.com>

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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6050
#define DEVICE_VER      0x0104
#define MANUFACTURER    Duck
#define PRODUCT         Octagon V2
#define DESCRIPTION     Duck Octagon V2

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 17

#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5

/* number of backlight levels */
#define BACKLIGHT_LEVELS 1

/* key combination for magic key command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#define RGBLIGHT_ANIMATIONS
#define RGB_DI_PIN D6
#define RGBLED_NUM 17

#define TAPPING_TERM 200

#endif
