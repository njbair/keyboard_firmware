enum macro_id {
    SIGNATURE,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case SIGNATURE:
            return (record->event.pressed ?
                MACRO(
                    I(32),I(0),T(ENTER),W(0),T(ENTER),W(128),I(32),T(MINS),T(SPACE),T(N),T(J),T(B),T(A),T(I),T(R),T(SPACE),T(O),T(N),T(SPACE),T(M),T(Y),T(SPACE),D(LSHIFT),T(T),U(LSHIFT),D(LSHIFT),T(M),U(LSHIFT),D(LSHIFT),T(K),U(LSHIFT),T(MINS),T(P),T(O),T(W),T(E),T(R),T(E),T(D),T(SPACE),D(LSHIFT),T(F),U(LSHIFT),T(I),T(L),T(C),T(O),T(SPACE),D(LSHIFT),T(Z),U(LSHIFT),T(E),T(R),T(O),I(0),T(ENTER),W(128),I(32),END
                ) :
                MACRO_NONE );
    }
    return MACRO_NONE;
};

