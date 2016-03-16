/*
Copyright 2011,2012,2013 Jun Wako <wakojun@gmail.com>

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
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


// 32*8(256) byte array which converts PS/2 code into USB code
extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];


#define KEYMAP( \
              K1F, K27, K2F, K5E, K08, K10, K18, K20, K28, K30, K38, K40, \
              K05, K06, K04, K0C, K03, K0B, K83, K0A, K01, K09, K78, K07, \
    K19, K5F, K0E, K16, K1E, K26, K25, K2E, K36, K3D, K3E, K46, K45, K4E, K55, K66,   K17, E07D,E07A,   K76, K7E, K7C, E04A, \
    K39, K77, K0D, K15, K1D, K24, K2D, K2C, K35, K3C, K43, K44, K4D, K54, K5B, K5D,   E069,E070,E071,   K6C, K75, K7D,       \
    K53, K50, K58, K1C, K1B, K23, K2B, K34, K33, K3B, K42, K4B, K4C, K52, K5A,             E075,        K6B, K73, K74, K79,  \
    E07C,K6F, K12, K1A, K22, K21, K2A, K32, K31, K3A, K41, K49, K4A, K59,             E06B,E06C,E074,   K69, K72, K7A,       \
    K5C, K48, K14,      K11,           K29,           E011,          E014,                 E072,        K70,      K71, E05A  \
) { \
    { KC_NO,     KC_##K01,  KC_NO,     KC_##K03,  KC_##K04,  KC_##K05,  KC_##K06,  KC_##K07  }, \
    { KC_##K08,  KC_##K09,  KC_##K0A,  KC_##K0B,  KC_##K0C,  KC_##K0D,  KC_##K0E,  KC_NO     }, \
    { KC_##K10,  KC_##K11,  KC_##K12,  KC_NO,     KC_##K14,  KC_##K15,  KC_##K16,  KC_##K17  }, \
    { KC_##K18,  KC_##K19,  KC_##K1A,  KC_##K1B,  KC_##K1C,  KC_##K1D,  KC_##K1E,  KC_##K1F  }, \
    { KC_##K20,  KC_##K21,  KC_##K22,  KC_##K23,  KC_##K24,  KC_##K25,  KC_##K26,  KC_##K27  }, \
    { KC_##K28,  KC_##K29,  KC_##K2A,  KC_##K2B,  KC_##K2C,  KC_##K2D,  KC_##K2E,  KC_##K2F  }, \
    { KC_##K30,  KC_##K31,  KC_##K32,  KC_##K33,  KC_##K34,  KC_##K35,  KC_##K36,  KC_NO     }, \
    { KC_##K38,  KC_##K39,  KC_##K3A,  KC_##K3B,  KC_##K3C,  KC_##K3D,  KC_##K3E,  KC_NO     }, \
    { KC_##K40,  KC_##K41,  KC_##K42,  KC_##K43,  KC_##K44,  KC_##K45,  KC_##K46,  KC_NO     }, \
    { KC_##K48,  KC_##K49,  KC_##K4A,  KC_##K4B,  KC_##K4C,  KC_##K4D,  KC_##K4E,  KC_NO     }, \
    { KC_##K50,  KC_NO,     KC_##K52,  KC_##K53,  KC_##K54,  KC_##K55,  KC_NO,     KC_NO     }, \
    { KC_##K58,  KC_##K59,  KC_##K5A,  KC_##K5B,  KC_##K5C,  KC_##K5D,  KC_##K5E,  KC_##K5F  }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_##K66,  KC_NO     }, \
    { KC_NO,     KC_##K69,  KC_NO,     KC_##K6B,  KC_##K6C,  KC_NO,     KC_NO,     KC_##K6F  }, \
    { KC_##K70,  KC_##K71,  KC_##K72,  KC_##K73,  KC_##K74,  KC_##K75,  KC_##K76,  KC_##K77  }, \
    { KC_##K78,  KC_##K79,  KC_##K7A,  KC_NO,     KC_##K7C,  KC_##K7D,  KC_##K7E,  KC_NO     }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_##K83,  KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_##E011, KC_NO,     KC_NO,     KC_##E014, KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_##E04A, KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_##E05A, KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO     }, \
    { KC_NO,     KC_##E069, KC_NO,     KC_##E06B, KC_##E06C, KC_NO,     KC_NO,     KC_NO     }, \
    { KC_##E070, KC_##E071, KC_##E072, KC_NO,     KC_##E074, KC_##E075, KC_NO,     KC_NO     }, \
    { KC_NO,     KC_NO,     KC_##E07A, KC_NO,     KC_##E07C, KC_##E07D, KC_NO,     KC_NO     }, \
}
#endif
