enum macro_id {
    M_SIGNATURE,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case M_SIGNATURE:
            return (record->event.pressed ?
                MACRO(
                    I(32),I(0),T(ENTER),W(0),T(ENTER),W(128),I(32),T(MINS),T(SPACE),T(N),T(J),T(B),T(A),T(I),T(R),I(0),T(ENTER),W(128),I(32),END
                ) :
                MACRO_NONE );
    }
    return MACRO_NONE;
};

