enum function_id {
    F_SWITCH_LAYOUT_QWERTY,
    F_SWITCH_LAYOUT_DVORAK,
    F_SWITCH_LAYOUT_COLEMAK,
    F_SWITCH_LAYOUT_GAMER,
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt __attribute__ ((unused))) {
    void layer_on(uint8_t layer);
    void layer_off(uint8_t layer);
    void default_layer_set(uint32_t state);

    switch (id) {
        case F_SWITCH_LAYOUT_QWERTY:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_QWERTY);
                layer_on(L_FN_SPACEFN);
            }
            break;
        case F_SWITCH_LAYOUT_DVORAK:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_DVORAK);
                layer_on(L_FN_SPACEFN);
            }
            break;
        case F_SWITCH_LAYOUT_COLEMAK:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_COLEMAK);
                layer_on(L_FN_SPACEFN);
            }
            break;
        case F_SWITCH_LAYOUT_GAMER:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_QWERTY);
                layer_off(L_FN_SPACEFN);
            }
            break;
    }
};
