#include "lfkpad.h"
#include "issi.h"
#include "lighting.h"
#include "action_layer.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP( /* Base */
  KC_ESC,   KC_TAB,  KC_PEQL, MO(1), \
  KC_LNUM,  KC_PSLS, KC_PAST, KC_PMNS, \
  KC_P7,    KC_P8,   KC_P9,   KC_PPLS, \
  KC_P4,    KC_P5,   KC_P6, \
  KC_P1,    KC_P2,   KC_P3,   KC_PENT, \
  KC_P0,    KC_PDOT),

[1] = KEYMAP( /* RGB */
  RGB_SAI,  RGB_VAI,  RGB_HUI,  KC_TRNS, \
  RGB_SAD,  RGB_VAD,  RGB_HUD,  KC_TRNS, \
  RGB_M_X,  RGB_M_G,  RGB_MOD,  RGB_RMOD, \
  RGB_M_SW, RGB_M_SN, RGB_M_K, \
  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_TOG, \
  KC_NO,    KC_NO),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {
    // This keymap only has a single base layer, so reset the default if needed
    if(eeconfig_read_default_layer() > 1){
        eeconfig_update_default_layer(1);
        default_layer_set(1);
    }
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
