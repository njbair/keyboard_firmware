#include "ps2.h"

enum function_id {
    LED_DANCE,
};

enum function_opt {
    OPT_NONE,
};

void keymap_call_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case LED_DANCE:
            if (record->event.pressed) {
                uint8_t ps2_led = 0;
                ps2_led |= (1<<PS2_LED_SCROLL_LOCK);
                ps2_led |= (1<<PS2_LED_NUM_LOCK);
                ps2_led |= (1<<PS2_LED_CAPS_LOCK);
                ps2_host_set_led(ps2_led);
            }
            break;
    }
};
