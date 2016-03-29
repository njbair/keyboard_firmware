/**
 * Init actions
 *
 * This function is run at the end of matrix_init(), as defined in matrix.c. So
 * whatever you put here will be triggered on keyboard boot.
 */
void user_init_actions(void)
{
    void layer_on(uint8_t layer);

    layer_on(L_FN_SPACEFN);
    layer_on(L_FN_PRIMARY);
}
