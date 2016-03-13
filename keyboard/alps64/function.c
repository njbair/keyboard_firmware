enum function_id {
    LAYOUT_QWERTY,
    LAYOUT_DVORAK,
    LAYOUT_COLEMAK,
    LAYOUT_GAMER,
};

enum function_opt {
    NONE,
};

void keymap_call_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case LAYOUT_QWERTY:
            if (record->event.pressed) {
                layer_clear();
                default_layer_set_state(0);
                layer_on(31);
            }
            break;
        case LAYOUT_DVORAK:
            if (record->event.pressed) {
                layer_clear();
                default_layer_set_state(1);
                layer_on(31);
            }
            break;
        case LAYOUT_COLEMAK:
            if (record->event.pressed) {
                layer_clear();
                default_layer_set_state(2);
                layer_on(31);
            }
            break;
        case LAYOUT_GAMER:
            if (record->event.pressed) {
                layer_clear();
                default_layer_set_state(3);
            }
            break;
    }
};
