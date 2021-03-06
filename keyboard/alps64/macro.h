enum macro_id {
    M_SIGNATURE,
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt __attribute__ ((unused)))
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
                    T(N),T(J),T(B),T(A),T(I),T(R), T(SPACE),
                    T(O),T(N), T(SPACE),
                    T(M),T(Y), T(SPACE),
                    D(LSHIFT),T(T),T(M),T(K),U(LSHIFT), T(SPACE),
                    D(LSHIFT),T(A),U(LSHIFT),T(L),T(P),T(S),T(6),T(4), T(SPACE),
                    T(K),T(E),T(Y),T(B),T(O),T(A),T(R),T(D),
                    T(ENTER),
                    END
                ) :
                MACRO_NONE );
    }
    return MACRO_NONE;
};
