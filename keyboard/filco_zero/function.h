#include "action_layer.h"
#include "action_util.h"
#include "action.h"
#include "print.h"

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
        /**
         * TMK's built-in keymap switching is limited to a single default layer.
         * These F_SWITCH_LAYOUT_* functions provide more customized keymap
         * switching, including functional overlay layers such as SpaceFn and a
         * special "gamer" (winkeyless) layer.
         */
        case F_SWITCH_LAYOUT_QWERTY:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_QWERTY);
                layer_on(L_FN_SPACEFN);
                layer_off(L_OVERLAY_GAMER);
                clear_keyboard();
                xprintf("Default layer: QWERTY [%d]\n", L_QWERTY);
                xprintf("SpaceFn enabled.\n");
                xprintf("Gaming overrides disabled.\n");
            }
            break;
        case F_SWITCH_LAYOUT_DVORAK:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_DVORAK);
                layer_on(L_FN_SPACEFN);
                layer_off(L_OVERLAY_GAMER);
                clear_keyboard();
                xprintf("Default layer: Dvorak [%d]\n", L_DVORAK);
                xprintf("SpaceFn enabled.\n");
                xprintf("Gaming overrides disabled.\n");
            }
            break;
        case F_SWITCH_LAYOUT_COLEMAK:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_COLEMAK);
                layer_on(L_FN_SPACEFN);
                layer_off(L_OVERLAY_GAMER);
                clear_keyboard();
                xprintf("Default layer: Colemak [%d]\n", L_COLEMAK);
                xprintf("SpaceFn enabled.\n");
                xprintf("Gaming overrides disabled.\n");
            }
            break;
        case F_SWITCH_LAYOUT_GAMER:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_QWERTY);
                layer_off(L_FN_SPACEFN);
                layer_on(L_OVERLAY_GAMER);
                clear_keyboard();
                xprintf("Default layer: QWERTY [%d]\n", L_QWERTY);
                xprintf("SpaceFn disabled.\n");
                xprintf("Gaming overrides enabled.\n");
            }
            break;
        /**
         * Temporarily revert the default layer to 0 (QWERTY) when the trigger
         * key is pressed, then restore the previous default layer upon release.
         *
         * Useful for Dvorak users who want to be able to use Ctrl+C, Ctrl+V,
         * etc. in the standard layout.
         */
        case F_CTRL_QWERTY_FALLBACK:
            if (record->event.pressed) {
                qwerty_fallback_previous_state = default_layer_state;
                default_layer_set(1UL<<L_QWERTY);
                add_weak_mods(MOD_LCTL);
            } else {
                default_layer_set(qwerty_fallback_previous_state);
                del_weak_mods(MOD_LCTL);
                clear_keyboard();
            }
            break;
    }
};
