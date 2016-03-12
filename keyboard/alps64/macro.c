enum macro_id {
    SIGNATURE,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case SIGNATURE:
            return (record->event.pressed ?
                MACRO( I(0), T(ENTER), T(ENTER), T(MINUS), T(SPACE), T(N), T(J), T(B), T(A), T(I), T(R), END ) :
                MACRO_NONE );
    }
    return MACRO_NONE;
};
