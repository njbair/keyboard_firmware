#include "action_layer.h"
#include "action_util.h"
#include "debug.h"

enum function_id {
    F_SWITCH_LAYOUT_QWERTY,
    F_SWITCH_LAYOUT_DVORAK,
    F_SWITCH_LAYOUT_COLEMAK,
    F_SWITCH_LAYOUT_GAMER,
    F_CTRL_QWERTY_FALLBACK,
};

uint32_t default_layer_state;
uint32_t qwerty_fallback_previous_state;

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt __attribute__ ((unused))) {
    switch (id) {
        case F_SWITCH_LAYOUT_QWERTY:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_QWERTY);
                layer_on(L_FN_SPACEFN);
                layer_off(L_OVERLAY_GAMER);
            }
            break;
        case F_SWITCH_LAYOUT_DVORAK:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_DVORAK);
                layer_on(L_FN_SPACEFN);
                layer_off(L_OVERLAY_GAMER);
            }
            break;
        case F_SWITCH_LAYOUT_COLEMAK:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_COLEMAK);
                layer_on(L_FN_SPACEFN);
                layer_off(L_OVERLAY_GAMER);
            }
            break;
        case F_SWITCH_LAYOUT_GAMER:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_QWERTY);
                layer_off(L_FN_SPACEFN);
                layer_on(L_OVERLAY_GAMER);
            }
            break;
        case F_CTRL_QWERTY_FALLBACK:
            if (record->event.pressed) {
                qwerty_fallback_previous_state = default_layer_state;
                default_layer_set(1UL<<L_QWERTY);
                add_weak_mods(MOD_LCTL);
            } else {
                default_layer_set(qwerty_fallback_previous_state);
                del_weak_mods(MOD_LCTL);
            }
            break;
    }
};
