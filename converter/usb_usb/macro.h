enum macro_id {
    M_SIGNATURE,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case M_SIGNATURE:
            return (record->event.pressed ?
                MACRO(
                    I(128),
                    T(ENTER),
                    T(ENTER),
                    I(32),
                    T(MINS), T(SPACE),
                    T(N),T(J),T(B),T(A),T(I),T(R),
                    T(ENTER),
                    END
                ) :
                MACRO_NONE );
    }
    return MACRO_NONE;
};

